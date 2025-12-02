#include <iostream>
using namespace std;

struct Node {
    string key;
    Node* next;
};

class HashChaining {
public:
    int size;
    Node** table;

    HashChaining(int s) {
        size = s;
        table = new Node*[size];
        for (int i = 0; i < size; i++)
            table[i] = nullptr;
    }

    int hashFunc(string key) {
        int sum = 0;
        for (char c : key) sum += c;
        return sum % size;
    }

    void insert(string key) {
        int index = hashFunc(key);
        Node* newNode = new Node{key, table[index]};
        table[index] = newNode;        // insert at head
    }

    bool search(string key) {
        int index = hashFunc(key);
        Node* curr = table[index];
        while (curr) {
            if (curr->key == key) return true;
            curr = curr->next;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << i << ": ";
            Node* curr = table[i];
            while (curr) {
                cout << curr->key << " -> ";
                curr = curr->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    HashChaining h(10);

    h.insert("A");
    h.insert("B");
    h.insert("C");
    h.insert("A");

    h.display();
}
