#include <iostream>
#include <string>
#include <fstream>
#include "MPQ.h"
using namespace std;

int findMax(int list[], int numOfBuildings){
	int max = 0;
	for (int i = 0; i < numOfBuildings*2; i++){
		if (max < list[i]) max = list[i];
	}
	return max;
}

int findIndex(int list[], int num, int numOfBuildings){
	// if we find the the number we want in the array we will destroy it (otherwise it will cause error in the future).
	for (int i=0; i < numOfBuildings*2; i++){
		if(list[i] == num){
			list[i] = -1; // remove that element
			return i;
		}
	}
	// -1 means not found
	return -1;
}

bool containZero(int list[], int numOfBuildings){
	for (int i=0; i < numOfBuildings*2; i++){
		if(list[i] == 0) return true;
	}
	return false;
}

int main(){

	// Reading the input
	ifstream file;
	file.open("testCase7.txt");

	int numOfBuildings;
	file >> numOfBuildings;
	MPQ *myHeap = new MPQ(numOfBuildings);

	// Data inside the file will be put inside arrays
	int *xCoordinates = new int[numOfBuildings*2];
	int *heights = new int[numOfBuildings];
	for (int i = 0; i < numOfBuildings*2; i += 2){
		file >> xCoordinates[i] >> heights[i/2] >> xCoordinates[i+1];
	}

	// I came up with a different solution rather than sorting
	// Structure of the xCoordinates array = [leftx, rightx, .....]
	// Heights array will contain their height according to their index inside the xCoordinates

	// we need to find the maximum number in our array so we can know where do buildings end 
	int lastNum = findMax(xCoordinates, numOfBuildings);

	// Special Case for 0
	if (!containZero(xCoordinates, numOfBuildings)){
		cout << 0 << " " << 0 << endl;
	}

	int currentMax = 0;
	for (int i = 0; i<lastNum; i++){

		// We need to find the location of the current x if it is located on our file.
		int index = findIndex(xCoordinates, i, numOfBuildings);
		// While loop because there may be more than one insertion and deletion and the same x
		while (index != -1) {
			// We need to check if it is insertion or deletion of a building
			// if our index is divisible by 2 it means the start of a new building. (becuase start of a buildins is always located at indexes 0,2,4....) 
			if (index % 2 == 0) {
				// height is located at index/2 and unique label is index/2
				myHeap->insert(heights[index/2], index/2);
			} else {
				// Means it is an deletion, unique label is index/2
				myHeap->remove(index/2);
			}

			// We check again if more than one operation is done at the same x value
			index = findIndex(xCoordinates, i, numOfBuildings);
		}

		// If the max has changed we print the output
		if (myHeap->getMax() != currentMax) {
					currentMax = myHeap->getMax();
					cout << i << " " << currentMax << endl;
		}
	}
	cout << lastNum << " " << 0 << endl;
	
	return 0;
}