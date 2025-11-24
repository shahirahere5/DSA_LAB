#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};
Node* createNode(int data){
        return new Node(data);
}
int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftH=height(root->left);
    int rightH=height(root->right);
    return (leftH>rightH? leftH: rightH)+1;
}
bool insertatLevel(Node* root, int data, int level){
    if(root==NULL){
        return false;
    }
    if(level==1){
        if(root->left==NULL){
            root->left=createNode(data);
            return true;
        }
        else if(root->right==NULL){
            root->right=createNode(data);
            return true;
        }
        else{
            return false;
        }
    }
    if(insertatLevel(root->left, data, level-1)){
        return true;
    }
    return insertatLevel(root->right, data, level-1);
}
Node* insert(Node* root, int data){
    if(root==NULL){
        return createNode(data);
    }
    int h=height(root);
    for(int i=1; i<=h; i++){
        if(insertatLevel(root, data, i)){
            return root;
        }
    }
    insertatLevel(root, data, h+1);
    return root;
}
void printPreorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    printPreorder(root->left);
    printPreorder(root->right);
}

int main(){
    Node* root= createNode(1);
    root->left= createNode(2);
    root->right=createNode(3);
    root->left->left=createNode(4);
    root->left->right=createNode(5);
    cout << "Before insertion: ";
    printPreorder(root);
    insert(root,6);
    cout << "\nAfter insertion: ";
    printPreorder(root);
    return 0;
}