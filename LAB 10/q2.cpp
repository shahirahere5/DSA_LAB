#include <iostream>
using namespace std;

int capacity = 100;

class MaxHeap {
public:
    int heap[100];
    int size;

    MaxHeap() {
        size = 0;
    }

    int parent(int i) {
        return (i - 1) / 2;
    }

    int leftChild(int i) {
        return (2 * i) + 1;
    }

    int rightChild(int i) {
        return (2 * i) + 2;
    }

    void insert(int val) {
        if (size == capacity) {
            cout << "Heap is full!" << endl;
            return;
        }

        heap[size] = val;
        size++;

        int i = size - 1;
        while (i != 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void maxHeapify(int i) {
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < size && heap[left] > heap[largest])
            largest = left;

        if (right < size && heap[right] > heap[largest])
            largest = right;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            maxHeapify(largest);
        }
    }

    void removeMax() {
        if (size <= 0) {
            cout << "Heap is empty!" << endl;
            return;
        }

        cout << "Deleted root (max element): " << heap[0] << endl;

        heap[0] = heap[size - 1]; 
        size--;                   

        maxHeapify(0);           
    }

    void display() {
        cout << "Heap: ";
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};

int main() {
    MaxHeap H;

    H.insert(50);
    H.insert(30);
    H.insert(40);
    H.insert(10);
    H.insert(20);
    H.insert(35);
    H.insert(25);

    cout << "Original Max Heap:" << endl;
    H.display();
    cout << endl;
    cout << "Removing root (highest priority)..." << endl;
    H.removeMax();

    cout << "Updated Heap after deletion:" << endl;
    H.display();

    return 0;
}
