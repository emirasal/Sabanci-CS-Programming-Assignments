#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int id;
    int size;
    int index;

    Node (int myId, int mySize, int myIndex) {
        id = myId;
        size = mySize;
        index = myIndex;
    }
};

class HeapManager {

    private: 
        vector<Node> heap;
        pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

    public:
        int initHeap (int size) {
            heap.push_back(Node(-1, size, 0));
            cout << "Memory initialized" << endl;
            print();
            return 1;
        }

        int myMalloc (int id, int size) {
            pthread_mutex_lock(&lock);
            
            for (int i=0; i < heap.size(); i++) {
                
                // We have enough space
                if (heap[i].id == -1 && heap[i].size >= size) {
                    Node newMemory(id, size, heap[i].index);
                    // We check if we have exact space or we need to split
                    // Since we are using vectors, we need additional changes so that the new element added just before the free element
                    if (heap[i].size == size) {
                        heap.insert(heap.begin() + i, newMemory);
                        // index changes (bcs added before the free memory)
                        heap[i+1].index += size;
                        heap[i+1].size = 0;
                        
                    } else { // Needs splitting
                        heap.insert(heap.begin() + i, newMemory);
                        // index changes (bcs added before the free memory)
                        heap[i+1].index += size;
                        heap[i+1].size = heap[i+1].size - size;
                    }

                    cout << "Allocated for thread " << id << endl;
                    print();
                    pthread_mutex_unlock(&lock);
                    return newMemory.index;
                }
            }
            // Iterated over the heap and could not found available space
            cout << "Can not allocate, requested size " << size << " for thread " << id << " is bigger than remaining size" << endl;
            print();
            pthread_mutex_unlock(&lock);
            return -1;
        }

        int myFree (int id, int index) {
            pthread_mutex_lock(&lock);
            

            for (int i = 0; i < heap.size(); i++) {
                if (heap[i].id == id && heap[i].index == index) { // Found the node to delete
                    heap[i].id = -1;
                    
                    // next element
                    int nextIndex = i + 1;
                    if (nextIndex < heap.size() && heap[nextIndex].id == -1) {
                        heap[i].size += heap[nextIndex].size;
                        heap.erase(heap.begin() + nextIndex);
                    }

                    // previous element
                    int prevIndex = i - 1;
                    if (prevIndex >= 0 && heap[prevIndex].id == -1) {
                        heap[i].index = heap[prevIndex].index;
                        heap[i].size += heap[prevIndex].size;
                        heap.erase(heap.begin() + prevIndex);
                    }
                    cout << "Freed for thread " << id << endl;
                    print();
                    pthread_mutex_unlock(&lock);
                    return 1;
                }
            } 
            // id is not the list
            cout << "Can not free, requested node with ID " << id << " and index " << index << " for thread " << id << " does not exist" << endl;
            print();
            pthread_mutex_unlock(&lock);
            return -1;
        }

        void print () {
            // Printing the first one seperatly to manage the "--- correctly"
            cout << "[" << heap[0].id << "]" << "[" << heap[0].size << "]" << "[" << heap[0].index << "]";
            // Rest of the heap
            for (int i=1; i < heap.size(); i++){
                cout << "---" << "[" << heap[i].id << "]" << "[" << heap[i].size << "]" << "[" << heap[i].index << "]";
            }
            cout << endl;
        }
};