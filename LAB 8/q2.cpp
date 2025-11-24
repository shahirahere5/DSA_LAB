#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int ID;
    string name;
    Node *left;
    Node *right;

    Node(int id, string n)
    {
        ID = id;
        name = n;
        left = right = NULL;
    }
};

class Stack {
private:
    static const int MAX = 100;
    Node* arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == MAX - 1);
    }

    void push(Node* n) {
        if(!isFull()) {
            arr[++top] = n;
        }
    }

    Node* pop() {
        if(!isEmpty()) {
            return arr[top--];
        }
        return NULL;
    }

    Node* peek() {
        if(!isEmpty()) {
            return arr[top];
        }
        return NULL;
    }
};

Node* insert(Node* root, int id, string n) {
    if(root == NULL)
        return new Node(id, n);

    if(id < root->ID)
        root->left = insert(root->left, id, n);
    else if(id > root->ID)
        root->right = insert(root->right, id, n);
    else
        cout << "Customer already exists!\n";

    return root;
}

void inorder_traversal(Node* root) {
    cout << "\nInorder Traversal:\n";
    Stack st;
    Node* current = root;

    while(current != NULL || !st.isEmpty()) {
        while(current != NULL) {
            st.push(current);
            current = current->left;
        }
        current = st.pop();
        cout << "ID: " << current->ID << ", Name: " << current->name << endl;
        current = current->right;
    }
}

void preorder_traversal(Node* root) {
    cout << "\nPreorder Traversal:\n";
    if(root == NULL) return;

    Stack st;
    st.push(root);

    while(!st.isEmpty()) {
        Node* current = st.pop();
        cout << "ID: " << current->ID << ", Name: " << current->name << endl;

        if(current->right)
            st.push(current->right);
        if(current->left)
            st.push(current->left);
    }
}

void postorder_traversal(Node* root) {
    cout << "\nPostorder Traversal:\n";
    if(root == NULL) return;

    Stack st;
    Node* current = root;
    Node* lastVisited = NULL;

    while(current != NULL || !st.isEmpty()) {
        if(current != NULL) {
            st.push(current);
            current = current->left;
        }
        else {
            Node* topNode = st.peek();
            if(topNode->right != NULL && lastVisited != topNode->right) {
                current = topNode->right;
            }
            else {
                cout << "ID: " << topNode->ID << ", Name: " << topNode->name << endl;
                lastVisited = st.pop();
            }
        }
    }
}

int main() {
    Node* root = NULL;

    root = insert(root, 50, "Ali");
    root = insert(root, 35, "Fatima");
    root = insert(root, 70, "Ahmed");
    root = insert(root, 20, "Hina");
    root = insert(root, 40, "Usman");
    root = insert(root, 60, "Sara");
    root = insert(root, 80, "Bilal");

    preorder_traversal(root);
    inorder_traversal(root);
    postorder_traversal(root);

    return 0;
}
