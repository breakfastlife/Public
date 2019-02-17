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
	vector<string> new_vec, vec_o, temp_vec;
	int len;
	ofstream stream("bunny_modified.ppm");
	for (int i = 0; i < 3; i++)
	{
		vec_o = StringSplitter::split(ppm_vec[i], " ");
		for (auto row : vec_o)
			stream << row << " ";
	}
	/*temp_vec = StringSplitter::split(ppm_vec[1], " ");
	len = stoi(temp_vec[0]);
	temp_vec = StringSplitter::split(ppm_vec[3], " ");
	cout << len << endl;
	cout << temp_vec.size() << endl;
	len = ((len * 3) / (temp_vec.size()-1));
	cout << len;
	*/
	

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

	RGB bun(14, "bunny2.ppm", "bunny_out.ppm");

	cout << "done..." << endl;
	//system("pause");
	return 0;
}


