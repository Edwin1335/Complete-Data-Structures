#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
};

class BinarySearchTree
{
private:
	Node* root;
	void makeInsertion(Node*&, Node*&);
	bool search(Node*&, int);
	void deleteNode(Node*&, int);
	void makeDeletion(Node*&);

	void inOrder(Node*&);
	void preOrder(Node*&);
	void postOrder(Node*&);

public:
	BinarySearchTree();
	void insertData(int x);
	bool searchTree(int x);
	void deleteData(int x);

	void printInOrder();
	void printPreOrder();
	void printPostOrder();

};

BinarySearchTree::BinarySearchTree()
{
	this->root = NULL;
}

void BinarySearchTree::insertData(int x)
{
	Node* newNode = new Node;
	newNode->data = x;
	newNode->left = NULL;
	newNode->right = NULL;
	
	makeInsertion(root, newNode);
}

void BinarySearchTree::makeInsertion(Node*& root, Node*& newNode)
{
	if (root == NULL)
		root = newNode;
	else if (newNode->data < root->data)
		makeInsertion(root->left, newNode);
	else
		makeInsertion(root->right, newNode);
}

bool BinarySearchTree::searchTree(int x)
{
	return search(root, x);
}

bool BinarySearchTree::search(Node*& root, int x)
{
	if (root == NULL)
		return false;
	else if (root->data == x)
		return true;
	else if (x < root->data)
		search(root->left, x);
	else if (x > root->data)
		search(root->right, x);
}

void BinarySearchTree::deleteData(int x)
{
	deleteNode(root, x);
}

void BinarySearchTree::deleteNode(Node*& root, int x)
{
	if (root)
	{
		if (root->data == x)
			this->makeDeletion(root);
		else if (x < root->data)
			deleteNode(root->left, x);
		else if (x > root->data)
			deleteNode(root->right, x);
	}
}

void BinarySearchTree::makeDeletion(Node*& deltNode)
{
	if (deltNode->left == NULL && deltNode->right == NULL)
	{
		delete deltNode;
	}
	else if (deltNode->right == NULL)
	{

	}
	else
	{

	}
}

void BinarySearchTree::printInOrder()
{
	inOrder(root);
}

void BinarySearchTree::printPostOrder()
{
	postOrder(root);
}

void BinarySearchTree::printPreOrder()
{
	preOrder(root);
}

void BinarySearchTree::inOrder(Node*& root)
{
	if (root != NULL)
	{		
		inOrder(root->left);
		cout << root->data << endl;
		inOrder(root->right);
	}
}

void BinarySearchTree::preOrder(Node*& root)
{
	if (root != NULL)
	{
		cout << root->data << endl;
		inOrder(root->left);
		inOrder(root->right);
	}
}

void BinarySearchTree::postOrder(Node*& root)
{
	if (root != NULL)
	{
		inOrder(root->right);
		inOrder(root->left);
		cout << root->data << endl;
	}
}