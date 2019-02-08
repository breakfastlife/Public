#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>
#include "stringSplitter.h"

using namespace std;
vector<string> readFile(ifstream& some_file);
vector<string> readFile(ifstream&& some_file);
vector<string> readFile(string file_name);

class RGB {
private:
	string red;
	string green;
	string blue;
	int size;

public:
	//RGB();
	RGB(int option, string file_in, string file_out);
	//RGB();
	//~RGB();
	const string getRed() const;
	const string getBlue() const;
	const string getGreen() const;
	const int getSize() const;
	void setRed(int color);
	void setBlue(int color);
	void setGreen(int color);
	void setSize(int number);
};

RGB::RGB(int option, string file_in, string file_out)
{
	setRed(0);
	setBlue(0);
	setGreen(0);
	int h(0), num(0), len(0), width(0);
	vector<vector<string>> table;
	vector<string> ppm_vec = readFile(file_in);
	vector<string> new_vec, vec_o, temp_vec, flip_vec;


	ofstream stream(file_out);
	stream << "P3" << endl;
	stream << "300 188" << endl;
	stream << "255" << endl;
	switch (option)
	{
	case 1:
		//remove red
		for (int i = 3; i < ppm_vec.size(); i++)
		{
			new_vec = StringSplitter::split(ppm_vec[i], " ");
			for (int i = 0; i < new_vec.size() - 1; i += 3)
			{
				new_vec[i] = "0";
			}

			for (auto row : new_vec)
			{
				stream << row << " ";
			}
			stream << endl;
		}
		cout << "made it \n";
		break;
	case 2:
		//remove green
		for (int i = 3; i < ppm_vec.size(); i++)
		{
			new_vec = StringSplitter::split(ppm_vec[i], " ");
			for (int i = 1; i < new_vec.size(); i += 3)
			{
				new_vec[i] = getGreen();
			}

			for (auto row : new_vec)
			{
				stream << row << " ";
			}
			stream << endl;
		}
		
		break;
	case 3:
		//remove blue
		for (int i = 3; i < ppm_vec.size(); i++)
		{
			new_vec = StringSplitter::split(ppm_vec[i], " ");
			for (int i = 2; i < new_vec.size(); i += 3)
			{
				new_vec[i] = getBlue();
			}

			for (auto row : new_vec)
			{
				stream << row << " ";
			}
			stream << endl;
		}
		//stream.close();
		break;
	case 4:
		//negate Red
		for (int i = 3; i < ppm_vec.size(); i++)
		{
			new_vec = StringSplitter::split(ppm_vec[i], " ");
			for (int i = 0; i < new_vec.size() - 1; i += 3)
			{
				setRed(255 - stoi(new_vec[i]));
				new_vec[i] = getRed();
			}

			for (auto row : new_vec)
			{
				stream << row << " ";
			}
			stream << endl;
		}
		//stream.close();
		break;
	case 5:
		//negate green
		for (int i = 3; i < ppm_vec.size(); i++)
		{
			new_vec = StringSplitter::split(ppm_vec[i], " ");
			for (int i = 1; i < new_vec.size(); i += 3)
			{
				setGreen(255 - stoi(new_vec[i]));
				new_vec[i] = getGreen();
			}

			for (auto row : new_vec)
			{
				stream << row << " ";
			}
			stream << endl;
		}
		//stream.close();
		break;
	case 6:
		//negate Blue
		for (int i = 3; i < ppm_vec.size(); i++)
		{
			new_vec = StringSplitter::split(ppm_vec[i], " ");
			for (int i = 2; i < new_vec.size(); i += 3)
			{
				setBlue(255 - stoi(new_vec[i]));
				new_vec[i] = getBlue();
			}

			for (auto row : new_vec)
			{
				stream << row << " ";
			}
			stream << endl;
		}
		//stream.close();
		break;
	case 7:
		//random noise
		srand(time(NULL));
		h = ((rand()% 20 + 1) - 10);
		for (int i = 3; i < ppm_vec.size(); i++)
		{
			new_vec = StringSplitter::split(ppm_vec[i], " ");
			for (int i = 0; i < new_vec.size() -1; i += 3)
			{
				setRed((stoi(new_vec[i]) + h));
				new_vec[i] = getRed();
			}
			for (int i = 1; i < new_vec.size(); i += 3)
			{
				setGreen((stoi(new_vec[i]) + h));
				new_vec[i] = getGreen();
			}
			for (int i = 2; i < new_vec.size(); i += 3)
			{
				setBlue((stoi(new_vec[i]) + h));
				new_vec[i] = getBlue();
			}


			for (auto row : new_vec)
			{
				stream << row << " ";
			}
			stream << endl;
		}

		/*if(stoi(getBlue()) + h > 0)
			setBlue(stoi(getBlue()) + h);
		if (stoi(getBlue()) + h <= 0)
			setBlue(0);
		if (stoi(getGreen()) + h > 0)
			setGreen(stoi(getGreen()) + h);
		if (stoi(getGreen()) + h <= 0)
			setGreen(0);
		if (stoi(getRed()) + h > 0)
			setRed(stoi(getRed()) + h);
		if (stoi(getRed()) + h <= 0)
			setRed(0);*/

		break;
	case 8:
		//High Contrast
		for (int i = 3; i < ppm_vec.size(); i++)
		{
			new_vec = StringSplitter::split(ppm_vec[i], " ");
			for (int i = 0; i < new_vec.size() - 1; i += 3)
			{
				setRed(stoi(new_vec[i]));
				if (stoi(getRed()) > (255 / 2))
					setRed(255);
				if (stoi(getRed()) <= (255 / 2))
					setRed(0);
				new_vec[i] = getRed();
			}
			for (int i = 1; i < new_vec.size(); i += 3)
			{
				setGreen(stoi(new_vec[i]));
				if (stoi(getGreen()) > (255 / 2))
					setGreen(255);
				if (stoi(getGreen()) <= (255 / 2))
					setGreen(0);
				new_vec[i] = getGreen();
			}
			for (int i = 2; i < new_vec.size(); i += 3)
			{
				setBlue(stoi(new_vec[i]));
				if (stoi(getBlue()) > (255 / 2))
					setBlue(255);
				if (stoi(getBlue()) <= (255 / 2))
					setBlue(0);
				new_vec[i] = getBlue();
			}

			for (auto row : new_vec)
			{
				stream << row << " ";
			}
			stream << endl;
		}
		
		/*if (stoi(getBlue()) > 255 / 2)
			setBlue(255);
		if (stoi(getBlue()) <= 255 / 2)
			setBlue(0);
		if (stoi(getGreen()) > 255 / 2)
			setGreen(255);
		if (stoi(getGreen()) <= 255 / 2)
			setGreen(0);*/
		break;
	case 9:
		//grayscale
		for (int i = 3; i < ppm_vec.size(); i++)
		{
			new_vec = StringSplitter::split(ppm_vec[i], " ");
			for (int i = 0; i < new_vec.size() - 1; i += 3)
			{
				setRed(stoi(new_vec[i]));
				setGreen(stoi(new_vec[i + 1]));
				setBlue(stoi(new_vec[i + 2]));

				h = ((stoi(getRed()) + stoi(getBlue()) + stoi(getGreen())) / 3);

				setRed(h);
				setGreen(h);
				setBlue(h);

				new_vec[i] = getRed();
				new_vec[i+1] = getGreen();
				new_vec[i+2] = getBlue();
			}

			for (auto row : new_vec)
			{
				stream << row << " ";
			}
			stream << endl;
		}
		
		break;
	case 10:
		//Flip Horizontally
		temp_vec = StringSplitter::split(ppm_vec[1], " ");
		len = stoi(temp_vec[0]);
		width = stoi(temp_vec[1]);
		temp_vec = StringSplitter::split(ppm_vec[3], " ");
		for (int t = 0; t < width; t++)
		{
			for (int i = 3 + (t * 60); i < (((len * 3) / (temp_vec.size() - 1)) + (t * 60) + 3); i++)
			{
				new_vec = StringSplitter::split(ppm_vec[i], " ");

				for (int y = 0; y < new_vec.size(); y++)
				{
					vec_o.push_back(new_vec[y]);
				}
				//stream << endl;
			}
			//stream << endl;
			vec_o.push_back("\n");
			table.push_back(vec_o);
			vec_o.clear();
		}
		cout << "Processing table\n";
	
		for (auto row : table)
		{
			
			for (int w = 0; w < (row.size() / 2); w += 3)
			{
				//cout << row.size() << endl;
				swap(row[w], row[(row.size() - 3) - w]);
				swap(row[w + 1], row[(row.size() - 2) - w]);
				swap(row[w + 2], row[(row.size() - 1)- w]);
			}
			for (int q = 0; q < row.size(); q++)
			{
				stream << row[q] << " ";
			}
			stream << endl;
		}
		
		/*for (int r = 0; r < width; r++)
		{

			flip_vec = StringSplitter::split(vec_o[r], "\n");
			for (int e = 0; e < flip_vec.size()/2; e++)
			{
				swap(flip_vec[e], flip_vec[(flip_vec.size() - 1) - e]);
			}
			for (auto row : flip_vec)
			{
				stream << row << " ";
			}
			stream << endl;
		}*/

		break;
	case 11:
		//Flip Vertical
		for (int i = 3; i < ppm_vec.size(); i ++)
		{
			for (int p = 0; p < 60; p++)
			{
				new_vec = StringSplitter::split(ppm_vec[i], " ");
				//if (i < (ppm_vec.size() - 1))
					//temp_vec = StringSplitter::split(ppm_vec[(ppm_vec.size() - 1) - (i)], " ");
				//temp_vec = new_vec;
				/*for (int j = 0; j < new_vec.size(); j++)
				{
					setSize(j);
				}

				cout << getSize();*/

				/*for (int i = 0; i < (new_vec.size()); i++)
				{
					swap(new_vec[i], temp_vec[i]);
				}*/

				/*for (int i = 0; i < (getSize() / 2) + 1; i += 3)
				{
					swap(new_vec[i], new_vec[getSize() - i-2]);
				}
				cout << "1";
				for (int i = 1; i < (getSize() / 2) + 1; i += 3)
				{
					swap(new_vec[i], new_vec[getSize() - i-1]);
				}
				cout << "2";
				for (int i = 2; i < (getSize() / 2) + 1; i += 3)
				{
					swap(new_vec[i], new_vec[getSize() - i]);
				}*/


				for (auto row : new_vec)
				{
					stream << row << " ";
				}
				//stream << endl;
				/*for (auto row : temp_vec)
				{
					stream << row << " ";
				}
				stream << endl;*/
			}
			stream << endl;
		}
		/*for (int i = (ppm_vec.size()/2)+3; i < ppm_vec.size(); i++)
		{

			new_vec = StringSplitter::split(ppm_vec[i], " ");
			if (i < (ppm_vec.size() - 1))
				temp_vec = StringSplitter::split(ppm_vec[(ppm_vec.size() - 1) - (i)], " ");
			//temp_vec = new_vec;
			/*for (int j = 0; j < new_vec.size(); j++)
			{
				setSize(j);
			}

			cout << getSize();

			for (int i = 0; i < (new_vec.size()); i++)
			{
				//stream << "AHHH ... ";
				//temp_vec[i-2] = new_vec[i];
				//stream << "AHHH ... ";
				//temp_vec[i-1] = new_vec[i - 1];
				//stream << "AHHH ... ";
				//temp_vec[i] = new_vec[i - 2];
				swap(new_vec[i], temp_vec[i]);
				/*if (i < 8)
				{
					swap(new_vec[i - 1], new_vec[(new_vec.size() - 1) - (i - 1)]);
					swap(new_vec[i - 2], new_vec[(new_vec.size() - 1) - i]);
				}
			}*/

			/*for (int i = 0; i < (getSize() / 2) + 1; i += 3)
			{
				swap(new_vec[i], new_vec[getSize() - i-2]);
			}
			cout << "1";
			for (int i = 1; i < (getSize() / 2) + 1; i += 3)
			{
				swap(new_vec[i], new_vec[getSize() - i-1]);
			}
			cout << "2";
			for (int i = 2; i < (getSize() / 2) + 1; i += 3)
			{
				swap(new_vec[i], new_vec[getSize() - i]);
			}


			for (auto row : new_vec)
			{
				stream << row << " ";
			}
			stream << endl;
			/*for (auto row : temp_vec)
			{
				stream << row << " ";
			}
			stream << endl;
		}*/
		break;

	}
	

	//stream.close();
}

const string RGB::getRed() const
{
	return red;
}
const string RGB::getBlue() const
{
	return blue;
}
const string RGB::getGreen() const
{
	return green;
}
const int RGB::getSize() const
{
	return size;
}
void RGB::setRed(int color)
{
	red = to_string(color);
}
void RGB::setBlue(int color)
{
	blue = to_string(color);
}
void RGB::setGreen(int color)
{
	green = to_string(color);
}

void RGB::setSize(int number)
{
	size = number;
}


/*RGB::RGB(int red, int green, int blue)
{
	setRed(red);
	setGreen(green);
	setBlue(blue);
}*/


// ********* Read file stuff ****** //

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

template <typename t>
void swap(t& x, t& y)
{
	t temp = x;
	x = y;
	y = temp;
	return;
}

vector<string> header(vector<string> item)
{
	vector<string> vector_return;
	for (int i = 0; i < 3; i++)
	{
		vector_return[i] = item[i];
	}
	return vector_return;
}