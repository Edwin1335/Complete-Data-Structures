#include <iostream>
#include <string>
#include "DoublyLinkedList.h"
using namespace std;

void useList()
{
	DoublyLinkedList<int> myList;
	myList.insert_beg(20);
	myList.insert_end(45);
	myList.insert_end(50);
	myList.insert_end(60);
	myList.insert_end(70);
	myList.insert_end(89);
	myList.print();
	myList.del_beg();
	myList.del_end();
	myList.print();

}

int main()
{

	useList();
	return 0;
}