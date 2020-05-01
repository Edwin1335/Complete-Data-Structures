#include "SingleLinkedList.h"
#include <iostream>
using namespace std;

int main()
{
	SingleLinkedList<int> myList;
	myList.insert_end(10);
	myList.insert_beg(34);
	myList.insert_end(45);

	myList.print();
	myList.reverse();
	myList.print();
	myList.insert_beg(34);
	myList.insert_end(45);
	myList.insert_end(45);
	myList.print();

	return 0;
}