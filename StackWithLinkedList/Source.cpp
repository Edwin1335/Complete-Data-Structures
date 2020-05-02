#include "Stack.h"

int main()
{
	Student roster;

	roster.push(123, "Edwin");
	roster.push(34, "Arrakachan");
	roster.push(345, "John");
	roster.push(67, "Ninfa");
	roster.push(979, "Sal");
	roster.printRecursive();
	roster.reverseStack();
	cout << "Reverse" << endl << endl;
	roster.printRecursive();



	system("pause");
	return 0;
}