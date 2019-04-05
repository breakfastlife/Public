#include <iostream>
#include "BinaryNode.h"

using namespace std;

void reverse(BinaryNode* node);

int main()
{
	BinaryNode* root = new BinaryNode{ 50 };
	root->left = new BinaryNode{ 10 };
	root->right = new BinaryNode{ 75 };
	root->left->left = new BinaryNode{ 5 };
	root->left->right = new BinaryNode{ 20 };
	root->right->left = new BinaryNode{ 60 };
	root->right->right = new BinaryNode{ 80 };
	/*root->right->left->left = new BinaryNode{ 3 };
	root->right->left->right = new BinaryNode{ 9 };
	root->right->right->right = new BinaryNode{ 15 };
	root->right->right->right->left = new BinaryNode{ 20 };
	root->right->right->right->right = new BinaryNode{ 22 };*/
	
	reverse(root);

}


void reverse(BinaryNode* node)
{
	if (node == nullptr)
		return;
	if (node->right != nullptr)
		reverse(node->right);
	cout << node->value << " ";
	if (node->left != nullptr)
		reverse(node->left);
}