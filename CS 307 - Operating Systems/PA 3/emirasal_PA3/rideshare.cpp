#include <iostream>
#include <vector>
#include <semaphore.h>
#include <pthread.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// Declearing the variables
vector<pthread_t> threads;
int numA, numB; // Number of people for each team
pthread_barrier_t barrier;
sem_t semaphore;
sem_t outputSemaphore;
sem_t semaphoreA, semaphoreB;
int numReadyA = 0, numReadyB = 0;

int CarID = 0;

bool InputCheck(int argc, char *argv[]){
    if (argc == 3) {
        numA = atoi(argv[1]);
        numB = atoi(argv[2]);
        return ((numA % 2 == 0) && (numB % 2 == 0) && ((numA + numB) % 4 == 0));
    }
    return false;
}

void * thread_function(void * arg){
    sem_wait(&semaphore); // General lock acquired.
    char team = *((char*)arg);
    cout << "Thread ID: " << pthread_self() << ", Team: " << team << ", I am looking for a car\n";

    bool Driver = false; // Last person will be the driver

    if (team == 'A') {
        // There are two different cases for car to be ready for this thread
        if (numReadyA >= 3) { // Car is full of Team A
            // The car is full we will relase the waiting people
            // 3 people are waiting from Team A
            sem_post(&semaphoreA);
            sem_post(&semaphoreA);
            sem_post(&semaphoreA);
            numReadyA = numReadyA - 3;
            Driver = true;

        } else if (numReadyA >= 1 && numReadyB >= 2) { // Car is half Team A, half Team B
            // The car is full we will relase the waiting people
            // 1 people from Team A and 2 people from Team B is waiting
            sem_post(&semaphoreA);
            numReadyA = numReadyA - 1;
            sem_post(&semaphoreB);
            sem_post(&semaphoreB);
            numReadyB = numReadyB - 2;
            Driver = true;

        } else { // The car is not ready
            numReadyA++;
            // We let go of the general lock for other threads
            sem_post(&semaphore);
            // We will be waiting for the car to be full
            sem_wait(&semaphoreA);
        }
        
    } else {
        // Team B
        // There are two different cases for car to be ready for this thread
        if (numReadyB >= 3) { // Car is full of Team B
            // The car is full we will relase the waiting people
            // 3 people are waiting from Team B
            sem_post(&semaphoreB);
            sem_post(&semaphoreB);
            sem_post(&semaphoreB);
            numReadyB = numReadyB - 3;
            Driver = true;

        } else if (numReadyB >= 1 && numReadyA >= 2) { // Car is half Team A, half Team B
            // The car is full we will relase the waiting people
            // 1 people from Team B and 2 people from Team A is waiting
            sem_post(&semaphoreB);
            numReadyB = numReadyB - 1;
            sem_post(&semaphoreA);
            sem_post(&semaphoreA);
            numReadyA = numReadyA - 2;
            Driver = true;

        } else { // The car is not ready
            numReadyB++;
            // We let go of the general lock for other threads
            sem_post(&semaphore);
            // We will be waiting for the car to be full
            sem_wait(&semaphoreB);
        }
    }

    // We need additional semaphore for print this line since it is not protected by the general lock:
    sem_wait(&outputSemaphore);
    cout << "Thread ID: " << pthread_self() << ", Team: " << team << ", I have found a spot in a car\n";
    sem_post(&outputSemaphore);

    // We need to put a barrier otherwise driver may say that I'm the driver before everyone says that they've found a car.
    pthread_barrier_wait(&barrier);

    // Only one person have to do this:
    if (Driver) {
        cout << "Thread ID: " << pthread_self() << ", Team: " << team << ", I am the captain and driving the car with ID " << CarID <<"\n";
        CarID++;
        // Refreshing the barrier
        pthread_barrier_destroy(&barrier);
        pthread_barrier_init(&barrier, NULL, 4);
        // We will let go of the general lock so other people can search for a car
        sem_post(&semaphore);
    }
}

int main(int argc, char *argv[]) {

    // Input correctness will be checked and numbers will be assigned to global variables: numA, numB
    if(!InputCheck(argc, argv)){
        cout << "Invalid Inputs\n" << "The main terminates\n";
        return 0;
    };
    
    // 4 people will enter the car so barrier is 4
    pthread_barrier_init(&barrier, NULL, 4);
    sem_init(&semaphore, 0, 1); // General Lock

    sem_init(&outputSemaphore, 0, 1); // Will be used to correctly output the string
    sem_init(&semaphoreA, 0, 0);
    sem_init(&semaphoreB, 0, 0);

    
    // Creating the threads (A)
    char * teamA = strdup("A");
    for (int i=0; i<numA; i++) {
        pthread_t thread;
        pthread_create(&thread, NULL, thread_function, teamA);
        threads.push_back(thread);
    }
    // Creating the threads (B)
    char * teamB = strdup("B");
    for (int i=0; i<numB; i++) {
        pthread_t thread;
        pthread_create(&thread, NULL, thread_function, teamB);
        threads.push_back(thread);
    }
    // Waiting for all threads to finish (A and B) (They're stored in a vector during execution)
    for (int i = 0; i < threads.size(); i++) {
        pthread_join(threads[i], NULL);
    }
    // Everyone is done
    cout << "The main terminates\n";
    return 0;
}