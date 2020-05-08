#include "BinaryTree.h"
#include "BinarySearchTree.h"

int main()
{
    BinarySearchTree<int> myTree;
    myTree.insertData(25);
    myTree.insertData(12);
    myTree.insertData(2);
    myTree.insertData(50);
    myTree.insertData(23);
    myTree.insertData(54);
    myTree.insertData(6);
    myTree.insertData(23);
    myTree.insertData(56);
    myTree.deleteData(6);
    myTree.display();

    return 0;
}