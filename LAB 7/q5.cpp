#include <iostream>
using namespace std;

class Node {
public:
    string url;
    Node* next;

    Node(string u) {
        url = u;
        next = nullptr;
    }
};

class Stack {
private:
    string data[100];
    int top;
public:
    Stack() { top = -1; }

    void push(string val) {
        if (top < 99) data[++top] = val;
    }

    string pop() {
        if (top >= 0) return data[top--];
        else return "";
    }

    bool isEmpty() {
        return top == -1;
    }

    string peek() {
        if (top >= 0) return data[top];
        return "";
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() { head = nullptr; }

    void visitWebsite(string url) {
        Node* newNode = new Node(url);
        newNode->next = head;
        head = newNode;
    }

    void removeFirst() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void showHistory() {
        cout << "Browsing History (most recent first): ";
        Node* temp = head;
        while (temp) {
            cout << temp->url;
            if (temp->next) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }

    string currentPage() {
        if (head) return head->url;
        return "No pages visited";
    }
};

int main() {
    LinkedList history;
    Stack backStack;

    string sites[5] = {"Google", "Facebook", "Twitter", "LinkedIn", "Instagram"};

    cout << "User visits websites:" << endl;
    for (int i = 0; i < 5; i++) {
        history.visitWebsite(sites[i]);
        backStack.push(sites[i]);
        cout << sites[i] << endl;
    }

    cout << "Current: " << endl;
    history.showHistory();
    cout << "Current Page: " << history.currentPage() << endl;

    cout << "User clicks BACK twice..." << endl;
    backStack.pop();
    backStack.pop();
    history.removeFirst();
    history.removeFirst();

    cout << "After going back twice: " << endl;
    history.showHistory();
    cout << "Current Page: " << history.currentPage() << endl;

    return 0;
}
