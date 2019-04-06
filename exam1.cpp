#include <vector>
#include <stack>
#include <string>
#include <iostream>

using namespace std;

int findNthSmallest(vector<int> numbers, int n) //problem 1 ////////////////
{
	if (n > numbers.size() || n < 1)
	{
		cout << "Not a valid input, too small or too much\n";
		exit(1);
	}
	int min, next = 0;
	min = numbers[0];
	for (auto i : numbers)
	{
		if (min < i)
			min = i;
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (auto j : numbers)
		{
			if (j > min)
			{
				next = j;
				break;
			}
		}
		for (auto k : numbers)
		{
			if (k > min && k < next)
				next = k;
			min = next;
		}
	}
}


class BinaryNode  //problem 2//////////////
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

class LinkedList { //problem 3/////////////////////
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
	stack<int> temp{};
	vector<int> result;
	int max;
	while (!some_stack.empty())
	{
		max = some_stack.top();
		some_stack.pop();
		while (!temp.empty() && temp.top() < max)
		{
			some_stack.push(temp.top());
			temp.pop();
		}
		temp.push(max);
	}
	//temp.push(max);
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
	if (node == nullptr) return false;
	if (node->value == key) return true;
	if (searchTree(node->left,key) || searchTree(node->right,key)) return true;
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

bool isAvl(TreeNode* node) //Problem 7 //////////////////////////
{
	if (node == nullptr)
		return true;
	int LH = isAvl(node->left);
	int RH = isAvl(node->right);
	if((LH == RH +1) || (LH == RH) || (LH == RH - 1))
		return true;
	else return false;
}

int getHeight(TreeNode* node) // problem 8 ///////////
{
	if (node == nullptr)
		return 0;
	int LH = getHeight(node->left) + 1;
	int RH = getHeight(node->right) + 1;
	if (RH > LH)
		LH = RH;
	return LH;
}

vector<int> merseSorted(vector<int> first, vector<int> second) // problem 9 //////////
{
	//cout << "hello";
	for (auto i : second)
	{
		//cout << "hello";
		for (int j = 0; j < first.size() - 2; j++)
		{
			//cout << first.size() << " ";
			if ((i > first[j]) && (i < first[j + 1]))
			{
				first.emplace(first.begin() + j+1, i);
			}
			if (j + 1 == first.size() - 1 && i > first[j + 1])
				first.emplace(first.begin() + j + 1, i);
		}

	}
	//cout << "hello";
	return first;
}

void isBalanced(string insert)  //problem 10 ////////
{

}

int main()
{
	//prblem 1 //////////////////////
	vector<int> num = { 11,3,4,76,1048,74,2754,885,85 };
	int a = findNthSmallest(num, 3);
	cout << a << " ";
	a = findNthSmallest(num, 2);
	cout << a << " ";
	//a = findNthSmallest(num, 13);  //uncomment to get the exit error
	//cout << a << " ";
	a = findNthSmallest(num, 5);
	cout << a << " ";




	//problem 2////////////////
	BinaryNode* root = new BinaryNode{ 50 };
	root->left = new BinaryNode{ 10 };
	root->right = new BinaryNode{ 75 };
	root->left->left = new BinaryNode{ 5 };
	root->left->right = new BinaryNode{ 20 };
	root->right->left = new BinaryNode{ 60 };
	root->right->right = new BinaryNode{ 80 };

	reverse(root);
	cout << endl;

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
	cout << endl;


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
	cout << endl;

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
	q = searchTree(Tree, 10);
	cout << boolalpha << q << endl;
	q = searchTree(Tree, 5);
	cout << boolalpha << q << endl;
	cout << endl;


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

	//Problem 7

	cout << boolalpha << isAvl(Treeroot) << endl;

	//Problem 8

	cout << getHeight(Treeroot) << endl;


	//problem 9
	vector<int> fir = { 1, 3, 5, 14, 16, 22 };
	vector<int> sec = { 6, 7, 8, 12, 13, 15, };
	vector<int> c = {};
	
	c = merseSorted(fir, sec);
	//cout << "hello";
	for (auto i : c)
	{
		cout << i << " ";
	}

	return 0;
}