#pragma once
#include <iostream>
#include <string>
using namespace std;

/***********************************************************************************************************************
	Single Linked List: This project "SingleLinkedList(Tempate)" is a program that will create a list of data
	like an array. The list can hold infinte amounts of data and is not required to know the size first hand
	like arrays. It is faster and more versatile than arrays. The term template means that in can hold any type of data.
	Integers, Double, Strings, Floats.. ect. It works by connecting a node from one memory location to a another node's
	memory location without necessarly being next to each other (like arrays). For us to use templates we must 
	use have all of our code inside the header file( Class decleration and class function delceration funtions).
***************************************************************************************************************************/

template <class T>
struct Node
{
	Node* next;
	T data;
};
/******************************************************************************************************
	A Node is a block of memory containing information. Any information can be inside a linked list
	but we must add a pinter to another node to continue adding more Nodes and connect them.
**********************************************************************************************************/

template <class T>
class SingleLinkedList
{
public:
	SingleLinkedList();
	/***********************************************************************
		This is the constructor for the Single Linked list class that will
		intialize the list by setting the head to NULL.
	************************************************************************/

	~SingleLinkedList();
	/********************************************************************************************
		The deconstructor will delete every element from the linked list to save space. The final
		result should have the head pointing to NULL or we can delete the head as well.
	*********************************************************************************************/

	bool isEmpty();
	/************************************************************************************
		This funtion will check wether the list is empty by returning of the head-> NULL.
	*************************************************************************************/

	void insert_end(T);
	/************************************************************************************************
		Insert_end will isnert the data passed int he parameter into the end of the list. For example
		insert_end(x): head-> 1-> 3-> 4-> x.
	*************************************************************************************************/

	void insert_Data_at_index(T, int);
	/************************************************************************************************
		The insert at funtion will insrt a data into a specific index location in the linked list,
		if it exist. For example:             (insert here)
		insert_Data_at_index(7, 2): head->   1->   7->   2->   3->   4.
	*************************************************************************************************/

	void insert_beg(T);
	/*****************************************************************************************************
		Insert_beg will insert the data passed in the paramter into the beggining of the list. For example
		insert_beg(x): head-> x-> 1-> 3-> 4.
	******************************************************************************************************/

	void del_beg();
	/***********************************************************************************
		The del_beg funtion will delete the begginign of the first element of the list.
	************************************************************************************/
	void del_end();
	/***************************************************************************************************
		The del_end is a funtion that every linked list must have and seems very obviuos, it will delete
		the last element of the list.
	******************************************************************************************************/
	bool search(T);
	/******************************************************************************************************
		The search funtions is a boolean funton that will check if the value passed by the paramtere exist 
		in the list. It will loop from the begining to the end until it reaches the value is lloking for 
		or reaches the end. 
	*******************************************************************************************************/

	void reverse();
	/*********************************************************************************************************
		The reverse funtion will do reverse the list(Duh). As always check if its empty (or has one node), 
		if it is dont do anything, becuase techniclaly it is already reversed.
	**********************************************************************************************************/

	void print();
	/***************************************************************************************************
		This print funtion will be seen in every class to display the what the class is doing and test
		whether it is doing it right.
	***************************************************************************************************/
	Node<T>* getHead();
	/***************************************************************************************************
		lol, this funtion will retunr the pointer to the head.
	****************************************************************************************************/

private:
	Node<T>* head;
	/************************************************************************************************
		Head is a pointer to a Node that will point to another Node. This head is to keep track of
		where the list is in the memory. The head will always point to the beggining of the list and
		will not be moved.
	***********************************************************************************************/
};



/*******************************************************************************************************
	The Single Linked List constructor will intialize the head pinter to nothing (NULL) so it can begin
	the insertion when needed and keep track of where the list begins.
********************************************************************************************************/
template <class T>
SingleLinkedList<T>::SingleLinkedList()
{
	this->head = NULL;
}

/********************************************************************************************************************
	The isEmpty funtion will check if the Head pointer is equal to NULL, meaning it is not pointing to any other
	Node, therefore no other node has been created. Also meaning that the list is empty. It is a boolean funtion
	that returns true if head is NULL or false otherwise.
*****************************************************************************************************************/
template <class T>
bool SingleLinkedList<T>::isEmpty()
{
	return (head == NULL);
}

/****************************************************************************************************************
	Insert_end is a basic funtion in every list. Most list will automatically insert towards the end anyways.
	The funtion must first create a node with the given information and then check whether the list is empty
	to be able to start the process. If the list is empty then set the head to point to the new node, else
	find the last node and let the last node point the new Node.
****************************************************************************************************************/
template <class T>
void SingleLinkedList<T>::insert_end(T x)
{
	Node<T>* newNode = new Node<T>;
	newNode->data = x;
	newNode->next = NULL;

	if (isEmpty())
	{
		head = newNode;
	}
	else
	{
		Node<T>* current = head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = newNode;
	}
}

/***********************************************************************************************************
	Insert_beg is a funtion that is not normally found in the Standard Template Libarary, but will
	be created here for practice purposes. Same as insert_end, it will check wether the funtion is empty.
	If its is set head equal to newNode. This time if the head is not empty we want to insert at the
	begining so we will move everything forwards and lets not forget to change the head back to the first
	element in the list.
**************************************************************************************************************/
template <class T>
void SingleLinkedList<T>::insert_beg(T x)
{
	Node<T>* newNode = new Node<T>;
	newNode->data = x;
	newNode->next = NULL;

	if (isEmpty())
	{
		this->head = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
}

/*******************************************************************************************************************
	Funtion requires the data that wants to be added and the index/position of the list to be inserted. If the index
	larger than the size of the list+1 then display error, index is too small, display error.
	Create new node to be inserted into the list. No need to check wether is empty or full because no matter 
	what the linked list status is, it will always accept new data. It will never be full because, unlike arrays,
	linked list can be infinite. 
********************************************************************************************************************/
template <class T>
void SingleLinkedList<T>::insert_Data_at_index(T x, int index)
{
	if (index < 0)
	{
		cout << "ERROR: Index must be greater than zero" << endl;
	}
	else
	{

		Node<T>* newNode = new Node<T>;
		newNode->next = NULL;
		newNode->data = x;

		// Insert at the first position if is empty and the index indicated is 0.
		if (isEmpty() && index == 0)
		{
			head = newNode;
		}
		else
		{
			Node<T>* temp = NULL;
			Node<T>* current = head;
			int counter = 0;

			while (current != NULL && counter != index)
			{
				temp = current;
				current = current->next;
				counter++;
			}

			if (current == head)
			{
				// check if the index is 0. Meaning the user whats to input at the begining.
				this->insert_beg(x);
			}
			else if (current == NULL && counter != index)
			{
				// Check to see if the index is bigger than the size of the list.
				cout << "ERROR: Index too larger" << endl;
			}
			else if (temp->next == NULL && counter == index)
			{
				// Check to see if the user wants to input at the very end
				this->insert_end(x);
			}
			else if (counter == index)
			{
				//We reached an index without going over or under.
				temp->next = newNode;
				newNode->next = current;
			}
		}
	}
}

/**************************************************************************************************************
	Unlike the adding a node to a linked list, we must check if the list is empty. When adding in the list,
	this wont matter, but when deleting in a list we must check wether there is at least something to delete in
	the fist place, therefore we must check if the list is empty. Next we will traverse through the list until we
	find the end. We must also keep track of what is behind the traversing node to bea ble tot set the pre-end 
	node->next to NULL and then delete the end node.
**************************************************************************************************************/
template <class T>
void SingleLinkedList<T>::del_end()
{
	if (isEmpty())
	{
		cout << "ERROR: Cannot delete from an empty lsit." << endl;
	}
	else
	{
		Node<T>* current = head;
		Node<T>* temp = NULL;
		while (current->next != NULL)
		{
			temp = current;
			current = current->next;
		}
		if (current == head)
		{
			head = NULL;
		}
		else
		{
			temp->next = NULL;
			delete current;
		}
	}
}

/*******************************************************************************************************************
	Similar to the del_end funtion we will check if the list is empty. If not, simply delete the begging Node and 
	dont foget to move the head pointer to head->next;
********************************************************************************************************************/
template <class T>
void SingleLinkedList<T>::del_beg()
{
	if (isEmpty())
	{
		cout << "ERROR: Cannot delete from an empty list." << endl;
	}
	else
	{
		Node<T>* current = head;
		head = head->next;
		delete current;
	}
}

/*********************************************************************************************************************
	The search function returns a booleans value and will check if the value passed in the parameter is in the list 
	by traversing through it. if is empty, obviously return false, else traverse it. While its traversing,if its found 
	return true else return false.
**********************************************************************************************************************/
template <class T>
bool SingleLinkedList<T>::search(T x)
{
	if (isEmpty())
	{
		return false;
	}
	else
	{
		Node<T>* current = head;
		while (current != NULL)
		{
			if (current->data == x)
			{
				return true;
			}
			current = current->next;
		}
		return false;
	}
}

template <class T>
void SingleLinkedList<T>::reverse()
{
	if (!isEmpty())
	{
		if (head->next != NULL)
		{
			Node<T>* current = head;
			Node<T>* prev = NULL;

			while (head->next != NULL)
			{
				current = head;
				head = head->next;
				current->next = prev;
				prev = current;
			}
			head->next = current;
		}
	}
}

template <class T>
Node<T>* SingleLinkedList<T>::getHead()
{
	return this->head;
}


/***************************************************************************************************************
	From previous funtions you should know how to traverse the list by now. This funtion will do the same but
	with and additional code to print the value of the node its currently on.
***************************************************************************************************************/

template <class T>
void SingleLinkedList<T>::print()
{
	if (isEmpty())
	{
		cout << "ERROR: List is empty." << endl;
	}
	else
	{
		Node<T>* current = head;
		while (current != NULL)
		{
			cout << current->data << "--> ";
			current = current->next;
		}
		cout << endl;
	}
}

/*****************************************************************************************************************
	Delete the entire list to save the memory. 
*******************************************************************************************************************/
template <class T>
SingleLinkedList<T>::~SingleLinkedList()
{
	while (!isEmpty())
	{
		this->del_beg();
	}
	delete head;
}
