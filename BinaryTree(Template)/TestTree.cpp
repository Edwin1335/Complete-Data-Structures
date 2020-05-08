#include "BinarySeachTree.h"

int main()
{
	BinarySearchTree<int> myTree;
    myTree.insertData(20);
    myTree.insertData(4);
    myTree.insertData(5);
    myTree.insertData(24);
    myTree.insertData(23);
    myTree.insertData(65);
    myTree.insertData(32);
    myTree.insertData(12);
    myTree.insertData(1);
    myTree.insertData(7);
    myTree.display();

    return 0;
}