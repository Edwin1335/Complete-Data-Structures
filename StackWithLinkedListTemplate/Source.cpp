#include "Stack.h"

int main()
{
	Stack<int> myStack;

	myStack.push_back(1);
	myStack.push_back(2);
	myStack.push_back(3);
	myStack.push_back(4);
	myStack.push_back(5);
	myStack.print();
	int c;
	myStack.pop_top(c);
	cout << "Popping " << c << endl;
	myStack.print();


	system("pause");
	return 0;
}