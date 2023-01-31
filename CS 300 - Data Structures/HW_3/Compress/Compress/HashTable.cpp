#include "HashTable.h"


HashTable::HashTable(int size){
	maxSize = size;
	table = new HashNode[size];
	currentSize = 0;
}

int HashTable::hash(string x){
	// They will be hashed according to sum of the ascii values of characters
	int sum=0;

	for(int i=0; i < x.length(); i++){
		sum += ((int(x[i]) % 256 + 256) % 256);
	}
	return sum % maxSize;
}


void HashTable::insert(string x, int c){
	int position = hash(x);
	// We need to find the correct position to insert it
	while (table[position].state != -1) position++;

	table[position].state = 1;
	table[position].key = x;
	table[position].code = c;

	currentSize++;
}


int HashTable::findPos(string x){
	int p = hash(x);
	int startPos = p;

	// We go on if we come accross an empty cell without finding the same value we return false
	while(table[p].state != -1){

		// Found the same value
		if (table[p].key == x) return table[p].code;
		p++;

		// After increment we check if the max size is reached
		if (p == maxSize) p = 0;

		// If we end up where we started we also return not found
		if(startPos == p) return -1;
	}
	return -1;
}

int HashTable::getSize(){
	return currentSize;
}