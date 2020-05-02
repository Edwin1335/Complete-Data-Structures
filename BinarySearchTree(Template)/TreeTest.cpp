#include "BinaryTree.h"
#include "BinarySearchTree.h"

int main()
{
	BinarySearchTree<int> myTree;

	myTree.insertData(20);
	myTree.insertData(10);
	myTree.insertData(1);
	myTree.insertData(15);
	myTree.insertData(12);
	myTree.insertData(17);
	myTree.insertData(40);
	myTree.insertData(30);
	myTree.insertData(50);
	myTree.insertData(35);
	myTree.insertData(60);

	myTree.display();


	system("pause");
	return 0;
}