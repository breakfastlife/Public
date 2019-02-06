#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "stringSplitter.h"
#include "RGB.h"


using namespace std;
//vector<string> readFile(ifstream& some_file);
//vector<string> readFile(ifstream&& some_file);
//vector<string> readFile(string file_name);

int main()
{
	vector<string> ppm_vec = readFile("bunny.ppm");
	vector<string> new_vec, vec_o;

	
	ofstream stream("bunny_modified.ppm");
	stream << "P3" << endl;
	stream << "400 273" << endl;
	stream << "255" << endl;

	/*for (int i = 3; i < ppm_vec.size(); i++)
	{
		new_vec = StringSplitter::split(ppm_vec[i], " ");
		for (int i = 1; i < new_vec.size(); i += 3)
		{
			new_vec[i] = "0";
		}

		for (auto row : new_vec)
		{
			stream << row << " ";
			cout << row << " ";
		}
		cout << endl;
		stream << endl;
	}
	stream.close();*/

	RGB bun(7, "bunny.ppm", "bunny_out.ppm");
	cout << "done...";
	system("pause");
	return 0;
}


