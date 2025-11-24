#include <iostream>
#include <string>
using namespace std;

class Node{
    public:
    int rollNo;
    Node *next;

    Node(int r){
        rollNo = r;
        next = NULL;
    }
};

class StudentRollCallSystem{
    public:
    Node *head;  
    Node *tail;

    StudentRollCallSystem(){
        head = NULL;
        tail = NULL;
    }

    void insertAtTail(int r){
        Node *n = new Node(r);
        if(head == NULL){
            head = n;
            cout << "inserted" << endl;
            return;
        }
        Node *temp = head;
        while(temp->next != tail){
            temp = temp->next;
        }
        temp->next = n;
        n->next = tail;
        cout << "inserted" << endl;
    }

    void deleteAfter(int pos){
        Node *pre;
        Node *curr;
        curr = head;
        for(int i=1;i<pos;i++){
            pre = curr;
            curr = curr->next;
        }
        pre->next = curr->next;
        delete curr;
    }

    void display(){
        Node *temp = head;
        while(temp != NULL){
            cout << temp->rollNo << " ";
            temp = temp->next;
        }
    }
};

int main(){
    StudentRollCallSystem s1;
    s1.insertAtTail(23);
    s1.insertAtTail(45);
    s1.insertAtTail(639);
    s1.display();
    s1.deleteAfter(2);
    cout << endl;
    cout << "after deleting: " << endl;
    s1.display();
    return 0;
}