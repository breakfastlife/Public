#include "BinaryNode.h"
#include <iostream>
#include <string>

using namespace std;

bool find(BinaryNode<int>* start, const int& to_find)
{
	//base case 1: starts value matches to_find
	//base case 2: children are null
	//base case 3: if start is null

	if (start == nullptr)
		return false;
	if (start->getValue() == to_find)
		return true;

	//rcursive case: offload work to some subsegment of our children
	return find(start->getLeft(), to_find) || find(start->getRight(), to_find);
}

int size(BinaryNode<int>* start)
{
	//base case
	if (start == nullptr)
		return 0;
	return 1 + size(start->getLeft()) + size(start->getRight());
}

int height(BinaryNode<int>* start)
{
	if (start == nullptr)
		return -1;
	int left = 1 + height(start->getLeft());
	int right = 1 + height(start->getRight());
	int height = right;
	if (left > right)
		height = left;
	return height;

	/*int left = 1 + height(start->getLeft());
	int right = 1 + height(start->getRight());
	if (left > right)
		return left;
	else
		return right;*/ //My try (Which is totally usuable and works)
}

bool isFull(BinaryNode<int>* start)
{
	if (start == nullptr)
		return true;
	if (start->getLeft() != nullptr && start->getRight() == nullptr)
		return false;
	if (start->getLeft() == nullptr && start->getRight() != nullptr)
		return false;
	return isFull(start->getLeft()) && isFull(start->getRight());
}


int main()
{
	BinaryNode<int>* root = new BinaryNode<int>{ 5 };
	root->setLeft(new BinaryNode<int>{ 12 });
	root->setRight(new BinaryNode<int>{ 4 });
	root->getLeft()->setLeft(new BinaryNode<int> {11});
	root->getLeft()->setRight(new BinaryNode<int> {18});
	root->getRight()->setLeft(new BinaryNode<int> {10});
	root->getRight()->setRight(new BinaryNode<int> {7});
	root->getRight()->getLeft()->setLeft(new BinaryNode<int> {3});
	root->getRight()->getLeft()->setRight(new BinaryNode<int> {9});
	root->getRight()->getRight()->setRight(new BinaryNode<int> {15});
	root->getRight()->getRight()->getRight()->setLeft(new BinaryNode<int> {20});
	root->getRight()->getRight()->getRight()->setRight(new BinaryNode<int> {22});
	
	cout << height(root) << endl;

	return 0;
}