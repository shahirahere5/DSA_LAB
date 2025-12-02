#include <iostream>
using namespace std;

class DoubleHash {
public:
    int size;
    string* table;

    DoubleHash(int s) {
        size = s;
        table = new string[size];
        for (int i = 0; i < size; i++)
            table[i] = "";
    }

    int hash1(string key) {
        int sum = 0;
        for (char c : key) sum += c;
        return sum % size;
    }

    int hash2(string key) {
        int sum = 0;
        for (char c : key) sum += c;
        return 7 - (sum % 7);    // must be non-zero
    }

    void insert(string key) {
        int index1 = hash1(key);
        int index2 = hash2(key);

        int i = 0;
        while (table[(index1 + i * index2) % size] != "") {
            i++;
        }

        table[(index1 + i * index2) % size] = key;
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << i << ": " << table[i] << endl;
    }
};

int main() {
    DoubleHash h(10);
    h.insert("A");
    h.insert("B");
    h.insert("C");

    h.display();
}
