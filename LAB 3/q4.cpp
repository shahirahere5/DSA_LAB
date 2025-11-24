#include <iostream>
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

class PhotoGallery{
    public:
    Node *head;
    Node *tail;

    PhotoGallery(){
        head = NULL;
        tail= NULL;
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

    void printReverse(Node *node){
        if(node == NULL){
            return;
        }
        printReverse(node->next);
        cout << node->ID << " ";
    }

    void showReverse(){
        printReverse(head);
        cout << endl;
    }
};

int main(){
    PhotoGallery gallery;
    gallery.insertAtTail(101);
    gallery.insertAtTail(102);
    gallery.insertAtTail(103);
    gallery.insertAtTail(104);
    gallery.showReverse();
    return 0;
}