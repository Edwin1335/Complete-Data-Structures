#include "Stack.h"

int main()
{
	Student roster;

	roster.pushStudent(123, "Edwin");
	roster.pushStudent(34, "Arrakachan");
	roster.pushStudent(345, "John");
	roster.pushStudent(67, "Ninfa");
	roster.pushStudent(979, "Sal");
	roster.printRecursive();
	roster.reverseStack();
	cout << "Reverse" << endl << endl;
	roster.printRecursive();



	system("pause");
	return 0;
}