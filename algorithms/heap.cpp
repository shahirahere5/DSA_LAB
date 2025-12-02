#include <iostream>
using namespace std;

int capacity = 100;

// ======================= MAX HEAP =======================
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

    void insert(int val) {
        if (size == capacity) {
            cout << "Heap is full." << endl;
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

    void deleteValue(int val) {
        int i;

        for (i = 0; i < size; i++) {
            if (heap[i] == val)
                break;
        }

        if (i == size) {
            cout << "Value not found." << endl;
            return;
        }

        heap[i] = heap[size - 1];
        size--;

        maxHeapify(i);
    }

    void heapSort() {
        int originalSize = size;

        for (int i = size - 1; i > 0; i--) {
            swap(heap[0], heap[i]);
            size--;
            maxHeapify(0);
        }

        cout << "Sorted (ascending): ";
        for (int i = 0; i < originalSize; i++)
            cout << heap[i] << " ";

        cout << endl;

        size = originalSize;
    }

    void removeMax() {
        if (size <= 0) {
            cout << "Heap is empty." << endl;
            return;
        }

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

// ======================= MIN HEAP =======================
class MinHeap {
public:
    int heap[100];
    int size;

    MinHeap() {
        size = 0;
    }

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return (2 * i) + 1; }
    int rightChild(int i) { return (2 * i) + 2; }

    void insert(int val) {
        if (size == capacity) {
            cout << "Heap is full." << endl;
            return;
        }

        heap[size] = val;
        size++;

        int i = size - 1;

        while (i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void minHeapify(int i) {
        int smallest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            minHeapify(smallest);
        }
    }

    void deleteValue(int val) {
        int i;

        for (i = 0; i < size; i++) {
            if (heap[i] == val)
                break;
        }

        if (i == size) {
            cout << "Value not found." << endl;
            return;
        }

        heap[i] = heap[size - 1];
        size--;

        minHeapify(i);
    }

    void removeMin() {
        if (size <= 0) {
            cout << "Heap is empty." << endl;
            return;
        }

        heap[0] = heap[size - 1];
        size--;

        minHeapify(0);
    }

    void display() {
        cout << "Heap: ";
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};


// ======================= MAIN =======================
int main() {

    MaxHeap heap1;
    cout << "-------------- Max Heap ---------------" << endl;

    heap1.insert(25); heap1.display();
    heap1.insert(30); heap1.display();
    heap1.insert(35); heap1.display();
    heap1.insert(11); heap1.display();
    heap1.insert(15); heap1.display();
    heap1.insert(19); heap1.display();
    heap1.insert(18); heap1.display();
    heap1.insert(55); heap1.display();
    heap1.insert(78); heap1.display();
    heap1.insert(36); heap1.display();

    cout << "After removing 55: ";
    heap1.deleteValue(55);
    heap1.display();

    heap1.heapSort();


    MinHeap heap2;
    cout << "-------------- Min Heap ---------------" << endl;

    heap2.insert(25); heap2.display();
    heap2.insert(30); heap2.display();
    heap2.insert(35); heap2.display();
    heap2.insert(11); heap2.display();
    heap2.insert(15); heap2.display();
    heap2.insert(19); heap2.display();
    heap2.insert(18); heap2.display();
    heap2.insert(55); heap2.display();
    heap2.insert(78); heap2.display();
    heap2.insert(36); heap2.display();

    cout << "After removing 18: ";
    heap2.deleteValue(18);
    heap2.display();
}
