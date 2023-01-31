#include "MPQ.h"


MPQ::MPQ(int size){
	maxSize = size;
	Heap = new int[maxSize+1]; // +1 for Heap because we dont use the first element
	Location = new int[maxSize];
	currentSize = 0;

	// We set empty cells to 0 (It will be useful to determine cells which contain value)
	for (int i = 0; i < maxSize+1; i++){
		Heap[i] = 0;
	}
	for (int i = 0; i < maxSize; i++){
		Location[i] = 0;
	}
}

MPQ::~MPQ(){
	delete[] Heap;
	delete[] Location;
}

void MPQ::insert(int value, int label){

	// We inialize our hole at the end
	int hole = ++currentSize;

	// We will stop the loop when hole becomes the root or parent is bigger than our insertion value
	for(; hole > 1 && value > Heap[hole / 2]; hole = hole/2) {
		// Move the parent to the current hole and then move the hole up
		Heap[hole] = Heap[hole / 2];

		// We need to find the label of the parent with the known position and then update it
		Location[locateLabel(hole/2)] = hole;
	}
	Heap[hole] = value;
	Location[label] = hole;
}

int MPQ::remove(int label){
	int pos = Location[label];

	// We save the value so we can return it
	int returnValue = Heap[pos];

	Heap[pos] = Heap[currentSize];
	// Also need to update the location 
	Location[locateLabel(currentSize)] = Location[label]; 
	currentSize--;
	// We need to set last element to 0 (means no value)
	Heap[currentSize+1] = 0;

	Location[label] = 0;

	percolateDown(pos);
	percolateUp(pos);

	return returnValue;
}

int MPQ::getMax(){
	return Heap[1];
}

bool MPQ::isEmpty(){
	return currentSize == 0;
}

int MPQ::locateLabel(int position){
	for (int i = 0; i < maxSize; i++){
		if(Location[i] == position) return i;
	}
	return -1;
}

void MPQ::percolateDown(int pos){
	int child;
	int temp = Heap[pos];
	// The index inside the Location array that we are gonna update at the end
	int L_index = locateLabel(pos);

	// Until we came across an empty cell 
	for (; Heap[pos*2] != 0; pos = child){
		child = pos*2;
		// We find the bigger child
		if(Heap[child+1] != 0 && Heap[child+1] > Heap[child]) child++;

		if (Heap[child] > temp) {
			Heap[pos] = Heap[child];
			// Then we update the Location array
			// We move the child to it's parent so location has changed to /2
			Location[locateLabel(child)] = Location[locateLabel(child)] / 2; 
		}
		else break;
	}
	// After we find the correct location
	Heap[pos] = temp;
	Location[L_index] = pos;
}

void MPQ::percolateUp(int pos){
	int parent;
	int temp = Heap[pos];

	// The index inside the Location array that we are gonna update at the end
	int L_index = locateLabel(pos);


	// Until we are at the root
	for (; pos > 1; pos = parent){
		parent = pos/2;

		if (Heap[pos] > Heap[parent]) {
			Heap[pos] = Heap[parent];
			// We move the the parent to it's child's location so Location has changed by *2 or *2 + 1
			// if left child
			if (pos % 2 == 1) Location[locateLabel(parent)] = Location[locateLabel(parent)] * 2;
			// if right child
			else Location[locateLabel(parent)] = (Location[locateLabel(parent)] * 2) + 1;
		} 
		else break;
	}
	Heap[pos] = temp;
	Location[L_index] = pos;
}