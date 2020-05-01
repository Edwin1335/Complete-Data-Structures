#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
using namespace std;

// Creating a class called "Stack"
template <class T>
class Stack
{
private:
	T* myStack;							// Will be a poibter to an array
	int size;							// The constant size of the array
	int top;							// The integer it points to

public:					
	Stack(int);							// Overloaded constructor 

	T pop();							// To remove the top item of the stack 
	void push(T);						// To add and iem to the top of the stack 
	void reverseStack();				// Reverse the stack
	void printReverseRecursively();		// To reverse the stack 
	void printRecursively();			// Print normal order

	bool isFull();						// To check if the array is full
	bool isEmpty();						// To check if the stack is empty 
};

// Constructor that will initialize my stack to NULL and top to -1;
template <class T>
Stack<T>::Stack(int x)
{
	size = x;
	myStack = new T[size];
	top = -1;
}

// Funtion that will check if the stack is full.
template <class T>
bool Stack<T>::isFull()
{
	if (top == size - 1)
		return true;
	else
		return false;
}

// Funtion that will check if the stack is empty
template <class T>
bool Stack<T>::isEmpty()
{
	if (top == -1)
		return true;
	else
		return false;
}

// Adding to the top of the array
template <class T>
void Stack<T>::push(T x)
{
	if (isFull())
		cout << "Stack is Full cannot push further more" << endl;
	else
	{
		top++;
		myStack[top] = x;
	}
}

// Deleting the top of the array;
template <class T>
T Stack<T>::pop()
{
	if (isEmpty())
		cout << "Stack is Empty cannot delete further more" << endl;
	else
	{
		T x = myStack[top];
		top--;
		return x;
	}
}

// Reverse the Stack
template <class T>
void Stack<T>::reverseStack()
{
	Stack newStack(this->size);
	while (this->top != -1)
	{
		T x = this->pop();
		newStack.push(x);
	}

	Stack newerStack(newStack.size);
	while (newStack.top != -1)
	{
		T x = newStack.pop();
		newerStack.push(x);
	}

	while (newerStack.top != -1)
	{
		T x = newerStack.pop();
		this->push(x);
	}
}

// Print the reversed stack
template <class T>
void Stack<T>::printReverseRecursively()
{
	if (top != -1)
	{
		T x = this->pop();
		printReverseRecursively();
		cout << x << endl;
		this->push(x);
	}
}

// Printign the stack with a recursive funtion
template <class T>
void Stack<T>::printRecursively()
{
	if (top != -1)
	{
		T x = this->pop();
		cout << x << endl;
		printRecursively();
		this->push(x);
	}
}

