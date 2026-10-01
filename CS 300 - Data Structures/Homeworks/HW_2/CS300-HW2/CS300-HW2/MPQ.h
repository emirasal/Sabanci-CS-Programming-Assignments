#include <iostream>
using namespace std;


class MPQ {
private:
	int *Heap;
	int *Location;
	int currentSize;
	int maxSize;
	int locateLabel(int position); // Find the label when position on the heap is given.
	void percolateDown(int pos);
	void percolateUp(int pos);
public:
	MPQ(int size);
	~MPQ();
	void insert(int value, int label);
	int remove(int label);
	int getMax();
	bool isEmpty();
};