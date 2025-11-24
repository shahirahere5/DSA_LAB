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

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return (2 * i) + 1; }
    int rightChild(int i) { return (2 * i) + 2; }

    void display() {
        cout << "Heap: ";
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
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
        cout << "Processing task with priority: " << heap[0] << endl;

        heap[0] = heap[size - 1];
        size--;
        maxHeapify(0);
    }

    void updatePriority(int oldVal, int newVal) {
        int index = -1;

        for (int i = 0; i < size; i++) {
            if (heap[i] == oldVal) {
                index = i;
                break;
            }
        }

        if (index == -1) {
            cout << "Task not found!" << endl;
            return;
        }

        heap[index] = newVal;

        if (newVal > oldVal) {
            while (index != 0 && heap[parent(index)] < heap[index]) {
                swap(heap[index], heap[parent(index)]);
                index = parent(index);
            }
        } else {
            maxHeapify(index);
        }
    }
};

int main() {
    MaxHeap tasks;

    tasks.insert(40);
    tasks.display();

    tasks.insert(20);
    tasks.display();

    tasks.insert(60);
    tasks.display();

    tasks.insert(10);
    tasks.display();

    tasks.insert(50);
    tasks.display();

    cout << "\nProcessing highest priority task...\n";
    tasks.removeMax();
    tasks.display();

    cout << "\nUpdating priority (20 → 55)...\n";
    tasks.updatePriority(20, 55);
    tasks.display();

    cout << "\nUpdating priority (55 → 15)...\n";
    tasks.updatePriority(55, 15);
    tasks.display();

    cout << "\nFinal Heap After All Operations:\n";
    tasks.display();

    return 0;
}
