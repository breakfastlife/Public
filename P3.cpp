#include <iostream>
#include <stack>
using namespace std;

class LinkedList {
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
		temp2= temp2->next;
	}

	return root;
}


int main()
{
	LinkedList* a1 = new LinkedList{ 1 };
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




	return 0;
}