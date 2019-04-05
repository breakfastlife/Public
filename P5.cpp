#include <iostream>

using namespace std;

class TreeNode
{
public:
	int value;
	TreeNode *left = nullptr;
	TreeNode *right = nullptr;
	TreeNode(int v = 0)
	{
		value = v;
	}
};

bool searchTree(TreeNode* node, int key)
{
	if (node == nullptr)
		return false;
	if (node->value == key)
		return true;
	else
	{
		bool a = searchTree(node->left, key);
		bool b = searchTree(node->right, key);
		if (a == true || b == true)
			return true;
	}
	return false;
}



int main()
{
	TreeNode* root = new TreeNode{ 5 };
	root->left = new TreeNode{ 12 };
	root->right = new TreeNode{ 4 };
	root->left->left = new TreeNode{ 11 };
	root->left->right = new TreeNode{ 18 };
	root->right->left = new TreeNode{ 10 };
	root->right->right = new TreeNode{ 7 };
	root->right->left->left = new TreeNode{ 3 };
	root->right->left->right = new TreeNode{ 9 };
	root->right->right->right = new TreeNode{ 15 };
	root->right->right->right->left = new TreeNode{ 20 };
	root->right->right->right->right = new TreeNode{ 22 };

	bool q = searchTree(root, 22);
	cout << boolalpha << q << endl;
	q = searchTree(root, 11);
	cout << boolalpha << q << endl;
	q = searchTree(root, 100);
	cout << boolalpha << q << endl;
	q = searchTree(root, 5);
	cout << boolalpha << q << endl;

	return 0;
}