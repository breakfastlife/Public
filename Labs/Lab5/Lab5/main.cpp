#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include "stringSplitter.h"
using namespace std;



int main()
{
	cout << "*** Postfix Evaluator ***\n";
	//define new stack;
	stack<int> numbers{};

	//add 5 numbers to the stack
	/*for (int i = 0; i < 5; i++)
	{
		numbers.push(i);
	}*/

	string user_input;
	do
	{
		string expression;
		cout << "Enter an expression to evaluate: ";
		getline(cin, expression);

		vector<string> yes = {};

		yes = StringSplitter::split(expression, " ");

		int result;
		for (auto exp : yes)
		{
			if (exp == "-" || exp == "/" || exp == "*" || exp == "+")
			{
				if (numbers.size() == 0)
				{
					cout << "Unexpected operation encountered, exiting...\n";
					exit(1);
				}
				int top = numbers.top();
				numbers.pop();
				if (numbers.size() == 0)
				{
					cout << "Unexpected operation encountered, exiting...\n";
					exit(1);
				}
				int bottom = numbers.top();
				numbers.pop();
				if (exp == "-")
					result = bottom - top;
				if (exp == "+")
					result = bottom + top;
				if (exp == "/")
					result = bottom / top;
				if (exp == "*")
					result = bottom * top;
				numbers.push(result);
			}
			else
			{
				numbers.push(stoi(exp));
			}
		}
		if (numbers.size() > 1)
		{
			cout << "Unexpected operation encountered, exiting...\n";
			exit(1);
		}
		cout << "Result: " << result << endl;

		numbers = {};


		cout << "Continue (Y/N)?: ";
		getline(cin, user_input);
	} while (user_input == "Y" || user_input == "y");


	return 0;
}