#include <iostream>
#include <list>
using namespace std;

const int SIZE = 10;

class HashTable {
public:
    list<pair<string,string>> table[SIZE];

    int hashFunction(string key) {
        int sum = 0;
        for (char c : key)
            sum += c;
        return sum % SIZE;
    }

    void insert(string key, string value) {
        int index = hashFunction(key);
        for (auto &p : table[index]) {
            if (p.first == key) {
                p.second = value;
                return;
            }
        }
        table[index].push_back({key, value});
    }

    void removeKey(string key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it);
                return;
            }
        }
    }

    void search(string key) {
        int index = hashFunction(key);
        for (auto &p : table[index]) {
            if (p.first == key) {
                cout << key << ": " << p.second << endl;
                return;
            }
        }
        cout << "Not found" << endl;
    }

    void display() {
        for (int i = 0; i < SIZE; i++) {
            cout << i << ": ";
            for (auto &p : table[i])
                cout << "(" << p.first << ", " << p.second << ") -> ";
            cout << "NULL" << endl;
        }
    }
};

int main() {
    HashTable h;
    h.insert("A","aaaaa");
    h.insert("B","bbbbb");
    h.insert("C","ccccc");
    h.insert("A","zzzzz");
    h.display();
    h.search("B");
    h.removeKey("B");
    h.display();
}
