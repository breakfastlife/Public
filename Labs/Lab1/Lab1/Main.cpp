#include <iostream>
#include "CsvParser.h"
using namespace std;


int main()
{
	cout << "Hello world!\n";
	DefaultState state{ nullptr };
	state.handle();

	return 0;
}