#include <iostream>
using namespace std;

class Node
{
public:
	int ID;
	int quantity;
	Node *left;
	Node *right;
	Node(int id, int q)
	{
		ID = id;
		quantity = q;
		left = NULL;
		right = NULL;
	}
};

Node *insert(Node *root, int id, int q)
{
	if (root == NULL)
	{
		cout << "ID: " << id << ", Quantity: " << q << endl;
		return new Node(id, q);
	}
	if (id < root->ID)
	{
		root->left = insert(root->left, id, q);
	}
	else if (id > root->ID)
	{
		root->right = insert(root->right, id, q);
	}
	else
	{
		root->quantity = q;
	}
	return root;
}
void setQuantity(Node *root, int id, int q)
{
	if (root == NULL)
	{
		return;
	}
	if (root->ID == id)
	{
		root->quantity = q;
		cout << "Updated Data of ID " << id << endl;
		return;
	}
	else if (id < root->ID)
	{
		setQuantity(root->left, id, q);
	}
	else
	{
		setQuantity(root->right, id, q);
	}
}
Node *search(Node *root, int id)
{
	if (root == NULL || root->ID == id)
	{
		return root;
	}
	if (id < root->ID)
	{
		return search(root->left, id);
	}
	else
	{
		return search(root->right, id);
	}
}
void Max(Node *root, int &m, int &id)
{
	if (root == NULL)
	{
		return;
	}
	if (root->quantity > m)
	{
		m = root->quantity;
		id = root->ID;
	}
	Max(root->left, m, id);
	Max(root->right, m, id);
}
void printInorder(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	printInorder(root->left);
	cout << "ID: " << root->ID << ", Quantity: " << root->quantity << endl;
	printInorder(root->right);
}

int main()
{
	Node *root=NULL;
	root=insert(root, 1001, 10);
	root = insert(root, 2002, 20);
    root = insert(root, 3003, 30);
	printInorder(root);
	setQuantity(root, 2002, 25);
	printInorder(root);
	int mq=-1, mid=-1;
	Max(root, mq, mid);
	cout << "Product with highest quantity: ID=" << mid << ", Quantity=" << mq << endl;
	Node* result = search(root, 3003);
        if (result != NULL){
            cout << "Search For quantity according to ID " << result->ID << endl << result->quantity << endl;
		}
		else{
            cout << "Product ID not found.\n";
		}
	return 0;
}