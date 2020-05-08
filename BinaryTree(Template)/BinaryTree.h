#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <map>

using namespace std;
/****************************************************************************
	This is an abstract class that will be inherited by Binary Search Tree
    and AVL Tree. The class will be using templates to make it more versatile
    for all datatypes.
****************************************************************************/

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
    int countLeafs(Node<T>*&);
    /****************************************************************************
		The countLeaf funtion will be passed into the treeLeafCount function 
        (which will return an integer). The function will itearbly loop through 
        all the nodes and find the leaf node( nodes that have a left and right 
        null pointers) and count them.
	****************************************************************************/

    int countNodes(Node<T>*&);
    /****************************************************************************
		Similar to the count leafs funtion, this will count all the nodes in the 
        tree including the root node.
	****************************************************************************/

    void inOrder(Node<T>*&);
    /****************************************************************************
		This funtion will print the tree in order
	****************************************************************************/

    void postOrder(Node<T>*&);
    /****************************************************************************
		This funtion will print the tree in post order.
	****************************************************************************/

    void preOrder(Node<T>*&);
    /****************************************************************************
		This funtion will print the tree in post order.
	****************************************************************************/

protected:
    Node<T>* root;
    // Default constructor.
	BinaryTree();
    // Chek if tree is empty.
	bool isEmpty();
    // Add data to the tree. 
	void insertData(T);
    // Search will be diffferent for AVL and BST.
	virtual bool searchData(T) = 0;
    // Delete will be different for AVL and BST.
	virtual void deleteData(T) = 0;
    // Count the number of leafs in the tree/
	int treeLeafsCount();
    // Count the number of nodes in the tree.
	int treeNodesCount();
    // Print the data in order.
	void printOrder();
    // Print the data post order.
	void printPostOrder();
    // Print the data pre order.
	void printPreOrder();
};

template <class T>
BinaryTree<T>::BinaryTree()
{   
    // Initialize the poiter to the root to NULL.
	root = NULL;
}

template <class T>
bool BinaryTree<T>::isEmpty()
{
    // If the root is not pointing to anything then it is empty.
	return(root == NULL);
}

template <class T>
int BinaryTree<T>::treeLeafsCount()
{
	return this->countLeafs(root);
}

template <class T>
int BinaryTree<T>::countLeafs(Node<T>*& root)
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
void BinaryTree<T>::inOrder(Node<T>*& node)
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
void BinaryTree<T>::postOrder(Node<T>*& node)
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
