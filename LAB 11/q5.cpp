#include <iostream>
using namespace std;

const int SIZE = 20;

class Node {
public:
    int a, b;
    Node* next;

    Node(int x, int y) {
        a = x;
        b = y;
        next = NULL;
    }
};

class HashTable {
public:
    Node* table[SIZE];

    HashTable() {
        for(int i=0;i<SIZE;i++)
            table[i] = NULL;
    }

    int hashFunction(int sum) {
        return sum % SIZE;
    }

    bool insertPair(int x, int y) {
        int sum = x + y;
        int index = hashFunction(sum);

        Node* temp = table[index];

        while(temp != NULL) {
            if(temp->a != x && temp->b != x &&
               temp->a != y && temp->b != y) {

                cout << "(" << temp->a << ", " << temp->b << ") and ("
                     << x << ", " << y << ")" << endl;

                return true;
            }
            temp = temp->next;
        }

        Node* newNode = new Node(x, y);
        newNode->next = table[index];
        table[index] = newNode;

        return false;
    }
};

bool findPairs(int arr[], int n) {
    HashTable h;

    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(h.insertPair(arr[i], arr[j]))
                return true;
        }
    }

    cout << "No pairs found" << endl;
    return false;
}

int main() {
    int a1[] = {3, 4, 7, 1, 2, 9, 8};
    int a2[] = {3, 4, 7, 1, 12, 9};
    int a3[] = {65, 30, 7, 90, 1, 9, 8};

    findPairs(a1,7);
    findPairs(a2,6);
    findPairs(a3,7);
}
