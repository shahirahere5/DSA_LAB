#include <iostream>
using namespace std;

class Node{
    public:
    int data, height;
    Node *left, *right;

    Node(int val){
        data = val;
        height = 1;
        left = right = NULL;
    }
};

int getHeight(Node* root){
    if(!root){
        return 0;
    }

    return root->height;
}

int getBalance(Node *root){
    return getHeight(root->left) - getHeight(root->right);
}

//right rotation
Node* rightRotation(Node *root){
    Node* child = root->left;
    Node* childRight = child->right;

    child->right = root;
    root->left = childRight;

    //update the height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    return child;
}

//left rotation
Node* leftRotation(Node *root){
    Node* child = root->right;
    Node* childLeft = child->left;

    child->left = root;
    root->right = childLeft;

    //update the height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    child->height = 1 + max(getHeight(child->left), getHeight(child->right));

    return child;
}

Node* insert(Node* root, int key){
    //doesn't exist
    if(!root){
        return new Node(key);
    }

    //exist
    if(key < root->data){
        root->left = insert(root->left, key);
    }else if(key > root->data){
        root->right = insert(root->right, key);
    }else{
        return root;
    }

    //update height
    root->height = 1+ max(getHeight(root->left),getHeight(root->right));

    //balancing check
    int balance = getBalance(root);

    //left left case
    if(balance > 1 && key < root->left->data){
        return rightRotation(root);
    }else if(balance < -1 && root->right->data < key){ //right right case
        return leftRotation(root);
    }else if(balance > 1 && key > root->left->data){ //left right case
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }else if(balance < -1 && root->right->data > key){ //right left case
        root->right = rightRotation(root->right);
        return leftRotation(root);
    }else{  // no unbalancing
        return root;
    }
}

void preorder(Node* root){
    if(!root){
        return;
    }

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(!root){
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

Node* deleteNode(Node* root, int key){
    if(!root){
        return NULL;
    }

    if(key < root->data){ //left side
        root->left = deleteNode(root->left, key);
    }else if(key > root->data){ //right side
        root->right = deleteNode(root->right,key); 
    }else{
        //leaf node
        if(!root->left && !root->right){
            delete root;
            return NULL;
        }else if(root->left && !root->right){  //only one child
            Node* temp = root->left;
            delete root;
            return temp;
        }else if(root->right && !root->left){  //only one child
            Node* temp = root->right;
            delete root;
            return temp;
        }else{ //both children exist
            //right side smallest element (left-most node in the right subtree)
            Node* curr = root->right;
            while(curr->left){
                curr = curr->left;
            }

            root->data = curr->data;
            root->right = deleteNode(root->right, curr->data);
        }
    }

    //update the height
    root->height = 1 + max(getHeight(root->left), getHeight(root->right));

    //check balancing
    int balance = getBalance(root);

    //left side
    if(balance > 1){
        //LL
        if(getBalance(root->left) >= 0){
            return rightRotation(root);
        }else{ //LR
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }
    }else if(balance < -1){ //right side
        //RR
        if(getBalance(root->right) <= 0){
            return leftRotation(root);
        }else{ //RL
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
    }else{
        return root;
    }
}

int main(){
    Node* root = NULL;

    root = insert(root,10);
    root = insert(root,20);
    root = insert(root,30);
    root = insert(root,50);
    root = insert(root,70);
    root = insert(root,5);
    root = insert(root,100);
    root = insert(root,95);

    cout << "preorder: " << endl;
    preorder(root);
    cout << endl;
    cout << "inorder: " << endl;
    inorder(root);

    deleteNode(root, 50);
    cout << "inorder: " << endl;
    inorder(root);

    return 0;
}
