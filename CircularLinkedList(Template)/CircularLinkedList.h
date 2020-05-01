#pragma once
#include <iostream>
#include <string>
/****************************************************************************************************************
	Circular Linked List is a data structure that linearly inserts, deletes and searches for data. The structure
	uses nodes that are able to connect to each other using pointers more Node pointers. Each node has a specific
	data saved in them. To be able to traverse it we need a a way to keep track of where we are so we must include
	a head pointer and in addition we will also point to the end of the lost to make insertion more and tracking 
	more easy.
****************************************************************************************************************/

//Node declaration
template <class T>
struct Node
{
	Node<T>* next;
	T data;
};

// Circular List class declaration as template for versatility
template <class T>
class CircularList
{
private:
	Node<T>* head;
	Node<T>* tail;

public:
	CircularList();
	~CircularList();
	void insert(T);
	void remove(T);
	void del_beg();
	void del_end();
	bool search(T);
	bool isEmpty();
	void print();

};

//Constructor to intialize the head and tail to NULL.
template <class T>
CircularList<T>::CircularList()
{
	head = NULL;
	tail = NULL;
}

// Check if list is empty
template <class T>
bool CircularList<T>::isEmpty()
{
	return (this->head == NULL);
}

// Insert funtion.
template <class T>
void CircularList<T>::insert(T x)
{
	// Must always create one. Cannot check if full beacause lists are infinte. 
	Node<T>* newNode = new Node<T>;
	newNode->data = x;
	newNode->next = NULL;

	// Must begin intializing if its empty.
	if (head == NULL)
	{
		this->head = newNode;
		this->tail = newNode;
		head->next = tail;
		tail->next = head;
	}
	else
	{
		// If somehting is in the list send it to the end.
		this->tail->next = newNode;
		tail = newNode;
		newNode->next = head;
	}
}

// Search funtion that return true if found and display message.
template <class T>
bool CircularList<T>::search(T x)
{
	// Must check if there is something in the list first .
	if (!isEmpty())
	{
		// Must traverse
		Node<T>* current = head;
		do
		{
			// Check every Node's data 
			if (current->data == x)
			{
				std::cout << "Item: " << x << " found " << std::endl;
				return true;
			}
			// Move to next position
			current = current->next;

		} while (current != head);

		// Was not found in non-empty list
		std::cout << "Item: " << x << " NOT found " << std::endl;
		return false;
	}
	//List is empty therefore, it must be false.
	std::cout << "Item: " << x << " NOT found " << std::endl;
	return false;
}


// Remove function that find and removes if and only if found.
template <class T>
void CircularList<T>::remove(T x)
{
	//Cannot delete from empty list
	if (!isEmpty())
	{

		// Must traverse to find data, create a temporary Node pointer.
		Node<T>* current = head;
		Node<T>* preCurrent = NULL;
		// Traverse. Jumpt out if, Data is found, is at the end, there is only one data.
		while (current->next != head && current->data != x)
		{
			preCurrent = current;
			current = current->next;
		}
		if (current->next == head && current->data != x)
		{
			// If current is at tail and no data is found (including tail's data), data was not found;
			std::cout << "ERROR:: Item was not found " << std::endl;
		}
		else if (current->next == head && current->data == x && preCurrent != NULL)
		{
			// Data was found at tail, tail is not head. Move tail to prev position and delete current. 
			tail = preCurrent;
			tail->next = head;
			delete current;
		}
		else if (current->data == x && preCurrent == NULL && head->next != head)
		{
			// Found at the beginning of the list && there is more than one element in the list.
			head = head->next;
			tail->next = head;
			delete current;
		}
		else if (current->next == head && current == head)
		{
			// There is only one element in the list
			head = NULL;
			tail = NULL;
			delete current;
		}
		else if(current != head && current != tail && current->data == x)
		{
			//Deleting from middle 
			preCurrent->next = current->next;
			delete current;
		}
	}

}

//Delete the first node from the beggining
template <class T>
void CircularList<T>::del_beg()
{
	if (!isEmpty())
	{
		Node<T>* current = head;
		if (head == tail)
		{
			head = NULL;
			tail = NULL;
			delete current;
		}
		else
		{
			head = head->next;
			tail->next = head;
			delete current;
		}
	}
}

// Delete the last node from the list 
template <class T>
void CircularList<T>::del_end()
{
	if (!isEmpty())
	{
		Node<T>* current = head;
		if (head == tail)
		{
			head = NULL;
			tail = NULL;
			delete current;
		}
		else
		{
			Node<T>* currentPrev = NULL;

			while (current->next != head)
			{
				currentPrev = current;
				current = current->next;
			}
			if (currentPrev == head)
			{
				tail = head;
				tail->next = head;
				head->next = tail;
				delete current;
			}
			else
			{
				tail = currentPrev;
				tail->next = head;
				delete current;
			}
		}
	}
}

// Print all data in the list.
template <class T>
void CircularList<T>::print()
{
	// Cant print if there is nothing there.
	if (!isEmpty())
	{
		// Temporary for traversal.
		Node<T>* current = head;
		do
		{
			std::cout << current->data << "--> ";
			current = current->next;

		} while (current != head);

		// Must print the head as well since its circular.
		std::cout << current->data << std::endl;
	}
}

//Empty the list and restore all memory allocated 
template <class T>
CircularList<T>::~CircularList()
{
	// While ther is mor than one element 
	while (head != tail)
	{
		// Begin deleting from the begining
		this->del_beg();
	}

	// Empty or not, we must delete the already made haed and tail.
	delete head;
	delete tail;
}