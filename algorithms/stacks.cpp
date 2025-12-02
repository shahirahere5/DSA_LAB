//arrays
#include <iostream>
using namespace std;

class Stack {
    int top;
    int arr[100];
public:
    Stack() { top = -1; }

    void push(int x) {
        if(top == 99) cout << "Stack Overflow\n";
        else arr[++top] = x;
    }

    void pop() {
        if(top == -1) cout << "Stack Underflow\n";
        else top--;
    }

    int peek() {
        if(top == -1) return -1;
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    
    cout << "Top element: " << s.peek() << endl; // 30
    s.pop();
    cout << "Top after pop: " << s.peek() << endl; // 20
}

//linked list
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
    Node* top;
public:
    Stack() { top = nullptr; }

    void push(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if(top == nullptr) {
            cout << "Stack Underflow\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    int peek() {
        if(top == nullptr) return -1;
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.peek() << endl; // 30
    s.pop();
    cout << "Top after pop: " << s.peek() << endl; // 20
}
