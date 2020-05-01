#pragma once
#include "BinaryTree.h"

template <class T>
class BinarySearchTree : public BinaryTree<T>
{
private:
	bool beginSeach(Node<T> *&, T);
	void deleteData(Node<T> *&, Node<T>*&, T);
	void display(Node<T>*&, int);

public:
	BinarySearchTree();
	bool searchData(T);
	void deleteData(T);
	void display();
	void makeDeletion(Node<T> *&, Node<T> *&);
};

template <class T>
BinarySearchTree<T>::BinarySearchTree()
{
	this->root = NULL;
}

template <class T>
bool BinarySearchTree<T>::searchData(T x)
{
	return this->beginSeach(this->root, x);
}

template <class T>
bool BinarySearchTree<T>::beginSeach(Node <T>*& node, T x)
{
	if (node->data == x)
		return true;
	else if (x < node->data)
		return beginSeach(node->left, x);
	else if (x > node->data)
		return beginSeach(node->right, x);
	else
		return false;
}

template <class T>
void BinarySearchTree<T>::deleteData(T x)
{
	this->deleteData(this->root, this->root, x);
}

template <class T>
void BinarySearchTree<T>::deleteData(Node<T> *&node, Node<T>*& prev, T x)
{
	if (x > node->data)
		deleteData(node->right, node, x);
	else if (x < node->data)
		deleteData(node->left, node, x);
	else
		this->makeDeletion(node, prev);
}

template <class T>
void BinarySearchTree<T>::makeDeletion(Node<T>*& node, Node<T>*& prev)
{
	if (node == NULL)
	{
		delete node;
		prev->left = NULL;
		prev->right = NULL
	}
	else if (node->right == NULL)
	{
		Node<T>* newNode = node->left;
		Node<T>* prev = newNode;
		while (newNode->right != NULL)
		{
			prev = newNode;
			newNode = newNode->right;
		}
		prev->right = NULL;
		node->data = newNode->data;
		delete newNode;
	}
}

template <class T>
void BinarySearchTree<T>::display()
{
	this->display(this->root, 0);
}

template <class T>
void BinarySearchTree<T>::display(Node<T>*& t, int level)
{
	if (t == nullptr)
		return;
	display(t->right, level + 1);
	cout << endl;
	for (int i = 0; i < level; i++)
		cout << "    ";
	cout << t->data << endl;
	display(t->left, level + 1);
}