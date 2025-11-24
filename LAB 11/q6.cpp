#include <iostream>
using namespace std;

class StudentHashTable {
public:
    int rolls[15];
    string names[15];

    StudentHashTable() {
        for(int i=0;i<15;i++) {
            rolls[i] = -1;
            names[i] = "";
        }
    }

    int hashFunction(int roll) {
        return roll % 15;
    }

    void InsertRecord(int roll, string name) {
        int index = hashFunction(roll);
        int attempt = 0;

        while(attempt < 15) {
            int newIndex = (index + attempt*attempt) % 15;

            if(rolls[newIndex] == -1) {
                rolls[newIndex] = roll;
                names[newIndex] = name;
                return;
            }
            attempt++;
        }

        cout << "Table full, cannot insert\n";
    }

    void SearchRecord(int roll) {
        int index = hashFunction(roll);
        int attempt = 0;

        while(attempt < 15) {
            int newIndex = (index + attempt*attempt) % 15;

            if(rolls[newIndex] == roll) {
                cout << names[newIndex] << endl;
                return;
            }

            if(rolls[newIndex] == -1) break;

            attempt++;
        }

        cout << "Record not found" << endl;
    }
};

int main() {
    StudentHashTable s;

    s.InsertRecord(20, "Ali");
    s.InsertRecord(35, "Sara");
    s.InsertRecord(50, "Ahmed");

    s.SearchRecord(35);
    s.SearchRecord(99);
}
