#include <iostream>
#include <string>
#include "CircularLinkedList.h"

void testing()
{
	CircularList<int> myList;
	myList.insert(2);
	myList.insert(23);
	myList.insert(34);

	myList.print();
	std::cout << "\ndeleting the begginign " << std::endl;
	myList.del_beg();
	myList.print();
	std::cout << std::endl << "Deleting the end node" << std::endl;
	myList.del_end();
	myList.del_beg();
	myList.print();
}

int main()
{
	testing();

	return 0;
	system("pause");
}