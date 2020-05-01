#include "Queue.h"

int main()
{
	Queue x(5);
	x.enQueue(100);
	x.enQueue(200);
	x.enQueue(400);
	x.enQueue(500);
	x.enQueue(600);
	x.print();
	if (x.search(234))
		cout << "Found";
	else
		cout << "Not found" << endl;

	system("pause");
	return 0;
}