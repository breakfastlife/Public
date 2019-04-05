#include <iostream>
#include <vector>

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

vector<int> InbstToVector(TreeNode* node) //inorder
{
	vector<int> inorder = {}, q = {};
	if (node == nullptr)
		return {};
	q = InbstToVector(node->left);
	for (auto a : q)
		inorder.push_back(a);
	inorder.push_back(node->value);
	q = InbstToVector(node->right);
	for (auto a : q)
		inorder.push_back(a);
	return inorder;
}
vector<int> PrebstToVector(TreeNode* node) //preorder
{
	vector<int> Preorder = {}, q = {};
	if (node == nullptr)
		return {};
	Preorder.push_back(node->value);
	q = PrebstToVector(node->left);
	for (auto a : q)
		Preorder.push_back(a);
	q = PrebstToVector(node->right);
	for (auto a : q)
		Preorder.push_back(a);
	return Preorder;
}
vector<int> PostbstToVector(TreeNode* node) //preorder
{
	vector<int> postorder = {}, q = {};
	if (node == nullptr)
		return {};
	q = PostbstToVector(node->left);
	for (auto a : q)
		postorder.push_back(a);
	q = PostbstToVector(node->right);
	for (auto a : q)
		postorder.push_back(a);
	postorder.push_back(node->value);
	return postorder;
}





int main()
{
	TreeNode* root = new TreeNode{ 4 };
	root->left = new TreeNode{ 2 };
	root->right = new TreeNode{ 6 };
	root->left->left = new TreeNode{ 1 };
	root->left->right = new TreeNode{ 3 };
	root->right->left = new TreeNode{ 5 };
	root->right->right = new TreeNode{ 7 };

	vector<int> in = InbstToVector(root);
	for (auto i : in)
	{
		cout << i << " ";
	}
	cout << endl;
	vector<int> pre = PrebstToVector(root);
	for (auto i : pre)
	{
		cout << i << " ";
	}
	cout << endl;
	vector<int> post = PostbstToVector(root);
	for (auto i : post)
	{
		cout << i << " ";
	}
	cout << endl;

	return 0;
}