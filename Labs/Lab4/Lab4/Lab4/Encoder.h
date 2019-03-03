#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <random>
#include "time.h"
#include "StringSplitter.h"
#include "readFile.h"

using namespace std;


class Encoder
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
	Encoder(string file_in);
	~Encoder();
	int getX();
	int getY();
	string getMessage();
	void setX(int x);
	void setY(int y);
	void setMessage(string m);
};

Encoder::Encoder(string file_in)
{
	vector<string> temp, Encoder;
	ppm_file = readFile(file_in);

	string file_user_location;
	cout << "Enter the location where you wish to store the new encoded message (ppm files only): ";
	cin >> file_user_location;
	ofstream stream(file_user_location);

	cout << "Processing...\n";
	
	
	{ //header strip hidden because its ugly. smh.

		temp = StringSplitter::split(ppm_file[0], " ");
		stream << temp[0] << endl;
		temp = StringSplitter::split(ppm_file[1], " ");
		stream << temp[0] << " " << temp[1] << endl;
		temp = StringSplitter::split(ppm_file[2], " ");
		stream << temp[0] << endl;
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

	srand(time(NULL));
	int x_ran = rand() % width +1;
	int y_ran = rand() % width + 1;
	string mess;
	cout << "enter mesasge to encode: ";
	getline(cin, mess);
	cout << "Encoding...\n";
	
	vector<int> secret_mes = {};
	for (auto hi : mess)
	{
		char x = hi;
		secret_mes.push_back((int)x);
	}
	//vector<int> secret_mes = { 83, 116, 101, 118, 101, 32, 73, 114, 119, 105, 110, 32, 119, 97, 115, 32, 97, 32, 108, 101, 103, 101, 110, 100, 33 };
	
	pixels[0][0][0] = secret_mes[0];
	pixels[0][0][1] = y_ran;
	pixels[0][0][2] = x_ran;
	setY(y_ran);
	setX(x_ran);

	int i = 1;
	while (i < secret_mes.size() - 1)
	{
		pixels[getY()][getX()][0] = secret_mes[i];
		//setY(pixels[y_temp][x_temp][1]);
		x_ran = rand() % width + 1;
		y_ran = rand() % width + 1;
		pixels[getY()][getX()][1] = y_ran; // y
		pixels[getY()][getX()][2] = x_ran; // x
		setX(x_ran);
		setY(y_ran);
		i++;
	}

	pixels[getY()][getX()][0] = secret_mes[secret_mes.size() - 1];
	pixels[getY()][getX()][1] = 0; 
	pixels[getY()][getX()][2] = 0;

	for (auto row : pixels)
	{
		for (auto col : row)
			for (auto pix : col)
			{
				stream << pix << " ";
			}
		stream << endl;
	}
	cout << endl << "Your encoded message is stored in: " << file_user_location << endl;
	//system("Pause");
}


Encoder::~Encoder()
{
}

int Encoder::getX()
{
	return x_cor;
}
int Encoder::getY()
{
	return y_cor;
}
string Encoder::getMessage()
{
	return message_text;
}
void Encoder::setX(int x)
{
	x_cor = x;
}
void Encoder::setY(int y)
{
	y_cor = y;
}
void Encoder::setMessage(string m)
{
	message_text = m;
}