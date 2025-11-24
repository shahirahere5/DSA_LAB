#include <iostream>
using namespace std;

class Node{
    public:
    int seatNo;
    bool reserved;
    Node *next;

    Node(int n){
        seatNo = n;
        reserved = false;
        next = NULL;
    }
};

class RideManagement{
    public:
    Node *head;
    Node *tail;

    RideManagement(){
        head = NULL;
        tail = NULL;
    }

    void insertAtEnd(int sn){
        Node *n = new Node(sn);
        if(head == NULL){
            head = n;
            tail = n;
            tail->next = head;
            return;
        }
        tail->next = n;
        tail = tail->next;
        tail->next = head;
    }

    void display(){
        if(head == NULL){
            cout << "no seats available" << endl;
            return;
        }
        Node *temp = head;
        do{
            cout << "seat:" << temp->seatNo << endl;
            cout << "reserved?: " << (temp->reserved ? "reserved" : "available") << endl;
            temp = temp->next;
        }while(temp != head);
    }
};

int main(){
    RideManagement r1;
    r1.insertAtEnd(1);
    r1.insertAtEnd(2);
    r1.insertAtEnd(3);
    r1.display();
    return 0;
}