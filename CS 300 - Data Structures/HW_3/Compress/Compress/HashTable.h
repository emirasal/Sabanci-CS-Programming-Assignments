#include <string>
#include <vector>
#include <iostream>

using namespace std;

// Making my own hashtable with linear probbing
class HashTable {
public:
	HashTable(int size);
	void insert(string x, int c);
	int findPos(string x); // if returns -1 it means not inside
	int getSize();
private:

	struct HashNode{
		string key;
		int code;

		// -1 means empty, 1 means occupied
		int state;

		// inital constructor used in main class constructor
		HashNode(){
			state = -1;
		}
	};

	HashNode *table; //table array will be created in Constructor
	int maxSize;
	int currentSize;
	int hash(string x);
};