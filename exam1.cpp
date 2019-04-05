#include <vector>
#include <stack>
#include <iostream>

using namespace std;

class BinaryNode  //problem 2
{
public:
	int value;
	BinaryNode* left;
	BinaryNode* right;
};

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

class LinkedList { //problem 3
public:
	int value;
	LinkedList* next;
};


LinkedList* reverseLinkedList(LinkedList* root)
{
	stack<int> temp;
	LinkedList* tempList = root;
	LinkedList* temp2 = root;
	while (tempList != nullptr)
	{
		temp.push(tempList->value);
		tempList = tempList->next;
	}
	while (!temp.empty())
	{
		temp2->value = temp.top();
		temp.pop();
		temp2 = temp2->next;
	}

	return root;
}

vector<int> sortStack(stack<int> &some_stack) //problem 4
{
	stack<int> temp;
	vector<int> result;
	int min;
	while (!some_stack.empty())
	{
		min = some_stack.top();
		some_stack.pop();
		while (!temp.empty() && temp.top() > min)
		{
			some_stack.push(temp.top());
			temp.pop();
		}
		temp.push(min);
	}
	temp.push(min);
	while (!temp.empty())
	{
		result.push_back(temp.top());
		temp.pop();
	}
	return result;
}

class TreeNode //problem 5 ////////////////////////
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
 

//Problem 6 ///////////////////////
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
	//problem 2////////////////
	BinaryNode* root = new BinaryNode{ 50 };
	root->left = new BinaryNode{ 10 };
	root->right = new BinaryNode{ 75 };
	root->left->left = new BinaryNode{ 5 };
	root->left->right = new BinaryNode{ 20 };
	root->right->left = new BinaryNode{ 60 };
	root->right->right = new BinaryNode{ 80 };

	LinkedList* a1 = new LinkedList{ 1 }; //problem 3///////////////////////
	LinkedList* a2 = new LinkedList{ 2 };
	LinkedList* a3 = new LinkedList{ 3 };
	LinkedList* a4 = new LinkedList{ 4 };

	a1->value = 1;
	a1->next = nullptr;
	//cout << a1->value;
	a2->value = 2;
	a2->next = a1;
	//cout << a2->value;
	a3->value = 3;
	a3->next = a2;
	//cout << a3->value;
	a4->value = 4;
	a4->next = a3;
	//cout << a4->value;

	LinkedList* a5 = reverseLinkedList(a4);
	//cout << a5->value << " ";
	while (a5 != nullptr)
	{
		cout << a5->value << " ";
		a5 = a5->next;
	}


	//problem 4 stuff //////////////////////////////
	vector<int> r;
	stack<int> p;
	p.push(25);
	p.push(75);
	p.push(6);
	p.push(7);
	p.push(120);
	p.push(100);
	p.push(5);

	r = sortStack(p);
	for (auto i : r)
	{
		cout << i << " ";
	}

	TreeNode* Tree = new TreeNode{ 50 };  //problem 5 ////////////////
	Tree->left = new TreeNode{ 10 };
	Tree->right = new TreeNode{ 75 };
	Tree->left->left = new TreeNode{ 5 };
	Tree->left->right = new TreeNode{ 20 };
	Tree->right->left = new TreeNode{ 60 };
	Tree->right->right = new TreeNode{ 80 };
	
	bool q = searchTree(Tree, 22); 
	cout << boolalpha << q << endl;
	q = searchTree(Tree, 11);
	cout << boolalpha << q << endl;
	q = searchTree(Tree, 100);
	cout << boolalpha << q << endl;
	q = searchTree(Tree, 5);
	cout << boolalpha << q << endl;


	TreeNode* Treeroot = new TreeNode{ 4 };  //Problem 6//////////////////////////////
	Treeroot->left = new TreeNode{ 2 };
	Treeroot->right = new TreeNode{ 6 };
	Treeroot->left->left = new TreeNode{ 1 };
	Treeroot->left->right = new TreeNode{ 3 };
	Treeroot->right->left = new TreeNode{ 5 };
	Treeroot->right->right = new TreeNode{ 7 };

	vector<int> in = InbstToVector(Treeroot);
	for (auto i : in)
	{
		cout << i << " ";
	}
	cout << endl;
	vector<int> pre = PrebstToVector(Treeroot);
	for (auto i : pre)
	{
		cout << i << " ";
	}
	cout << endl;
	vector<int> post = PostbstToVector(Treeroot);
	for (auto i : post)
	{
		cout << i << " ";
	}
	cout << endl;


	return 0;
}