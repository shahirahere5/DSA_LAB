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

class InventoryManagement{
    public:
    Node *head;
    Node *tail;

    InventoryManagement(){
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

    void sort(){
        if(head == NULL || head->next == NULL){
            return;
        }
        bool swapped;
        do{
            swapped = false;
            Node *curr = head;
            while(curr->next != NULL){
                if(curr->ID > curr->next->ID){
                    swap(curr->ID, curr->next->ID);
                    swapped = true;
                }
                curr = curr->next;
            }
        }while(swapped);
    }
};

int main(){
    InventoryManagement inventory;
    inventory.insertAtTail(101);
    inventory.insertAtTail(200);
    inventory.insertAtTail(240);
    inventory.insertAtTail(23);
    inventory.insertAtTail(99);

    cout << "before sorting: ";
    inventory.display();

    inventory.sort();
    cout << "after sorting: ";
    inventory.display();
    return 0;
}