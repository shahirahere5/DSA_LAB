#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(NULL), right(NULL) {}
};

class BST {
public:
    Node* root;

    BST() {
        root = NULL;
    }

    Node* insert(Node* r, int v) {
        if (!r) return new Node(v);
        if (v < r->data) r->left = insert(r->left, v);
        else if (v > r->data) r->right = insert(r->right, v);
        return r;
    }

    bool search(Node* r, int v) {
        while (r) {
            if (v == r->data) return true;
            r = (v < r->data) ? r->left : r->right;
        }
        return false;
    }

    Node* minNode(Node* r) {
        while (r && r->left) r = r->left;
        return r;
    }

    Node* deleteNode(Node* r, int v) {
        if (!r) return r;

        if (v < r->data) r->left = deleteNode(r->left, v);
        else if (v > r->data) r->right = deleteNode(r->right, v);
        else {
            if (!r->left) {
                Node* t = r->right;
                delete r;
                return t;
            }
            else if (!r->right) {
                Node* t = r->left;
                delete r;
                return t;
            }
            Node* temp = minNode(r->right);
            r->data = temp->data;
            r->right = deleteNode(r->right, temp->data);
        }
        return r;
    }

    void inorder(Node* r) {
        if (!r) return;
        inorder(r->left);
        cout << r->data << " ";
        inorder(r->right);
    }

    void preorder(Node* r) {
        if (!r) return;
        cout << r->data << " ";
        preorder(r->left);
        preorder(r->right);
    }

    void postorder(Node* r) {
        if (!r) return;
        postorder(r->left);
        postorder(r->right);
        cout << r->data << " ";
    }
};

int main() {
    BST t;
    t.root = t.insert(t.root, 50);
    t.insert(t.root, 30);
    t.insert(t.root, 70);
    t.insert(t.root, 20);
    t.insert(t.root, 40);
    t.insert(t.root, 60);
    t.insert(t.root, 80);

    t.inorder(t.root);
    cout << endl;

    t.root = t.deleteNode(t.root, 70);
    t.inorder(t.root);
}
