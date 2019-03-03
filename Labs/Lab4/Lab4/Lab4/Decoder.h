#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include "StringSplitter.h"
#include "readFile.h"

using namespace std;


class Decoder
{
private:
	string message_text;
	int x_cor;
	int y_cor;
	vector<string> ppm_file;
	string header_1;
	string header_2_1;
	string header_2_2;
	string header_3;
public:
	Decoder(string file_in);
	~Decoder();
	int getX();
	int getY();
	string getMessage();
	void setX(int x);
	void setY(int y);
	void setMessage(string m);
};

Decoder::Decoder(string file_in)
{
	vector<string> temp, decoder;
	ppm_file = readFile(file_in);
	{ //header strip hidden because its ugly. smh.

		temp = StringSplitter::split(ppm_file[0], " ");
		header_1 = temp[0];
		temp = StringSplitter::split(ppm_file[1], " ");
		header_2_1 = temp[0];
		header_2_2 = temp[1];
		temp = StringSplitter::split(ppm_file[2], " ");
		header_3 = temp[0];
	}

	auto data = readFile(file_in);
	//vector<decltype(data)> data1 = data;
	auto dimensions = StringSplitter::split(data[1], " ");
	int width = stoi(dimensions[0]);
	int height = stoi(dimensions[1]);

	vector<vector<vector<int>>> pixels{};
	//recommended
	// vector<vector<pixel>> Pixels{}

	//initialize our vector
	pixels.resize(height);

	//finally process data
	vector<int> current_pixel{};
	vector<vector<int>> current_row{};

	cout << "decoding...\n";

	int row_counter = 0;
	for (int i = 3; i < data.size(); i++)
	{
		//cout << i << " ";
		string line = data[i];
		vector<string> pieces = StringSplitter::split(line, " ");
		for (string piece : pieces)
		{
			try
			{
				int color_value = stoi(piece);
				current_pixel.push_back(color_value);
				if (current_pixel.size() == 3)
				{
					//pixel complete
					// create pixel 2/ pixel p{current[0], r,g,b}
					current_row.push_back(current_pixel);
					current_pixel = vector<int>{};
				}
				if (current_row.size() == width)
				{
					pixels[row_counter] = current_row;
					current_row = vector<vector<int>>{};
					row_counter++;
					//cout << endl << row_counter << endl;
				}
			}
			catch (...)
			{

			}
		}
	}
	if (cin.peek() == '\n')
		cin.ignore();

	string file_out_input;
	cout << "Enter File output location: ";
	cin >> file_out_input;
	ofstream stream(file_out_input);
	/*for (auto thing : pixels)
	{
		for (auto doo_dad : thing)
		{
			for (auto yes : doo_dad)
			{
				stream << yes << " ";
			}
		}
		stream << endl;
	}*/

	setMessage(to_string(pixels[0][0][0]));
	stream << getMessage() << " ";

	setX(pixels[0][0][2]);
	setY(pixels[0][0][1]);
	
	
	while ((getX() != 0) && (getY() != 0))
	{
		setMessage(to_string(pixels[getY()][getX()][0]));
		stream << getMessage() << " ";
		//cout << endl << 1;
		int x_temp = getX();
		int y_temp = getY();
		setX(pixels[y_temp][x_temp][2]);
		setY(pixels[y_temp][x_temp][1]);
		//cout << endl << 2;
	}

	cout << endl << "The decoded message is stored in " << file_out_input << endl;

	system("Pause");
}


Decoder::~Decoder()
{
}

int Decoder::getX()
{
	return x_cor;
}
int Decoder::getY()
{
	return y_cor;
}
string Decoder::getMessage()
{
	return message_text;
}
void Decoder::setX(int x)
{
	x_cor = x;
}
void Decoder::setY(int y)
{
	y_cor = y;
}
void Decoder::setMessage(string m)
{
	message_text = m;
}