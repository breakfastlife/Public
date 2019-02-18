#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "stringSplitter.h"


using namespace std;

vector<string> readFile(ifstream& some_file);
vector<string> readFile(ifstream&& some_file);
vector<string> readFile(string file_name);
//void header_remover(vector<string> vec_out, vector<string> vec_in);

int main()
{
	string file_input, file_input_2, file_dest;
	cout << "Enter a PPM file to parse: ";
	cin >> file_input;
	cout << "Enter a PPM file to copy to parsing file: ";
	cin >> file_input_2;
	vector<string> target_file, key_file, key_colors, header;
	vector<string> ppm_vec = readFile(file_input);
	vector<string> vec_o = readFile(file_input_2);


	cout << endl << "Enter destination file: ";
	cin >> file_dest;
	ofstream stream(file_dest);
	for (int y = 0; y < 3; y++)
	{
		header = StringSplitter::split(ppm_vec[y], " ");
		for (auto head : header)
		{
			stream << head << " ";
		}
		stream << endl;
	}
	/*stream << header[0] << endl;
	stream << header[1] << endl;
	stream << header[2] << endl;*/
	
	key_file = StringSplitter::split(vec_o[3], " ");
	
	for (int i = 0; i < 3; i++)
	{
		key_colors.push_back(key_file[i]);
	}
	


	cout << "parsing..." << endl;

	for (int i = 3; i < ppm_vec.size(); i++)
	{
		target_file = StringSplitter::split(ppm_vec[i], " ");
		key_file = StringSplitter::split(vec_o[i], " ");
		
		for (int j = 0; j < target_file.size() - 1; j += 3)
		{
			if (key_file[j] != key_colors[0])
				target_file[j] = key_file[j];
			if (key_file[j + 1] != key_colors[1])
				target_file[j + 1] = key_file[j + 1];
			if (key_file[j + 2] != key_colors[2])
				target_file[j + 2] = key_file[j + 2];
		}

		for (auto row : target_file)
		{
			stream << row << " ";
			//cout << row << " ";
		}
		//cout << endl;
		stream << endl;
	}
	stream.close();

	cout << "Processing image complete..." << endl;
	return 0;
}

vector<string> readFile(ifstream& some_file)
{
	vector<string> result{};
	//is the file open?
	if (some_file.is_open() == true)
	{
		while (some_file.good() == true)
		{
			//two ways to grab data
			string data;
			//first_names >> data; //CIN style
			getline(some_file, data); //more robust method
			result.push_back(data);
		}
	}
	return result;
}

vector<string> readFile(ifstream&& some_file)
{
	ifstream& local_file = some_file;

	//auto is an automatically inferred variable type
	//in our case, vector<string>
	auto result = readFile(local_file);
	local_file.close();
	return result;
}

vector<string> readFile(string file_name)
{
	return readFile(ifstream{ file_name });
}

/*void header_remover(vector<string> vec_out, vector<string> vec_in)
{
	for (int k = 0; k < 3; k++)
	{
		vec_out = StringSplitter::split(vec_in[k], " ");
	}
}*/