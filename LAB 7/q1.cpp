#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    int score;
    Node* next;

    Node(string n, int s) {
        name = n;
        score = s;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;

    int getMax() {
        if (!head) return 0;
        int maxVal = head->score;
        Node* temp = head->next;
        while (temp) {
            if (temp->score > maxVal)
                maxVal = temp->score;
            temp = temp->next;
        }
        return maxVal;
    }

    int getDigit(int num, int exp) {
        return (num / exp) % 10;
    }

    void countingSort(int exp) {
        Node* buckets[10] = { nullptr };
        Node* tails[10] = { nullptr };

        Node* current = head;
        while (current) {
            int digit = getDigit(current->score, exp);

            Node* newNode = new Node(current->name, current->score);

            if (!buckets[digit]) {
                buckets[digit] = tails[digit] = newNode;
            } else {
                tails[digit]->next = newNode;
                tails[digit] = newNode;
            }

            current = current->next;
        }

        Node* newHead = nullptr;
        Node* newTail = nullptr;

        for (int i = 0; i < 10; i++) {
            if (buckets[i]) {
                if (!newHead) {
                    newHead = buckets[i];
                    newTail = tails[i];
                } else {
                    newTail->next = buckets[i];
                    newTail = tails[i];
                }
            }
        }

        head = newHead;
    }

public:
    LinkedList() { head = nullptr;tail = nullptr; }

    void addNode(string name, int score) {
        Node* newNode = new Node(name, score);
        newNode->next = head;
        head = newNode;
    }

    void radixSort() {
        int maxScore = getMax();

        for (int exp = 1; maxScore / exp > 0; exp *= 10) {
            countingSort(exp);
        }
    }

    void display() {
        cout << "Sorted list of student records:\n";
        Node* temp = head;
        while (temp) {
            cout << temp->name << " " << temp->score << endl;
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList students;

    students.addNode("Ayan", 90);
    students.addNode("Sara", 70);
    students.addNode("Ali", 60);
    students.addNode("Zara", 50);
    students.addNode("Jeena", 40);

    students.radixSort();
    students.display();

    return 0;
}
