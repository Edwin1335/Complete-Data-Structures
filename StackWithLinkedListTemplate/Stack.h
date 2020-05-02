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
	void del_mult(int);
	void print();
};

/**************************************************************************************
	Stack default constuctor to intialize the top pointer to NULL. Meaning that there
    is nothing on the stack.
***************************************************************************************/
template <class T>
Stack<T>::Stack()
{
	top = NULL;
}

/**************************************************************************************
	Push back is a funtion that is called to add a new value to the stack, we call it 
    push back because it resembles pushing a stack back one more unit. Create a node 
    and added to the top of the satck.
***************************************************************************************/
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

/**************************************************************************************
	Pop_top will pop the top node of the stack, if the value exists.
***************************************************************************************/
template <class T>
void Stack<T>::pop_top(T &x)
{
	if (isEmpty())
		return;
	else
	{	
		Node* temp = top->bottom;
		x = top->value;
		top->value = NULL;
		delete top;
		top = temp;
	}
}

/**************************************************************************************
	Check if the stack is empty by checking if the top pointer is equal to NULL or not.
***************************************************************************************/
template <class T>
bool Stack<T>::isEmpty()
{
	if (top == NULL)
		return true;
	else
		return false;
}

/**************************************************************************************
	The del mult will delete multiple values form the stack all at once. The nuber of
    values it will delte (number of times it ill pop) is passed in as the parameter.
    Problem: can accept any integer, meaning the fuction can be called many times. 
***************************************************************************************/
template <class T>
void Stack<T>::del_mult(int count)
{
    for (int i = 0; i < count; i++)
    {
        this->pop_top();
    }
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