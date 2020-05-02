#pragma once
#include <iostream>
#include <string>
using namespace std;

// Creating a node to store the Student's ID and Name along with a pointer to the next node
struct Node
{
	int ID;			
	string name;
	Node* bottom;
};

// A student class that will perform varius operations on the node
class Student 
{
private:
	Node* head;						// Will point to the top of the stack.
	int totalStudents;				// Will have the total amount of students.

public:
	Student();						// Constructor
	Student(int, string);			// Oveerloaded costructor for intialization

	bool isEmpty();					// Check if the stack is empty
	void push(int, string);	// Add Students to the stack 
	void pop();				// Delete students to the stack 
	void printStack();				// Print the Stack but pops all the students
	void reverseStack();			// Reverses the stack using two temporary Student objects
	void printRecursive();			// Prints the stack using recusion wihtout delteing all students
	void printReverse();			// Prints the stack in reverse order using recursion

	~Student();						// Desctructor to delete the stack and realease the memory

};

// Constructor, intializes the Head to NULL and total students to zero.
Student::Student()
{
	head = NULL;
	totalStudents = 0;
}

// Overloaded constructor, increments the 
Student::Student(int ID, string name)
{
	push(ID, name);
	totalStudents++;
}

// Check if the stack is empty
bool Student::isEmpty()
{
	if (totalStudents == 0)
		return true;
	else
		return false;
}

// Adds a student to the stack 
void Student::push(int ID, string name)
{
	Node* newNode = new Node;
	newNode->ID = ID;
	newNode->name = name;
	newNode->bottom = NULL;
	totalStudents++;

	if (isEmpty())
		head = newNode;
	else
	{
		newNode->bottom = head;
		head = newNode;
	}
}

// Deletes a student from the stack 
void Student::pop()
{
	if (!isEmpty())
	{
		Node* current = head->bottom;
		delete head;
		head = current;
		totalStudents--;
	}
	else
		cout << "Student roster is empty " << endl;
}

// Creates two temporary Stacks to be able to reverse the stack without violating the rules of
// a stack.
void Student::reverseStack()
{
	Student temp1;
	while (!isEmpty())
	{
		temp1.push(this->head->ID, this->head->name);
		this->pop();
	}

	Student temp2;
	while (!temp1.isEmpty())
	{
		temp2.push(temp1.head->ID, temp1.head->name);
		temp1.pop();
	}

	while (!temp2.isEmpty())
	{
		this->push(temp2.head->ID, temp2.head->name);
		temp2.pop();
	}
}

// This funtion will print the stack but will pop all the values and wont put them back 
// meaning after calling this funtion, the stack will be empty.
void Student::printStack()
{
	if (!isEmpty())
	{
		while (totalStudents != 0)
		{
			cout << "Student: " << head->name << endl;
			cout << "Id: " << head->ID << endl << endl;
			this->pop();
		}
	}
	else
		cout << "ERROR: Roster is empty" << endl;
}

// This funtion will print the correct way using recursion
void Student::printRecursive()
{
	if (totalStudents != 0)
	{
		int ID = head->ID;
		string name = head->name;
		this->pop();

		cout << "Student: " << name << endl;
		cout << "ID: " << ID << endl;

		printRecursive();

		this->push(ID, name);
	}
}

// Same as previous funtion but in reverse, will only print in reverse, but not change
// the position of the values.
void Student::printReverse()
{
	if (totalStudents != 0)
	{
		int ID = head->ID;
		string name = head->name;
		this->pop();
		printReverse();

		cout << "Student: " << name << endl;
		cout << "ID: " << ID << endl;

		this->push(ID, name);
	}
}

// Deconstructor.
Student::~Student()
{
	while (head != NULL)
	{
		this->pop();
	}
	delete head;
}

