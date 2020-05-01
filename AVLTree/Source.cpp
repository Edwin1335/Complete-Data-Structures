#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
public:
	int data = -1;
	node* left = nullptr;
	node* right = nullptr;
	int height = 1;
};

class AVL
{
private:
	node* root;
public:
	AVL();
	void makeEmpty(node* t);
	node* insert(int x, node* t);
	node* singleRightRotate(node*& t);
	node* singleLeftRotate(node*& t);
	node* doubleLeftRotate(node*& t);
	node* doubleRightRotate(node*& t);
	node* findMin(node* t);
	node* findMax(node* t);
	node* remove(int x, node* t);
	int height(node* t);
	int getBalance(node* t);
	void inorder(node* t);
	void display(node*, int);
	node* getRoot();
	void insert(int x) { root = insert(x, root); }
	void remove(int x) { root = remove(x, root); }
	void display() { display(root, 0); }
};

AVL::AVL()
{
	this->root = nullptr;
}

void AVL::makeEmpty(node* t)
{
	if (t == nullptr)
		return;

	makeEmpty(t->left);
	makeEmpty(t->right);

	delete t;
}

node* AVL::insert(int x, node* t)
{
	if (t == nullptr)
	{
		node* temp = new node;
		temp->data = x;
		temp->left = temp->right = nullptr;
		t = temp;
		if (root == nullptr)
			root = temp;
	}
	else if (x < t->data)
		t->left = insert(x, t->left);
	else if (x > t->data)
		t->right = insert(x, t->right);
	else
		return t; // no duplicates

	if (getBalance(t) > 1 && x < t->left->data)
		return singleRightRotate(t);
	if (getBalance(t) < -1 && x > t->right->data)
		return singleLeftRotate(t);
	if (getBalance(t) > 1 && x > t->left->data)
		return doubleLeftRotate(t);
	if (getBalance(t) < -1 && x < t->right->data)
		return doubleRightRotate(t);

	t->height = max(height(t->left), height(t->right)) + 1;

	return t;
}

node* AVL::singleRightRotate(node*& t)
{
	node* newroot = t->left;
	t->left = newroot->right;
	newroot->right = t;

	t->height = max(height(t->left), height(t->right)) + 1;

	return newroot;
}

node* AVL::singleLeftRotate(node*& t)
{
	node* newroot = t->right;
	t->right = newroot->left;
	newroot->left = t;

	t->height = max(height(t->left), height(t->right)) + 1;

	return newroot;
}

node* AVL::doubleLeftRotate(node*& t)
{
	t->left = singleLeftRotate(t->left);

	return singleRightRotate(t);
}

node* AVL::doubleRightRotate(node*& t)
{
	t->right = singleRightRotate(t->right);

	return singleLeftRotate(t);
}

node* AVL::findMin(node* t)
{
	if (t->left == nullptr)
		return t;
	return findMin(t->left);
}

node* AVL::findMax(node* t)
{
	if (t->right == nullptr)
		return t;
	return findMax(t->right);
}

node* AVL::remove(int x, node* t)
{
	if (t == nullptr)
		return t; // x not found
	else if (x < t->data)
		t->left = remove(x, t->left);
	else if (x > t->data)
		t->right = remove(x, t->right);
	else // x is found; delete
	{
		node* temp = new node;
		if (t->left == nullptr && t->right == nullptr) // leaf node
		{
			temp = t;
			t = nullptr;
			delete temp;
			return t;
		}
		else if (t->left == nullptr) // no left child
		{
			temp = t;
			t = t->right;
			delete temp;
		}
		else if (t->right == nullptr) // no right child
		{
			temp = t;
			t = t->left;
			delete temp;
		}
		else // two child nodes, replace with the predecessor
		{
			temp = findMin(t->right);
			t->data = temp->data;
			t->right = remove(temp->data, t->right);
		}
	}

	t->height = max(height(t->left), height(t->right)) + 1;

	if (getBalance(t) < -1 && getBalance(t->right) < 0)
		return singleRightRotate(t);
	if (getBalance(t) > 1 && getBalance(t->left) > 0)
		return singleLeftRotate(t);
	if (getBalance(t) > 1 && getBalance(t->left) <= 0)
		return doubleLeftRotate(t);
	if (getBalance(t) < -1 && getBalance(t->right) >= 0)
		return doubleRightRotate(t);
	return t;
}

int AVL::height(node* t)
{
	if (t == nullptr)
		return 0;
	return t->height;
}

int AVL::getBalance(node* t)
{
	if (t == nullptr)
		return 0;
	return height(t->left) - height(t->right);
}

void AVL::inorder(node* t)
{
	if (t != nullptr)
	{
		inorder(t->left);
		cout << t->data << " ";
		inorder(t->right);
	}
}

void AVL::display(node* t, int level = 0)
{
	if (t == nullptr)
		return;
	display(t->right, level + 1);
	cout << endl;
	for (int i = 0; i < level; i++)
		cout << "    ";
	cout << t->data << endl;
	display(t->left, level + 1);
}

node* AVL::getRoot()
{
	return this->root;
}
int main()
{
	AVL t;
	t.insert(20);
	t.insert(44);
	t.insert(55);
	t.insert(66);
	t.insert(11);
	t.insert(72);
	t.insert(34);
	t.insert(67);
	t.insert(45);
	t.insert(25);
	t.insert(10);
	t.insert(8);
	t.insert(5);
	t.remove(45);
	t.remove(67);
	t.inorder(t.getRoot());
	cout << endl << endl;
	t.display();
}
