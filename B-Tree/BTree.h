#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
//#include "ArgumentManager.h"
using namespace std;

/*
	In this asssignment i got help making the funtions with different TA who had close to the same code.
	Many of the funtions were also created using internets sites such as geeks for geeks and stack overflow.
	Also alot of the implementation came from the c++ programing book.
*/


class BTree
{
private:
	struct Node
	{
		int SIZE;
		int* data;
		Node** children;


		Node(int degree)
		{
			SIZE = 0;
			data = new int[degree - 1];
			children = new Node * [degree];
			for (int i = 0; i < degree; i++)
			{
				children[i] = NULL;
			}
		}
	};

	void insertPrivate(Node*,int&);
	void makeInsertion(Node*, int&, int&);
	void splitNodes(Node*,int&, int);
	void printTheLevelPrivate(Node*, int, bool&, int, ofstream&);

public:
	Node* root;
	Node* rigth;
	bool isTall;
	int degree;

	BTree();
	
	bool searchNode(Node*, int);
	void insert(int);
	void setDegree(int);
	void printInOrder(ofstream&);
	void printNUmberOfLevels(ofstream&, int);
	void printInOrderPrivate(Node*, ofstream&);
};

