#include <iostream>
#include <string>
#include <time.h>
using namespace std;

class BinaryTree
{
private:
	struct Node
	{
		int data;
		Node* left;
		Node* right;
	};
	Node* root;
	void beginInserting(Node*&, Node*&);
	void displayInOrder(Node*&) const;
	void displayPreOrder(Node*&) const;
	void displayPostOrder(Node*&) const;

public:
	BinaryTree();

	void insterData(int);
	bool search(int);

	void displayInOrder()
	{
		displayInOrder(root);
	};
	void displayPreOrder()
	{
		displayPreOrder(root);
	};
	void displayPostOrder()
	{
		displayPostOrder(root);
	};
};

BinaryTree::BinaryTree()
{
	root = NULL;
}

void BinaryTree::insterData(int x)
{
	Node* newNode = new Node;
	newNode->data = x;
	newNode->left = NULL;
	newNode->right = NULL;

	beginInserting(root, newNode);
}

void BinaryTree::beginInserting(Node *&current, Node *&newNode)
{
	if (current == NULL)
		current = newNode;
	else if (newNode->data < current->data)
		beginInserting(current->left, newNode);
	else
		beginInserting(current->right, newNode);
}

void BinaryTree::displayInOrder(Node*& current) const
{
	if (current)
	{
		displayInOrder(current->left);
		cout << "Data: " << current->data << endl;
		displayInOrder(current->right);
	}
}

void BinaryTree::displayPreOrder(Node*& current) const
{
	if (current)
	{
		cout << "Data: " << current->data << endl;
		displayPreOrder(current->left);
		displayPreOrder(current->right);
	}
}

void BinaryTree::displayPostOrder(Node*& current) const
{
	if (current)
	{
		cout << "Data: " << current->data << endl;
		displayPostOrder(current->right);
		displayPostOrder(current->left);
	}
}

bool BinaryTree::search(int x)
{
	Node* findNode = root;

	while (findNode!= NULL)
	{
		if (findNode->data == x)
			return true;
		else if (x > findNode->data)
			findNode = findNode->right;
		else
			findNode = findNode->left;
	}
	return false;
}

int main()
{
	BinaryTree myTree;

	srand(time(NULL));
	int fiveRandNum[10];
	for (int i = 0; i < 10; i ++)
	{
		fiveRandNum[i] = rand() % 100;
		cout << "Number " << i + 1  << ": " << fiveRandNum[i] << endl;
		myTree.insterData(fiveRandNum[i]);	
	
	}
	cout << "In Order" << endl;
	myTree.displayInOrder();
	cout << "\nPre Order\n";
	myTree.displayPreOrder();
	cout << "\nPre Order\n";
	myTree.displayPostOrder();

	return 0;
}