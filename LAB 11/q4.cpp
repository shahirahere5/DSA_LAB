#include <iostream>
using namespace std;

class Hash {
public:
    int arr[10];

    Hash() {
        for(int i=0;i<10;i++)
            arr[i] = -1;
    }

    int hashFunction(int key) {
        return key % 10;
    }

    void insert(int key) {
        int index = hashFunction(key);
        while(arr[index] != -1)
            index = (index + 1) % 10;
        arr[index] = key;
    }

    void removeKey(int key) {
        int index = hashFunction(key);
        int start = index;
        while(arr[index] != -1) {
            if(arr[index] == key) {
                arr[index] = -1;
                return;
            }
            index = (index + 1) % 10;
            if(index == start) break;
        }
    }

    void search(int key) {
        int index = hashFunction(key);
        int start = index;
        while(arr[index] != -1) {
            if(arr[index] == key) {
                cout << key << " found" << endl;
                return;
            }
            index = (index + 1) % 10;
            if(index == start) break;
        }
        cout << key << " not found" << endl;
    }

    void display() {
        for(int i=0;i<10;i++)
            if(arr[i] != -1)
                cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Hash h;
    h.insert(1);
    h.insert(3);
    h.insert(4);
    h.insert(5);
    h.insert(7);
    h.display();
    cout << "Remove 4" << endl;
    h.removeKey(4);
    h.display();
    h.search(5);
    h.search(6);
}
