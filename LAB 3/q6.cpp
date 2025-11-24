#include <iostream>
#include <string>
using namespace std;

class Node{
    public:
    int ID;
    Node *next;

    Node(int i){
        ID = i;
        next = NULL;
    }
};

class TaskSchedule{
    public:
    Node *head;
    Node *tail;

    TaskSchedule(){
        head = NULL;
        tail = NULL;
    }

    void insertAtTail(int i){
        Node *n = new Node(i);
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

    void display(){
        Node *temp = head;
        while(temp != NULL){
            cout << temp->ID << " ";
            temp = temp->next;
        }
    }

    static Node* merge(Node* l1, Node *l2){
        if(l1 == NULL){
            return l2;
        }else if(l2 == NULL){
            return l1;
        }
        Node *newHead = NULL;
        if(l1->ID <= l2->ID){
            newHead = l1;
            newHead->next = merge(l1->next,l2);
        }else{
            newHead = l2;
            newHead->next = merge(l1,l2->next);
        }
        return newHead;
    }
};

int main(){
    TaskSchedule l1,l2,newList;
    l1.insertAtTail(1);
    l1.insertAtTail(3);
    l1.insertAtTail(5);

    l2.insertAtTail(2);
    l2.insertAtTail(4);
    l2.insertAtTail(6);

    Node *newHead = TaskSchedule::merge(l1.head,l2.head);
    newList.head = newHead;

    newList.display();
    return 0;
}