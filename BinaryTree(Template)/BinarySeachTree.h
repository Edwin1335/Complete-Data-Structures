#pragma once
#include "BinaryTree.h"

template <class T>
class BinarySearchTree : public BinaryTree<T>
{
private:
    bool beginSeach(Node<T> *&, T);
    void display(Node<T> *&, int);
    void deleteDataPrivate(Node<T> *&, T &);
    void makeDeletion(Node<T> *&);
    void makeInsertion(Node<T> *&, Node<T> *&);

public:
    BinarySearchTree();
    bool searchData(T);
    void deleteData(T);
    void insertData(T);
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
    newNode->data = x;
    newNode->left = NULL;
    newNode->right = NULL;
    makeInsertion(this->root, newNode);

}

template <class T>
void BinarySearchTree<T>::makeInsertion(Node<T> *&rot, Node<T> *&newNode)
{
    if (rot == NULL)
        rot = newNode;
    else if (newNode->data > rot->data)
        makeInsertion(rot->right, newNode);
    else if (newNode->data < rot->data)
        makeInsertion(rot->left, newNode);
    else
        delete newNode;
}

template <class T>
void BinarySearchTree<T>::deleteData(T x)
{
    this->deleteDataPrivate(this->root, x);
}
template <class T>
void BinarySearchTree<T>::deleteDataPrivate(Node<T> *&node, T &x)
{
    Node<T> *current;      //pointer to traverse the tree
    Node<T> *trailCurrent; //pointer behind current
    bool found = false;

    if (this->root == NULL)
        std::cout << "Cannot delete from an empty tree." << std::endl;
    else
    {
        current = this->root;
        trailCurrent = this->root;

        while (current != NULL && !found)
        {
            if (current->data == x)
                found = true;
            else
            {
                trailCurrent = current;

                if (current->data > x)
                    current = current->left;
                else
                    current = current->right;
            }
        } //end while

        if (current == nullptr)
            std::cout << "The item to be deleted is not in the tree." << std::endl;
        else if (found)
        {
            if (current == this->root)
                makeDeletion(this->root);
            else if (trailCurrent->data > x)
                makeDeletion(trailCurrent->left);
            else
                makeDeletion(trailCurrent->right);
        }
        else
            std::cout << "The item to be deleted is not in the tree." << std::endl;
    }
}

template <class T>
void BinarySearchTree<T>::makeDeletion(Node<T> *&p)
{
    Node<T> *current;      //pointer to traverse the tree
    Node<T> *trailCurrent; //that uses a recursive algorithm instead. Hint: watch video tutorials. Write a test program to test your function and save a screenshot of a test run showing your insert function works properly.*trailCurrent;  //pointer behind current
    Node<T> *temp;         //pointer to delete the node

    if (p == nullptr)
        std::cout << "Error: The node to be deleted does not exist." << std::endl;
    // Node to be deleted is a leaf node
    else if (p->left == nullptr && p->right == nullptr)
    {
        temp = p;
        p = nullptr;
        delete temp;
    }
    // Node to be deleted has only a right child
    else if (p->left == nullptr)
    {
        temp = p;
        p = temp->right;
        delete temp;
    }
    // Node to be deleted has only a left child
    else if (p->right == nullptr)
    {
        temp = p;
        p = temp->left;
        delete temp;
    }
    else                   // Node to be deleted has a left child and a right child
    {                      // replace node with right-most node of left subtree
        current = p->left; // move left once
        trailCurrent = nullptr;

        while (current->right != nullptr) // find right-most node of left subtree
        {
            trailCurrent = current;
            current = current->right;
        } //end while

        p->data = current->data;

        if (trailCurrent == nullptr) //current did not move;
            //current == p->left; adjust p
            p->left = current->left;
        else
            trailCurrent->right = current->left;

        delete current;
    } //end else
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

    std::cout << std::endl;

    for (int i = 0; i < level; i++)
        std::cout << "    ";

    std::cout << t->data << std::endl;
    display(t->left, level + 1);
}