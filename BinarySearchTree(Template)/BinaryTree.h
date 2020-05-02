#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <map>

using namespace std;
/*
	This is an abstract class that will be inherited by Binary Search Tree and AVL Tree. 
	The class will be using templates to make it more versatile for all datatypes.
*/

// Node defintion - Must specify the type of Node.
template <class T>
struct Node
{
	T data;
	Node<T>* left;
	Node<T>* right;
};

// Class defintion.
template <class T>
class BinaryTree
{
private:
	void makeInsertion(Node<T> *&, Node<T> *&);
	/**********************************************************************************
		Make Insertion funtion will be used in the InsertData funtion so it 
		can iterate recusrsivly. The parameter are two adresses of pointers to nodes
		one for the root and another for the node being inserted.		
	***********************************************************************************/

	int countLeafs(Node<T> *&);
    /*************************************************************************************
		The countLeaf funtion will be passed into the treeLeafCount function(which will
		return an integer). The function will itearbly loop through all the nodes and find 
		the leaf node( nodes that have a left and right null pointers) and count them.
	*************************************************************************************/

    int countNodes(Node<T> *&);
	/*************************************************************************************
		Similar to the count leafs funtion, this will count all the nodes in the tree 
        including the root node. 
	**************************************************************************************/

	void inOrder(Node<T>*&);
	/**************************************************************************************
		This funtion will print the tree in order
	***************************************************************************************/

	void postOrder(Node<T>*&);
	/**************************************************************************************
		This funtion will print the tree in post order.
	**************************************************************************************/

	void preOrder(Node<T>*&);
	/**************************************************************************************
		This funtion will print the tree in post order.
	***************************************************************************************/
protected:
	Node<T>* root;

public:
	BinaryTree();
	bool isEmpty();			
	void insertData(T);	
	virtual bool searchData(T) = 0;
	virtual void deleteData(T) = 0;
	int treeLeafsCount();
	int treeNodesCount();
	void printOrder();
	void printPostOrder();
	void printPreOrder();
};

/**************************************************************************************
	Constructor to initlize the root to NULL. Meaning that the tree root is not 
    pointing to anything, therefore its empty.
***************************************************************************************/
template <class T>
BinaryTree<T>::BinaryTree()
{
	root = NULL;
}

/**************************************************************************************
	Check if the tree root is pointing to anything, if so return true, else 
    return false.
***************************************************************************************/
template <class T>
bool BinaryTree<T>::isEmpty()
{
	return(root == NULL);
}

/**************************************************************************************
	Create a new node that will be inserted into the tree. There is not need to check 
    wheter the tree is empty or full because no matter the state of the tree, you can 
    always insert a new node. 
***************************************************************************************/
template <class T>
void BinaryTree<T>::insertData(T x)
{
	Node<T>* newNode = new Node<T>;
	newNode->data = x;
	newNode->left = NULL;
	newNode->right = NULL;

	this->makeInsertion(root, newNode);
}

template <class T>
void BinaryTree<T>::makeInsertion(Node<T> *&root, Node<T> *&newNode)
{
	if (root == NULL)
		root = newNode;
	else if (newNode->data < root->data)
		makeInsertion(root->left, newNode);
	else if (newNode->data > root->data)
		makeInsertion(root->right, newNode);
	else
		delete newNode;
}

template <class T>
int BinaryTree<T>::treeLeafsCount()
{
	return this->countLeafs(root);
}

template <class T>
int BinaryTree<T>::countLeafs(Node<T> *&root)
{
	if (root == NULL)
		return 0;
	else if (root->left == NULL && root->right == NULL)
		return 1;
	else
		return countLeafs(root->left) + countLeafs(root->right);
}

template <class T>
int BinaryTree<T>::treeNodesCount()
{
	return this->countNodes(root);
}

template <class T>
int BinaryTree<T>::countNodes(Node<T>*& node)
{
	if (node == NULL)
		return 0;
	else
		return 1 + countNodes(node->left) + countNodes(node->right);
}

template <class T>
void BinaryTree<T>::printOrder()
{
	this->inOrder(root);
}

template <class T>
void BinaryTree<T>::inOrder(Node<T> *& node)
{
	if (node != NULL)
	{
		inOrder(node->left);
		cout << node->data << endl;
		inOrder(node->right);
	}
}

template <class T>
void BinaryTree<T>::printPostOrder()
{
	this->postOrder(root);
}

template <class T>
void BinaryTree<T>::postOrder(Node<T> *& node)
{
	if (node != NULL)
	{
		cout << node->data << endl;
		postOrder(node->left);
		postOrder(node->rigth);
	}
}

template <class T>
void BinaryTree<T>::printPreOrder()
{
	this->preOrder(root);
}

template <class T>
void BinaryTree<T>::preOrder(Node<T>*& node)
{
	if (node != NULL)
	{
		cout << node->data << endl;
		postOrder(node->rigth);
		postOrder(node->left);
	}
}
