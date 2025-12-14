#include <iostream>
using namespace std;

class Rehashing {
public:
    int size;
    int count;
    int* table;

    Rehashing(int s) {
        size = s;
        count = 0;
        table = new int[size];
        for (int i = 0; i < size; i++)
            table[i] = -1;
    }

    int hashFunc(int key) { return key % size; }

    void rehash() {
        int oldSize = size;
        int* oldTable = table;

        size = size * 2 + 1;         // new size
        table = new int[size];
        for (int i = 0; i < size; i++)
            table[i] = -1;

        count = 0;

        for (int i = 0; i < oldSize; i++) {
            if (oldTable[i] != -1)
                insert(oldTable[i]);
        }
        delete[] oldTable;
    }

    void insert(int key) {
        if ((double)count / size >= 0.7)
            rehash();

        int index = hashFunc(key);
        while (table[index] != -1)
            index = (index + 1) % size;

        table[index] = key;
        count++;
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << i << ": " << table[i] << endl;
    }
};

int main() {
    Rehashing h(5);
    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(40);
    h.display();
}
