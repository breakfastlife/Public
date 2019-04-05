#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> sortStack(stack<int> &some_stack)
{
	stack<int> temp;
	vector<int> result;
	int min;
	while (!some_stack.empty())
	{
		min = some_stack.top();
		some_stack.pop();
		while(!temp.empty() && temp.top() > min)
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

int main()
{
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


	return 0;
}