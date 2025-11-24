#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;
    Node *prev;

    Node(){
        data = 0;
        next = NULL;
        prev = NULL;
    }

    Node(int val){
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList{
    public:
    Node *head;
    Node *tail;

    DoublyLinkedList(){
        head = NULL;
        tail = NULL;
    }

    void insertAtEnd(int val){
        Node *n = new Node(val);
        if(tail == nullptr){
            head = n;
            tail = n;
        }else{
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }

    void deleteAtFront(){
        if(head == NULL){
            cout << "empty list" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        if(head != NULL){
            head->prev = NULL;
        }else{
            tail = NULL;
        }
        delete temp;
    }

    bool search(int val){
        Node *temp = head;
        while(temp != NULL){
            if(temp->data == val){
                return true;
            }
            temp=temp->next;
        }
        return false;
    }

    void display(){
        if (head == NULL) {
            cout << "empty list" << endl;
            return;
        }
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    DoublyLinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    cout << "List after insertions: ";
    list.display();

    list.deleteAtFront();
    cout << "After deleting front: ";
    list.display();

    cout << "Searching for 20: " << (list.search(20) ? "Found" : "Not Found") << endl;
    cout << "Searching for 40: " << (list.search(40) ? "Found" : "Not Found") << endl;
    return 0;
}