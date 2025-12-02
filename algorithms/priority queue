#include <iostream>
using namespace std;

struct Node {
    int value;      // The value of the element
    int priority;   // The priority of the element
    Node* next;     // Pointer to the next node in the queue

    Node(int val, int pri) : value(val), priority(pri), next(nullptr) {}
};

// PriorityQueue class
class PriorityQueue {
private:
    Node* front; // The front of the queue

public:

    // Constructor
    PriorityQueue() : front(nullptr) {}

    // Destructor to free the memory
    ~PriorityQueue() {
        while (front) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // Insert a new element with a given priority
    void insert(int val, int pri) {
        Node* newNode = new Node(val, pri);

        // If the queue is empty or the new node has higher priority than the front
        if (!front || pri > front->priority) {
            newNode->next = front;
            front = newNode;
        }
        else {
            // Otherwise, find the correct position based on priority
            Node* current = front;

            while (current->next && current->next->priority >= pri) {
                current = current->next;
            }

            newNode->next = current->next;
            current->next = newNode;
        }
    }

    // Remove the element with the highest priority (front of the queue)
    void remove() {
        if (!front) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    // Get the element with the highest priority (front of the queue)
    int peek() {
        if (!front) {
            cout << "Queue is empty!" << endl;
            return -1; // Error value
        }
        return front->value;
    }

    // Print the entire queue (from front to back)
    void printQueue() {
        if (!front) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Node* current = front;
        while (current) {
            cout << "(" << current->value << ", " << current->priority << ") ";
            current = current->next;
        }
        cout << endl;
    }
};

// ------------------ TEST CODE ------------------
int main() {
    PriorityQueue pq;

    pq.insert(10, 2);
    pq.insert(5, 5);
    pq.insert(20, 1);
    pq.insert(15, 3);

    cout << "Priority Queue: ";
    pq.printQueue();

    cout << "Peek: " << pq.peek() << endl;

    pq.remove();
    cout << "After removing highest priority: ";
    pq.printQueue();

    return 0;
}
