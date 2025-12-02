//array
#include <iostream>
using namespace std;

class Queue {
    int front, rear;
    int arr[100];
public:
    Queue() { front = rear = -1; }

    void enqueue(int x) {
        if(rear == 99) cout << "Queue Overflow\n";
        else {
            if(front == -1) front = 0;
            arr[++rear] = x;
        }
    }

    void dequeue() {
        if(front == -1 || front > rear) cout << "Queue Underflow\n";
        else front++;
    }

    int peek() {
        if(front == -1 || front > rear) return -1;
        return arr[front];
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.peek() << endl; // 10
    q.dequeue();
    cout << "Front after dequeue: " << q.peek() << endl; // 20
}


//linked list
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
    Node *front, *rear;
public:
    Queue() { front = rear = nullptr; }

    void enqueue(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = nullptr;
        if(rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }

    void dequeue() {
        if(front == nullptr) {
            cout << "Queue Underflow\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        if(front == nullptr) rear = nullptr;
        delete temp;
    }

    int peek() {
        if(front == nullptr) return -1;
        return front->data;
    }

    bool isEmpty() {
        return front == nullptr;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.peek() << endl; // 10
    q.dequeue();
    cout << "Front after dequeue: " << q.peek() << endl; // 20
}
