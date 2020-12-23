#pragma once
#include <iostream>
#include <string>

template <class T>
class Stack
{
private:
    struct Node
    {
        T value;
        Node *bottom;
    };
    Node *top;

public:
    Stack();
    ~Stack();
    void push_back(T);
    T get_top();
    void pop_top();
    bool isEmpty();
    void del_mult(int);
    void ins_mult();
    void print();
    void print_reverse();
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
    and added to the top of the stack.
***************************************************************************************/
template <class T>
void Stack<T>::push_back(T x)
{
    Node *newNode = new Node;
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
void Stack<T>::pop_top()
{
    if (isEmpty())
        return;
    else
    {
        Node *temp = top->bottom;
        top = NULL;
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

/**************************************************************************************
	Still needs to fix, continues to read for some reason. Never stops.
***************************************************************************************/
template <class T>
void Stack<T>::ins_mult()
{
    T x;
    while (std::getline(std::cin, x)) //&& x != "stop")
    {
        if (x != "")
        {
            push_back(x);
        }
        else
        {
            break;
        }
    }
}

/**************************************************************************************
	Return the first value of the stack.
***************************************************************************************/
template <class T>
T Stack<T>::get_top()
{
    return top->value;
}

/**************************************************************************************
	Print the stack using recursion to keep the rules of stack in tact.
***************************************************************************************/
template <class T>
void Stack<T>::print()
{
    if (!isEmpty())
    {
        T x = this->get_top();
        std::cout << x << std::endl;
        this->pop_top();
        print();
        this->push_back(x);
    }
}

/**************************************************************************************
	Print the stack in reverse using recursion to keep the rules of stack in tact.
***************************************************************************************/
template <class T>
void Stack<T>::print_reverse()
{
    if (!isEmpty())
    {
        T x = this->get_top();
        this->pop_top();
        print_reverse();
        std::cout << x << std::endl;
        this->push_back(x);
    }
}

/**************************************************************************************
	Remove the stack from memory by looping and deleting all values until the stack
    is empty. Finally delete the pointer as well.
***************************************************************************************/
template <class T>
Stack<T>::~Stack()
{
    while (!this->isEmpty())
    {
        this->pop_top();
    }

    delete top;
}