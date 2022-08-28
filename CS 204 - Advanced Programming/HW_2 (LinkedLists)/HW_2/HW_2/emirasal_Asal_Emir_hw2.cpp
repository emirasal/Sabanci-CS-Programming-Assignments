#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct node {

	char ch;
	node * next;

	node () {
		next = NULL;
	}
	node (char character, node *link) {
		ch = character;
		next = link;
	}
};

bool file_name_check (ifstream &file, string name);
node *build_linkedlist (ifstream &file);
void insert_node_to_end (node *head, char ch);
void print_linkedlist (node *head);
void menu (node *head1, node *head2);
bool is_lowercase (char ch);
node *del (node *head, char ch, int num);
node *delete_a_node (node *head, char ch);
int char_count (node *head, char argument1);
node *insert (node *head, char argument1, char argument2);
int sim (node *head, node *head2);
void delete_list (node *head);

int main () {

	ifstream file1, file2;
	string name1, name2;
	cout << "Please enter the file 1 name: ";
	cin >> name1;
	while (!file_name_check(file1, name1)) {
		cout << "Please enter the file 1 name: ";
		cin >> name1;
	}
	cout << "Please enter the file 2 name: ";
	cin >> name2;
	while (!file_name_check(file2, name2)) {
		cout << "Please enter the file 2 name: ";
		cin >> name2;
	}

	node *head1, *head2;
	head1 = build_linkedlist(file1);
	head2 = build_linkedlist(file2);

	cout << "List1: ";
	print_linkedlist(head1);
	cout << "List2: ";
	print_linkedlist(head2);

	menu(head1, head2);
	return 0;
}

bool file_name_check (ifstream &file, string name) {
	file.open(name.c_str());
	if (file.fail()) {
		file.close();
		return false;
	}
	else {
		return true;
	}
}

node *build_linkedlist (ifstream &file) {
	char character;
	// Head of the linked list created at the beginning.
	// And then every character added by inserting to the end of the list.
	file >> character;
	node *head = new node (character, NULL);
	while (file >> character) {
		insert_node_to_end(head, character);
	}
	return head;
}

void insert_node_to_end (node *head, char ch) {
	// While loop finds the tail of the linked list and then new node is added to the end of the list
	while ((*head).next != NULL) {
		head = (*head).next;
	}
	(*head).next = new node (ch, NULL);
}

void print_linkedlist (node *head) {
	while (head != NULL) {
		cout << (*head).ch;
		head = (*head).next;
	}
	cout << endl;
}

void menu (node *head1, node *head2) {
	string command = ""; 
	char argument1, argument2;
	// Later int num is going to be used to store the number occurences of the given character in the list.
	int num;
	while (command != "exit") {
		cout << endl << "Enter a command and its corresponding argument(s), if any: ";
		cin >> command;
		if (command == "del1") {
			cin >> argument1;
			if (is_lowercase(argument1)) {
				num = char_count(head1, argument1);
				if (num > 0) {
					cout << "Deleting all occurrences of " << argument1 << " in List1." << endl;
					head1 = del(head1, argument1, num);
					cout << "The current content of List1 is: "; 
					print_linkedlist(head1);
				}
				else {
					cout << "No deletion as the value " << argument1 << " was not found in the list" << endl;
				}
			}
		}
		else if (command == "del2") {
			cin >> argument1;
			if (is_lowercase(argument1)) {
				num = char_count(head2, argument1);
				if (num > 0) {
					cout << "Deleting all occurrences of " << argument1 << " in List2." << endl;
					head2 = del(head2, argument1, num);
					cout << "The current content of List2 is: "; 
					print_linkedlist(head2);
				}
				else {
					cout << "No deletion as the value " << argument1 << " was not found in the list" << endl;
				}
			}
		}
		else if (command == "insert1") {
			cin >> argument1 >> argument2;
			if (is_lowercase(argument1) && is_lowercase(argument2)) {
				cout << "Inserting " << argument1 << " after " << argument2 << " in List1." << endl;
				head1 = insert(head1, argument1, argument2);
				cout << "The current content of List1 is: "; 
				print_linkedlist(head1);
			}
		}
		else if (command == "insert2") {
			cin >> argument1 >> argument2;
			if (is_lowercase(argument1) && is_lowercase(argument2)) {
				cout << "Inserting " << argument1 << " after " << argument2 << " in List2." << endl;
				head2 = insert(head2, argument1, argument2);
				cout << "The current content of List2 is: "; 
				print_linkedlist(head2);
			}
		}
		else if (command == "sim") {
			cout << "Displaying the contents of the two lists:" << endl;
			cout << "List1: ";
			print_linkedlist(head1);
			cout << "List2: ";
			print_linkedlist(head2);
			cout << "There is/are " << sim(head1, head2) << " letter(s) matched in the same positions in both lists." << endl;
		}
		else if (command != "exit") {
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			cout << "Invalid command." << endl;
		}
	}
	delete_list (head1);
	delete_list (head2);
	cout << "Clearing the two lists and saying Goodbye!" << endl;
}

bool is_lowercase (char ch) {
	if (ch <= 'z' && ch >= 'a') {
		return true;
	}
	else {
		cout << "Invalid arguments." << endl;
		return false;
	}
}

node *del (node *head, char ch, int num) {
	// This loop will run the number of times that char to be deleted exits in the list.
	for (int i = 0; i < num; i++) {
		head = delete_a_node(head, ch);
	}
	return head;
}

node *delete_a_node (node *head, char ch) {
	node *ptr = head, *previous = NULL;
	// First we check if the node to be deleted is the head node;
	if (ptr!= NULL && ptr->ch == ch) {
		head = ptr->next;
		delete ptr;
	}
	else {
		previous = ptr;
		ptr = ptr->next;
		// This loop continues until we find the correct node to be deleted.
		while (ptr != NULL && ptr->ch != ch) {
			previous = ptr;
			ptr = ptr->next;
		}
		previous->next = ptr->next;
		delete ptr;
	}
	return head;
}

int char_count (node *head, char argument1) {
	// This function is used to count the number of occurenses of the given character in the list.
	int count = 0;
	while (head != NULL) {
		if (head->ch == argument1) {
			count++;
		}
		head = head->next;
	}
	return count;
}

node *insert (node *head, char argument1, char argument2) {
	// First we check if the given second character exist in the list.
	// char_count function returns 0 if the second character does not exist in the list.
	if (char_count(head, argument2)) { 
		cout << "The node with " << argument1 << " has been inserted after the first occurrence of a node with " << argument2 << " value." << endl;
		node *ptr = head;
		while (ptr != NULL) {
			if (ptr->ch == argument2) {
				node *new_node = new node(argument1, ptr->next);
				ptr->next = new_node;
				return head;
			}
			ptr = ptr->next;
		}
	}
	else {
		// When the second argument does not exist in the list we add the character to the beginning of the list.
		cout << "The node with " << argument2 << " value does not exist. Therefore, Inserting " << argument1 << " at the beginning of the list." << endl;
		node *new_node = new node(argument1, head);
		return new_node;
	}
	return head;
}

int sim (node *head1, node *head2) {
	int count = 0;
	while (head1 != NULL && head2 != NULL) {
		if (head1->ch == head2->ch) {
			count++;
		}
		head1 = head1->next;
		head2 = head2->next;
	}
	return count;
}

void delete_list (node *head) {
	node *temp;
	while (head != NULL) {
		temp = (*head).next;
		delete head;
		head = temp;
	}
}