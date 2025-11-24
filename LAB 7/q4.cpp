#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;

    void swap(Node* a, Node* b) {
        int temp = a->data;
        a->data = b->data;
        b->data = temp;
    }

    Node* partition(Node* start, Node* end, Node** newHead, Node** newEnd) {
        Node* pivot = end;
        Node* prev = nullptr;
        Node* curr = start;
        Node* tail = pivot;

        while (curr != pivot) {
            if (curr->data < pivot->data) {
                if ((*newHead) == nullptr)
                    (*newHead) = curr;

                prev = curr;
                curr = curr->next;
            } else {
                if (prev)
                    prev->next = curr->next;

                Node* tmp = curr->next;
                curr->next = nullptr;
                tail->next = curr;
                tail = curr;
                curr = tmp;
            }
        }

        if ((*newHead) == nullptr)
            (*newHead) = pivot;

        (*newEnd) = tail;

        return pivot;
    }

    Node* quickSortRecur(Node* start, Node* end) {
        if (!start || start == end)
            return start;

        Node *newHead = nullptr, *newEnd = nullptr;

        Node* pivot = partition(start, end, &newHead, &newEnd);

        if (newHead != pivot) {
            Node* temp = newHead;
            while (temp->next != pivot)
                temp = temp->next;
            temp->next = nullptr;

            newHead = quickSortRecur(newHead, temp);

            Node* tail = newHead;
            while (tail->next)
                tail = tail->next;
            tail->next = pivot;
        }

        pivot->next = quickSortRecur(pivot->next, newEnd);

        return newHead;
    }

    Node* getTail(Node* curr) {
        while (curr && curr->next)
            curr = curr->next;
        return curr;
    }

public:
    LinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void addNode(int val) {
        Node* newNode = new Node(val);
        if (!head)
            head = newNode;
        else {
            Node* temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void quickSort() {
        Node* tail = getTail(head);
        head = quickSortRecur(head, tail);
    }

    void printList() {
        if (!head) {
            cout << "List is empty.\n";
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;

    list.addNode(10);
    list.addNode(7);
    list.addNode(8);
    list.addNode(9);
    list.addNode(1);
    list.addNode(5);
    list.addNode(3);

    cout << "Original list:\n";
    list.printList();

    list.quickSort();

    cout << "\nSorted list:\n";
    list.printList();

    return 0;
}
