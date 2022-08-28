#include <iostream>
#include <string>

using namespace std;
// Emir Asal

int main () {
	cout << "Welcome to CS201 physical classroom capacity checker." << endl;

	string room_name;
	cout << "Please enter the room name: ";
	cin >> room_name;

	int capacity;
	cout << "Please enter the room capacity: ";
	cin >> capacity;
	if (capacity < 0) {
		cout << "You have entered an invalid value for room capacity." << endl;
		return 0;
	}

	double coefficient;
	cout << "Please enter the allowed capacity coefficient: ";
	cin >> coefficient;
	if (coefficient <= 0 || coefficient > 1) {
		cout << "You have entered an invalid value for capacity coefficient." << endl;
		return 0;
	}

	int registered_students;
	cout << "Please enter how many students are registered to your course: ";
	cin >> registered_students;
	if (registered_students < 0) {
		cout << "You have entered an invalid value for registered students." << endl;
		return 0;
	} 

	int allowed_capacity = capacity * coefficient;
	if (registered_students <= allowed_capacity) {
		cout << room_name << " can allow all students to attend physical lectures." << endl;
	}
	else {
		int zoom_students = registered_students - allowed_capacity;
		cout << room_name << " cannot allow all students to attend physical lectures." << endl;
		cout << "For each lecture " << zoom_students << " students must be selected to watch on Zoom." << endl;
	}

	return 0;
}