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
    myTree.insertData(29);
    myTree.insertData(21);
    myTree.insertData(38);
    myTree.display();
    std::cout << "Number of leaf nodes are " << myTree.treeLeafsCount() << std::endl;
    std::cout << "Total number of nodes are " << myTree.treeNodesCount() << std::endl;
    std::cout << "\nPrinting in order" << std::endl;
    myTree.printOrder();
    std::cout << "\nPrinting reverse order" << std::endl;
    myTree.printReverseOrder();

    return 0;
}