#include <iostream>
using namespace std;

class LinearProbing {
public:
    int size;
    string* table;

    LinearProbing(int s) {
        size = s;
        table = new string[size];
        for (int i = 0; i < size; i++)
            table[i] = "";
    }

    int hashFunc(string key) {
        int sum = 0;
        for (char c : key) sum += c;
        return sum % size;
    }

    void insert(string key) {
        int index = hashFunc(key);

        while (table[index] != "") {
            index = (index + 1) % size; // linear
        }
        table[index] = key;
    }

    bool search(string key) {
        int index = hashFunc(key);
        int start = index;

        while (table[index] != "") {
            if (table[index] == key)
                return true;
            index = (index + 1) % size;
            if (index == start) break;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << i << ": " << table[i] << endl;
    }
};

int main() {
    LinearProbing h(10);
    h.insert("A");
    h.insert("B");
    h.insert("C");

    h.display();
}
