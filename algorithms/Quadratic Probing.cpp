#include <iostream>
using namespace std;

class QuadraticProbing {
public:
    int size;
    string* table;

    QuadraticProbing(int s) {
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

        for (int i = 0; i < size; i++) {
            int newIndex = (index + i * i) % size;
            if (table[newIndex] == "") {
                table[newIndex] = key;
                return;
            }
        }
        cout << "Hash table full\n";
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << i << ": " << table[i] << endl;
    }
};

int main() {
    QuadraticProbing h(10);
    h.insert("A");
    h.insert("B");
    h.insert("C");

    h.display();
}
