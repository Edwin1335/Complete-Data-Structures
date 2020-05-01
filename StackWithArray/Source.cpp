#include "Stack.h"

int main()
{
	Stack<string> theFaggots(4);
	theFaggots.push("Edwin");
	theFaggots.push("Aarkachan");
	theFaggots.push("Jesus");
	theFaggots.push("Salmon");
	theFaggots.printRecursively();

	theFaggots.reverseStack();
	cout << endl << endl;
	theFaggots.printRecursively();
	
	system("pause");
	return 0;
}