#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "readFile.h"
#include "Decoder.h"
#include "Encoder.h"
#include "StringSplitter.h"
using namespace std;

int main()
{


	//pixels[y][x]= <r,g,b>;
	cout << "Enter 1 to encode, 2 to decode, or 3 to exit: ";
	int user_input;
	cin >> user_input;
	do
	{
		if (user_input == 1 || user_input == 2)
		{
			cout << "Enter the file you wish to decode/encode: ";
			string file_input;
			cin >> file_input;
			if (user_input == 1)
				Encoder file_encode(file_input);
			if (user_input == 2)
				Decoder filer_decode(file_input);
		}
		cout << "Enter 1 to encode, 2 to decode, or 3 to exit: ";
		cin >> user_input;

	} while (user_input == 1 || user_input == 2);

	return 0;

}






void print(vector<string> const &input)
{
	for (int i = 0; i < input.size(); i++)
	{
		cout << input.at(i) << endl;
	}
}