#include "BTree.h"

BTree::BTree()
{
	isTall = true;
	root = NULL;
	rigth = NULL;
}

void BTree::setDegree(int d)
{
	degree = d;
}

bool BTree::searchNode(Node* node, int data)
{
	int loc = 0;
	while (loc < node->SIZE && data > node->data[loc]) {
		loc++;
	}
	if (data == node->data[loc] && loc < node->SIZE)
		return true;
	else
		return false;
}

void BTree::insert(int x)
{
	rigth = 0;
	isTall = false;
	insertPrivate(root, x);

	if (isTall)
	{
		Node* temp = new Node(degree);

		temp->SIZE = 1;
		temp->data[0] = x;
		temp->children[0] = root;
		temp->children[1] = rigth;
		root = temp;
	}
}

void BTree::insertPrivate(Node* cu,int& x)
{
	int i = 0;

	if (cu == NULL)
	{
		rigth = NULL;
		isTall = true;
	}
	else
	{
		if (!searchNode(cu, x))
		{
			if (x < cu->data[i])
			{
				insertPrivate(cu->children[i], x);
			}
			else if (x > cu->data[cu->SIZE - 1])
			{
				i = cu->SIZE;
				insertPrivate(cu->children[i], x);
			}
			else {
				for (i = 0; i < cu->SIZE - 1; i++)
				{
					if (cu->data[i] < x && x < cu->data[i + 1])
					{
						insertPrivate(cu->children[i + 1], x);
						i = i + 1;
						break;
					}

				}
			}
			if (isTall == true)
			{
				if (cu->SIZE < degree - 1)
				{
					makeInsertion(cu, x, i);
					isTall = false;
				}
				else
				{
					splitNodes(cu, x, i);
				}
			}
		}
	}

	cout << "Edwin " << degree << endl;
}

void BTree::makeInsertion(Node* current, int& data, int& positon)
{
	int i;
	for (i=current->SIZE; i > positon; i--)
	{
		current->data[i] = current->data[i - 1];
		current->children[i + 1] = current->children[i];
	}
	current->data[i] = data;
	current->children[i + 1] = this->rigth;
	current->SIZE++;
}

void BTree::splitNodes(Node* current, int& x, int pos)
{
	Node* rightNode = new Node(degree);
	int middle = (degree - 1) / 2;

	if (pos <= middle)
	{
		int index = 0;
		int i = middle;
		while (i < degree - 1)
		{
			rightNode->data[index] = current->data[i];
			rightNode->children[index + 1] = current->children[i + 1];
			index++;
			i++;
		}
		current->SIZE = middle;
		makeInsertion(current, x, pos);
		(current->SIZE)--;

		x = current->data[current->SIZE];
		rightNode->SIZE = index;
		rightNode->children[0] = current->children[current->SIZE + 1];
	}
	else
	{
		int i = middle + 1;
		int index = 0;
		while (i < degree - 1)
		{
			rightNode->data[index] = current->data[i];
			rightNode->children[index + 1] = current->children[i + 1];
			index++;
			i++;
		}
		current->SIZE = middle;
		rightNode->SIZE = index;
		makeInsertion(rightNode, x, pos - middle - 1);
		x = current->data[middle];
		rightNode->children[0] = current->children[current->SIZE + 1];
	}
	rigth = rightNode;
}

void BTree::printInOrder(ofstream& output)
{
	this->printInOrderPrivate(root, output);
	output << endl;
}

void BTree::printInOrderPrivate(Node* current, ofstream& output)
{
	if (current != NULL)
	{
		printInOrderPrivate(current->children[0], output);
		for (int i = 0; i < current->SIZE; i++)
		{
			output << current->data[i] << " ";
			printInOrderPrivate(current->children[i + 1], output);
		}
	}
}

void BTree::printNUmberOfLevels(ofstream& output, int level)
{
	bool levelExist = false;
	printTheLevelPrivate(root, level, levelExist, 1, output);
	if (levelExist == false)
	{
		output << "empty";
	}
	output << endl;
}

void BTree::printTheLevelPrivate(Node* current, int level, bool& levelExist, int currentLevel, ofstream& output)
{
	if (current == 0)
		return;
	else if (currentLevel == level)
	{
		for (int i = 0; i < current->SIZE; i++)
			output << current->data[i] << " ";
		levelExist = true;
	}
	else
		for (int i = 0; i < current->SIZE + 1; i++)
			printTheLevelPrivate(current->children[i], level, levelExist, currentLevel + 1, output);
}