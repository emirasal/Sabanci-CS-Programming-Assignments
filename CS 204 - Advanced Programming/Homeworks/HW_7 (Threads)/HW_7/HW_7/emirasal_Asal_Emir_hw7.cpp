#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include "emirasal_Asal_Emir_hw7_HW7Printqueue.h"
using namespace std;

// Global variables here:
HW7PrintQueue printerQueue;
int max_print_jobs;
int request_id = 1; // Counts the order of print jobs that is send to the printer 
int printed_requests = 0; // Counts the number of printed requests by the printer
mutex m1, m2, m3, m4, m5; // 5 mutex is used (2 for accessing globals & 3 for cout statements)
bool printer_start = false; // This is used so that printer wont start before the first job is sent

// Taken from HW7 pdf Document
#include <random>
#include <time.h>
int random_range(const int & min, const int & max) {
 static mt19937 generator(time(0));
 uniform_int_distribution<int> distribution(min, max);
 return distribution(generator);
}
////

tm * get_time () {
	// Taken from lecture slides week 12
	time_t tt = chrono::system_clock::to_time_t(chrono::system_clock::now());
	struct tm *ptm = new struct tm; 
	localtime_s(ptm, &tt); 
	return ptm;
	////
}

void send_to_printer(int user_num, int min_waiting_time, int max_waiting_time, int min_pages, int max_pages) {
	int wait_time, pages, Queue_size, id; // these variables are used to save locally before unlocking the mutex
	wait_time = random_range(min_waiting_time, max_waiting_time);
	this_thread::sleep_for(chrono::seconds(wait_time)); // We sleep user before first print job.
	while (request_id <= max_print_jobs) {
		// We have if statement since request_id may have been changed by other threads
		m1.lock();
		if (request_id <= max_print_jobs) {
			// Random numbers are created here:
			wait_time = random_range(min_waiting_time, max_waiting_time);
			pages = random_range(min_pages, max_pages);
			printerQueue.enqueue(request_id, pages);
			Queue_size = printerQueue.getCurrentSize();
			id = request_id;
			request_id++;
			m1.unlock();
			// New mutex for the output:
			m2.lock();
			cout << "User " << user_num << " sent new print job with ID " << id << " sent to the printer queue, number of pages: " << pages 
				<< " (print queue size: " << Queue_size << ")  " << put_time(get_time(),"%X") << "\n";
			printer_start = true; // This means that printer can now start printing
			m2.unlock();
			
			this_thread::sleep_for(chrono::seconds(wait_time));
		}
		else {
			m1.unlock();
		}
	}
}

void print () {
	int id, page, Queue_size; // these variables are saved locally before unlocking the mutex 
	while (printed_requests < max_print_jobs) {
		m3.lock();
		if (!printerQueue.isEmpty() && printer_start) {
			printerQueue.dequeue(id, page);
			printed_requests++;
			Queue_size = printerQueue.getCurrentSize();
			m3.unlock();
			// New mutex for the output:
			m4.lock();
			cout << "The printer started to print the job with ID: " << id << ", number of pages: " << page 
				<< " (queue size is: " << Queue_size << ")  " << put_time(get_time(),"%X") << endl;
			m4.unlock();
			this_thread::sleep_for(chrono::seconds(page));

			m5.lock();
			cout << "The printer finished printing the job with ID: " << id << ", number of pages: " << page << "  " << put_time(get_time(),"%X") << endl;
			m5.unlock();
		}
		else {
			m3.unlock();
		}
	}
}

int main () {
	cout << "Please enter the max number of print jobs: ";
	cin >> max_print_jobs;
	
	int min_waiting_time, max_waiting_time;
	cout << "Please enter the min and max values for the waiting time period (in seconds) after creating a print job: " << endl;
	cout << "Min: ";
	cin >> min_waiting_time;
	cout << "Max: ";
	cin >> max_waiting_time;

	int min_pages, max_pages;
	cout << "Please enter the min and max values for the number of pages in a print job: " << endl;
	cout << "Min number of pages: ";
	cin >> min_pages;
	cout << "Max number of pages: ";
	cin >> max_pages;

	cout << "Simulation starts  " << put_time(get_time(),"%X") << endl;
	thread users[3];
	for (int i = 0; i < 3; i++) {
		users[i] = thread(&send_to_printer, i+1, min_waiting_time, max_waiting_time, min_pages, max_pages);
	}
	thread printer = thread(&print);

	for (int i = 0; i < 3; i++) {
		users[i].join();
	}
	printer.join();
	cout << "End of the simulation ends  " << put_time(get_time(),"%X") << endl;
 	return 0;
}