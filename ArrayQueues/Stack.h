#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T>
class Stack
{
private:
	struct Node
	{
		T value;
		Node* bottom;
	};
	Node* top;

public:
	Stack();
	void push_back(T);
	void pop_top(T&);
	bool isEmpty();
	void del_mult();
	void print();
};

template <class T>
Stack<T>::Stack()
{
	top = NULL;
}

template <class T>
void Stack<T>::push_back(T x)
{
	Node* newNode = new Node;
	newNode->value = x;
	newNode->bottom = NULL;

	if (isEmpty())
		top = newNode;
	else
	{
		newNode->bottom = top;
		top = newNode;
	}
}

template <class T>
void Stack<T>::pop_top(T& x)
{
	if (isEmpty())
		cout << "ERROR: Cannot pop from empty stack" << endl;
	else
	{
		Node* temp = top->bottom;
		x = top->value;
		top->value = NULL;
		delete top;
		top = temp;
	}
}

template <class T>
bool Stack<T>::isEmpty()
{
	if (top == NULL)
		return true;
	else
		return false;
}

template <class T>
void Stack<T>::del_mult()
{

}

template <class T>
void Stack<T>::print()
{
	if (!isEmpty())
	{
		int x;
		this->pop_top(x);

		cout << x << endl;
		print();
		this->push_back(x);
	}
}