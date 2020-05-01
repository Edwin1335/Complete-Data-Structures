#pragma once
#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;

class Queue
{
private:
	int* myQueue;
	int size;
	int front;
	int rear;
	int totalItems;
	

public:
	Queue(int);
	Queue(Queue&);
	bool isEmpty();
	bool isFull();
	void enQueue(int);
	int deQueue();
	void print();
	void printRecursive();
	bool search(int x);
};

Queue::Queue(int x)
{
	size = x;
	myQueue = new int[size];
	front = -1;
	rear = -1;
	totalItems = 0;
}

Queue::Queue(Queue& myQueue)
{

}

bool Queue::isEmpty()
{
	if (totalItems == 0)
		return true;
	else
		return false;
}

bool Queue::isFull()
{
	if (totalItems == size)
		return true;
	else
		return false;
}

void Queue::enQueue(int x)
{
	if (isFull())
		cout << "ERROR: List is full" << endl;
	else
	{
		rear = (rear + 1) % size;
		myQueue[rear] = x;
		totalItems++;
	}
}

int Queue::deQueue()
{
	if (isEmpty())
	{
		cout << "ERROR: List is empty" << endl;
	}
	else
	{
		front = (front + 1) % size;
		int x = myQueue[front];
		totalItems--;
		return x;
	}
}

void Queue::print()
{
	while (!isEmpty())
	{
		cout << deQueue() << endl;
	}
}

void Queue::printRecursive()
{
	if (!isEmpty())
	{
		int x = this->deQueue();
		cout << x << endl;
		printRecursive();
		//this->enQueue(x);
	}
}

bool Queue::search(int x)
{
	if (isEmpty())
		return false;
	else
	{
		if (x == this->myQueue[front])
			return true;
		else
		{
			int y = deQueue();
			return search(x);
		}
	}
}

