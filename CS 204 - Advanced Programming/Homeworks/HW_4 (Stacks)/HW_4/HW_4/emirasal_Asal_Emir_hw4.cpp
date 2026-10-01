#include <iostream>
#include <string>
#include <fstream>
#include "emirasal_Asal_Emir_hw4_DynStack.h"
using namespace std;

bool type_check (char ch, char removed_symbol) {
	bool result = false;
	if (ch == ')' && removed_symbol == '(') {
		result = true;
	}
	else if (ch == ']' && removed_symbol == '[') {
		result = true;
	}
	else if (ch == '}' && removed_symbol == '{') {
		result = true;
	}
	return result;
}

int main () {
	string filename;
	ifstream file;
	cout << "Please enter the file name: ";
	cin >> filename;
	file.open(filename);
	while (file.fail()) {
		file.close();
		cout << "File not found." << endl;
		cout << "Please enter the file name: ";
		cin >> filename;
		file.open(filename);
	}
	// removed_symbol and removed_line will be used to store the data of the top of the stack which is deleted.
	char ch, removed_symbol;
	int line = 1, removed_line;
	bool error = false;
	DynStack parentheses;
	while (!error && file.get(ch)) {
		if (ch == '(' || ch == '[' || ch == '{') {
			cout << "Found the opening symbol " << ch << " at line " << line << endl;
			parentheses.push(ch,line);
		}
		else if (ch == ')' || ch == ']' || ch == '}') {
			// We need to check if the stack is not empty because if we see a closing symbol with an empty stack it will cause an error.
			if (!parentheses.isEmpty()) {
				parentheses.pop(removed_symbol, removed_line);
				// After this point we need to check if the top of the stack matches the character.
				if (type_check(ch, removed_symbol)) {
					cout << "Found the closing symbol " << ch << " at line " << line << " which closes the opening symbol " << removed_symbol << " at line " << removed_line << endl;
				}
				else {
					error = true;
				}
			}
			else {
				error = true;
			}
		}
		else if (ch == '\n') {
			line++;
		}
	}

	if (error) {
		// Here we check if there exist a unclosed parentheses in the stack.
		if (!parentheses.isEmpty()) {
			cout << "ERROR!!! Found the closing symbol " << ch << " at line " << line << " but the last unclosed opening symbol is " << removed_symbol << " at line " << removed_line << endl;
		}
		else {
			cout << "ERROR!!! Found the closing symbol " << ch << " but there are no unclosed opening symbols!" << endl;
		}
	}
	else if (!parentheses.isEmpty()) {
		cout << "ERROR!!! The following opening symbols were not closed:" << endl;
		while (!parentheses.isEmpty()) {
			parentheses.pop(removed_symbol, removed_line);
			cout << "Symbol " << removed_symbol << " at line " << removed_line << endl;;
		}
	}
	else {
		cout << "File processed successfully. No errors were found." << endl;
	}
	return 0;
}