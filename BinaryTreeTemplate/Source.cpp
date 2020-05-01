#include "BInaryTree.h"

int main()
{
	BinarySearchTree myTree;
	myTree.insertData(20);
	myTree.insertData(10);
	myTree.insertData(5);
	myTree.insertData(23);
	myTree.insertData(64);
	myTree.insertData(8);
	myTree.insertData(1);
	myTree.insertData(11);
	myTree.printInOrder();
	bool myBool = myTree.searchTree(64);
	if (myBool)
		cout << "found \n";
	else
		cout << "Not found\n";
	return 0;
}