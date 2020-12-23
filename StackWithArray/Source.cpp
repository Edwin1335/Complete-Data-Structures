#include "Stack.h"

int main()
{
	Stack<string> Friends(4);
	Friends.push("Edwin");
	Friends.push("Aarkachan");
	Friends.push("Jesus");
	Friends.push("Salmon");
	Friends.printRecursively();

	Friends.reverseStack();
	cout << endl << endl;
	Friends.printRecursively();
	
	system("pause");
	return 0;
}