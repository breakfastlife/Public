#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "stringSplitter.h"


using namespace std;


int main()
{
	vector<string> hieght;
	string rgb;
	ifstream _bunny_stream{ "bunny.ppm" };
	while (_bunny_stream.good() == true)
	{
		_bunny_stream >> rgb;
		hieght.push_back(rgb);
		int i = 4;
		cout << hieght[i];
		i++;
	}

	return 0;
}