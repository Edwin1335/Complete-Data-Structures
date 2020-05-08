#include "BinaryTree.h"
#include "BinarySearchTree.h"

int main()
{
	BinarySearchTree<int> myTree;
    myTree.insertData(5);
    myTree.deleteData(0);
    myTree.display();

    return 0;
}