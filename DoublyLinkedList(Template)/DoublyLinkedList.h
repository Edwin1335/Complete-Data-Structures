#pragma once
#include <iostream>
using namespace std;

/*******************************************************************************************************************
	Doubly Linked List is a type of data structure that connects data togther using pointers just like Single Linked
	List. Aside fro havin a "Head" pointer, Doubly Linked List also has a "Tail" pointer that point to the end of a 
	list. The Nodes that connects them also have a small variation. The Node will point to the next node as well as 
	the previous. Some funtions will be easier to write and the list is easier to track, but comes with the 
	disadvantage of writing more code to keep tract of the tail as well. In my list i will also keep track of the 
	size of the list as i am adding and deleting from the funtion. It is not metioned in the funtion comments but 
	keep that in mind. 
*******************************************************************************************************************/

template <class T>
struct Node
{
	Node<T>* next;
	Node<T>* prev;
	T data;

/****************************************************************************************************************
	As stated before, Doubly Linked List must have a node that points forwards and backrds, hence the prev and
	next pointers. Also including the data it will contain.
*****************************************************************************************************************/
};


template <class T>
class DoublyLinkedList
{
public:
	DoublyLinkedList();
	/**************************************************************************************************
		The Doubly Linked List constructor will intialize the tail pointer and head pointer to null
		to begin the memory allocation for the comming list.
	**************************************************************************************************/

	~DoublyLinkedList();
	/***************************************************************************************************
		The destructor will delete everything in the list to save mermy allocation.
	****************************************************************************************************/

	void insert_beg(T);
	/***************************************************************************************************
		The insert begin funtion will first create anode with the data passed in as the parameter, the 
		next and prev pointer will be set to NULL for the mean time, until a place for the node is found. 
		Then it will check if list is empty, if so intialize the head pointer and tail pointer to point 
		to set node. Else, set the new node to point to the head and head-> prev to point to the new node.
		remember to update the head.
	****************************************************************************************************/

	void insert_end(T);
	/**************************************************************************************************
		The insert end funtion works just like the insert begin except for the part where the new node 
		will point to the head. In this case the tail will point to the new node and the newnode's prev
		pointer will point to the tail. Dont forget to update the tail.
	***************************************************************************************************/

	void del_end();
	void del_beg();
	/****************************************************************************************************
		del_beg and del_end are very simple function that will first check if the list is empty, else 
		begin deleting. They will have many cases to check so keep that in mind.
	****************************************************************************************************/

	bool isEmpty();
	// Check if its empty

	bool search(T);
	// search for a specific data in the list

	int size();
	// return the size of the list
	void print();
	// print the list

private:
	Node<T>* head;
	Node<T>* tail;
	int itemCount;
};

template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
	head = NULL;
	tail = NULL;
	itemCount = 0;
}

template <class T>
bool DoublyLinkedList<T>::isEmpty()
{
	return (head == NULL);
}

template <class T>
int DoublyLinkedList<T>::size()
{
	return this->itemCount;
}

template <class T>
void DoublyLinkedList<T>::insert_beg(T x)
{
	// Creat a new node
	Node<T>* newNode = new Node<T>;
	newNode->data = x;
	newNode->next = NULL;
	newNode->prev = NULL;
	itemCount++;
	// if is empty intialize head an tail pointer, else insert beggining.
	if (isEmpty())
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		newNode->next = head;
		head->prev = newNode;
		head = newNode;
	}
}

template <class T>
void DoublyLinkedList<T>::insert_end(T x)
{
	// Create a new node
	Node<T>* newNode = new Node<T>;
	newNode->data = x;
	newNode->next = NULL;
	newNode->prev = NULL;
	itemCount++;
	// if is empty intialize head an tail pointer, else insert end.
	if (isEmpty())
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
}

template <class T>
void DoublyLinkedList<T>::del_beg()
{
	// Check if the list is empty. Cannot delete from empty list.
	if (isEmpty())
	{
		cout << "ERROR: Cannot delete from an empty list " << endl;
	}
	else
	{
		// Point to the node that will be deleted. If there is only one node, set head and tail to NULL
		// else move the head forwards and set et the prev pointer to NULL so we wont get BAD_ALLOC.
		Node<T>* current = head;
		if (head->next == NULL)
		{
			head = head->next;
			tail = tail->next;
			delete current;
			itemCount--;
		}
		else
		{
		head = head->next;
		head->prev = NULL;
		delete current;
		itemCount--;
		}
	}
}

template <class T>
void DoublyLinkedList<T>::del_end()
{
	// Check if the list is empty. Cannot delete from empty list.
	if (isEmpty())
	{
		cout << "ERROR: Cannot delete from an empty list " << endl;
	}
	else
	{
		// Point to the node that will be deleted. If there is only one node, set head and tail to NULL
		// else move the tail backawards and set et the next pointer to NULL so we wont get BAD_ALLOC.
		Node<T>* current = tail;
		if (tail->prev == NULL)
		{
			tail = tail->prev;
			head = head->prev;
			delete current;
			itemCount--;
		}
		else
		{
			tail = tail->prev;
			tail->next = NULL;
			delete current;
			itemCount--;
		}
	}
}

template <class T>
bool DoublyLinkedList<T>::search(T x)
{
	// Return false if list is empty.
	if (isEmpty())
	{
		return false;
	}
	else
	{
		// creat a new pointer to traverse
		Node<T>* current = head;
		// traverse until find, if find return false, no need for else statment.
		while (current != NULL)
		{
			if (current->data == x)
			{
				return true;
			}
			current = current->next;
		}
		// could not find node, therefore will return false.
		return false;
	}
}

template <class T>
void DoublyLinkedList<T>::print()
{
	// Cannot print empty list.
	if (isEmpty())
	{
		cout << "ERROR: List is empty." << endl;
	}
	else
	{
		// create node pointer for traversal.
		Node<T>* current = head;
		//traverse and print starting with head.
		while (current != NULL)
		{
			cout << current->data;
			if(current->next != NULL)
				cout << " <--> ";
			current = current->next;
		}
		// Finish with an end line command.
		cout << endl;
	}
}

template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
	// loop until tail and head point to NULL
	while (!isEmpty())
	{
		this->del_end();

	}
	// delete both head and tail for final storage 
	delete head;
	delete tail;
}