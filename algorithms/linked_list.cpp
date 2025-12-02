//singly
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
    Node* head;
public:
    SinglyLinkedList() { head = nullptr; }

    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, head};
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node{value, nullptr};
        if(!head) { head = newNode; return; }
        Node* temp = head;
        while(temp->next) temp = temp->next;
        temp->next = newNode;
    }

    void insertAtPosition(int value, int pos) {
        if(pos <= 1) { insertAtBeginning(value); return; }
        Node* newNode = new Node{value, nullptr};
        Node* temp = head;
        for(int i = 1; temp && i < pos-1; i++) temp = temp->next;
        if(!temp) { insertAtEnd(value); return; }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteAtBeginning() {
        if(!head) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtEnd() {
        if(!head) return;
        if(!head->next) { delete head; head = nullptr; return; }
        Node* temp = head;
        while(temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteAtPosition(int pos) {
        if(!head) return;
        if(pos <= 1) { deleteAtBeginning(); return; }
        Node* temp = head;
        for(int i = 1; temp->next && i < pos-1; i++) temp = temp->next;
        if(temp->next) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    bool search(int value) {
        Node* temp = head;
        while(temp) {
            if(temp->data == value) return true;
            temp = temp->next;
        }
        return false;
    }

    int length() {
        int count = 0;
        Node* temp = head;
        while(temp) { count++; temp = temp->next; }
        return count;
    }

    void display() {
        Node* temp = head;
        while(temp) { cout << temp->data << " "; temp = temp->next; }
        cout << endl;
    }
};

int main() {
    SinglyLinkedList list;
    list.insertAtEnd(10);
    list.insertAtBeginning(5);
    list.insertAtEnd(20);
    list.insertAtPosition(15, 3);
    list.display();
    list.deleteAtBeginning();
    list.display();
    list.deleteAtEnd();
    list.display();
    list.deleteAtPosition(2);
    list.display();
    cout << "Search 10: " << (list.search(10) ? "Found" : "Not Found") << endl;
    cout << "Length: " << list.length() << endl;
}


//doubly
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
    Node* head;
public:
    DoublyLinkedList() { head = nullptr; }

    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, head, nullptr};
        if(head) head->prev = newNode;
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node{value, nullptr, nullptr};
        if(!head) { head = newNode; return; }
        Node* temp = head;
        while(temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertAtPosition(int value, int pos) {
        if(pos <= 1) { insertAtBeginning(value); return; }
        Node* temp = head;
        for(int i = 1; temp && i < pos-1; i++) temp = temp->next;
        if(!temp || !temp->next) { insertAtEnd(value); return; }
        Node* newNode = new Node{value, temp->next, temp};
        temp->next->prev = newNode;
        temp->next = newNode;
    }

    void deleteAtBeginning() {
        if(!head) return;
        Node* temp = head;
        head = head->next;
        if(head) head->prev = nullptr;
        delete temp;
    }

    void deleteAtEnd() {
        if(!head) return;
        if(!head->next) { delete head; head = nullptr; return; }
        Node* temp = head;
        while(temp->next) temp = temp->next;
        temp->prev->next = nullptr;
        delete temp;
    }

    void deleteAtPosition(int pos) {
        if(!head) return;
        if(pos <= 1) { deleteAtBeginning(); return; }
        Node* temp = head;
        for(int i = 1; temp && i < pos; i++) temp = temp->next;
        if(temp) {
            if(temp->prev) temp->prev->next = temp->next;
            if(temp->next) temp->next->prev = temp->prev;
            delete temp;
        }
    }

    bool search(int value) {
        Node* temp = head;
        while(temp) {
            if(temp->data == value) return true;
            temp = temp->next;
        }
        return false;
    }

    int length() {
        int count = 0;
        Node* temp = head;
        while(temp) { count++; temp = temp->next; }
        return count;
    }

    void displayForward() {
        Node* temp = head;
        while(temp) { cout << temp->data << " "; temp = temp->next; }
        cout << endl;
    }

    void displayBackward() {
        if(!head) return;
        Node* temp = head;
        while(temp->next) temp = temp->next;
        while(temp) { cout << temp->data << " "; temp = temp->prev; }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;
    list.insertAtEnd(10);
    list.insertAtBeginning(5);
    list.insertAtEnd(20);
    list.insertAtPosition(15, 3);
    list.displayForward();
    list.displayBackward();
    list.deleteAtBeginning();
    list.displayForward();
    list.deleteAtEnd();
    list.displayForward();
    list.deleteAtPosition(2);
    list.displayForward();
    cout << "Search 10: " << (list.search(10) ? "Found" : "Not Found") << endl;
    cout << "Length: " << list.length() << endl;
}


//circular
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
    Node* tail;
public:
    CircularLinkedList() { tail = nullptr; }

    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, nullptr};
        if(!tail) { newNode->next = newNode; tail = newNode; return; }
        newNode->next = tail->next;
        tail->next = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node{value, nullptr};
        if(!tail) { newNode->next = newNode; tail = newNode; return; }
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }

    void deleteAtBeginning() {
        if(!tail) return;
        Node* head = tail->next;
        if(tail == head) { delete head; tail = nullptr; return; }
        tail->next = head->next;
        delete head;
    }

    void deleteAtEnd() {
        if(!tail) return;
        Node* head = tail->next;
        if(tail == head) { delete tail; tail = nullptr; return; }
        Node* temp = head;
        while(temp->next != tail) temp = temp->next;
        temp->next = tail->next;
        delete tail;
        tail = temp;
    }

    bool search(int value) {
        if(!tail) return false;
        Node* temp = tail->next;
        do {
            if(temp->data == value) return true;
            temp = temp->next;
        } while(temp != tail->next);
        return false;
    }

    int length() {
        if(!tail) return 0;
        int count = 0;
        Node* temp = tail->next;
        do { count++; temp = temp->next; } while(temp != tail->next);
        return count;
    }

    void display() {
        if(!tail) return;
        Node* temp = tail->next;
        do { cout << temp->data << " "; temp = temp->next; } while(temp != tail->next);
        cout << endl;
    }
};

int main() {
    CircularLinkedList list;
    list.insertAtEnd(10);
    list.insertAtBeginning(5);
    list.insertAtEnd(20);
    list.display();
    list.deleteAtBeginning();
    list.display();
    list.deleteAtEnd();
    list.display();
    cout << "Search 10: " << (list.search(10) ? "Found" : "Not Found") << endl;
    cout << "Length: " << list.length() << endl;
}
