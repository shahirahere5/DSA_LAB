#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(NULL), right(NULL) {}
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = NULL;
    }

    Node* createNode(int v) {
        return new Node(v);
    }

    void preorder(Node* r) {
        if (!r) return;
        cout << r->data << " ";
        preorder(r->left);
        preorder(r->right);
    }

    void inorder(Node* r) {
        if (!r) return;
        inorder(r->left);
        cout << r->data << " ";
        inorder(r->right);
    }

    void postorder(Node* r) {
        if (!r) return;
        postorder(r->left);
        postorder(r->right);
        cout << r->data << " ";
    }
};

int main() {
    BinaryTree t;
    t.root = t.createNode(1);
    t.root->left = t.createNode(2);
    t.root->right = t.createNode(3);
    t.root->left->left = t.createNode(4);
    t.root->left->right = t.createNode(5);

    t.preorder(t.root);
    cout << endl;
    t.inorder(t.root);
    cout << endl;
    t.postorder(t.root);
}
