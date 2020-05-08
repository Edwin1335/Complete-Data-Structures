#pragma once
#include "BinaryTree.h"

template <class T>
class BinarySearchTree : public BinaryTree<T>
{
private:
    bool beginSeach(Node<T> *&, T);
    void makeInsertion(Node<T> *&, Node<T> *&);
    Node<T> *makeDeletion(Node<T> *&);
    void display(Node<T> *&, int);
    void deleteData(Node<T> *&, T);

public:
    BinarySearchTree();
    bool searchData(T);
    void insertData(T);
    void deleteData(T);
    void display();
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
bool BinarySearchTree<T>::beginSeach(Node<T> *&node, T x)
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
void BinarySearchTree<T>::insertData(T x)
{
    Node<T> *newNode = new Node<T>;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = x;

    makeInsertion(this->root, newNode);
}

template <class T>
void BinarySearchTree<T>::makeInsertion(Node<T> *&root, Node<T> *&newNode)
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
void BinarySearchTree<T>::deleteData(T x)
{
    deleteData(this->root, x);
}

template <class T>
void BinarySearchTree<T>::deleteData(Node<T> *&node, T x)
{
    // Check if tree is not empty.
    if (node == NULL)
        std::cout << "ERROR: Cannot delete from an empty tree" << std::endl;
    else
    {
        // Create a node to traverse and another to follow behind.
        Node<T> *current = this->root;
        Node<T> *trail = new Node<T>;
        bool found = false;

        // Loop unitl you find the valu or until you reach the end.
        while (current != NULL && !found)
        {
            if (current->data == x)
                found = true;
            else
            {
                trail = current;

                if (x > current->data)
                    current = current->right;
                else
                    current = current->left;
            }
        }

        // If value was not found.
        if (current == NULL)
        {
            std::cout << "ERROR: Value " << x << " to delete not found" << std::endl;
            return;
        }
        else
        {
            if (current == this->root)
                this->root = makeDeletion(current);
            else if (trail->data > x)
                trail->left = makeDeletion(current);
            else
                trail->right = makeDeletion(current);
        }
    }
}

template <class T>
Node<T> *BinarySearchTree<T>::makeDeletion(Node<T> *&del)
{

    if (del->left == NULL && del->right == NULL)
    {
        return NULL;
    }
    if(del->left == NULL && del->right != NULL)
    {
        return del->right;
    }
    if(del->left != NULL && del->right == NULL)
    {
        return del->left;
    }
    if(del->left != NULL && del->right != NULL)
    {
        Node<T>* current = del->left;
        while(current->right != NULL)
        {
            current = del->
        }
    }
}

template <class T>
void BinarySearchTree<T>::display()
{
    this->display(this->root, 0);
}

template <class T>
void BinarySearchTree<T>::display(Node<T> *&t, int level)
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