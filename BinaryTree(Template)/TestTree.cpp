#include "BinarySeachTree.h"

int main()
{
	BinarySearchTree<int> myTree;

	myTree.insertData(20);
	myTree.insertData(10);
	myTree.insertData(40);
	myTree.insertData(13);
	myTree.insertData(1);
	myTree.insertData(35);
	myTree.insertData(25);
	myTree.insertData(15);
	myTree.insertData(2);
	myTree.insertData(47);
	myTree.insertData(60);
	myTree.insertData(28);
	myTree.deleteData(35);
	myTree.display();

	return 0;
}