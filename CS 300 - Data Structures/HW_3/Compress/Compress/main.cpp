#include <iostream>
#include <string>
#include "HashTable.h"
#include <fstream>

using namespace std;

int main(){

	int tableSize = 4096;
	HashTable table(tableSize);
	int codeValue = 1;

	// Variables ch and s will be used to convert the ascii value to character and then string below:
	char ch; 
	string s;
	// First we need to append the every ascii character to our hash table
	for (int i=1; i < 256; i++){
		ch = char(i);
		s = ch;
		table.insert(s, codeValue++);
	}

	// Output file defined here
	ofstream output;
	output.open("compout.txt");


	// Reading the input
	ifstream file;
	file.open("compin.txt");


	// We read the file character by character
	char c;
	string prefix;
	int outputCode; // This will be outputted to compressed file

	while (!file.eof()){
		prefix = "";
		
		// We will read until we find a string that is not inside our hashTable
		while(file.get(c)){
			prefix += c;

			// -1 means not found in the hash table
			if(table.findPos(prefix) == -1) {
				break;
			}
		}


		// We dont enter this if it the file has ended
		if (!file.eof()){

			// We will only insert if table is not full
			if (table.getSize() != tableSize) {
				table.insert(prefix, codeValue++);
			}

			// Remove the last element
			prefix.pop_back();
			// We also need to go back one char in the txt file
			file.seekg(-1, ios_base::cur);

			// Finding the correspoinding code to our prefix
			outputCode = table.findPos(prefix); 
		}
		else{
			outputCode = table.findPos(prefix); 
		}
		

		// Outputing it to the new text
		output << outputCode << " ";
	}

	return 0;
}