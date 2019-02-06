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

public:
	//RGB();
	RGB(int option, string file_in, string file_out);
	//RGB();
	//~RGB();
	const string getRed() const;
	const string getBlue() const;
	const string getGreen() const;
	void setRed(int color);
	void setBlue(int color);
	void setGreen(int color);
};

RGB::RGB(int option, string file_in, string file_out)
{
	setRed(0);
	setBlue(0);
	setGreen(0);
	int h(0);
	vector<string> ppm_vec = readFile(file_in);
	vector<string> new_vec, vec_o;


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
		h = (rand()% 20 + 1) - 10;
		for (int i = 3; i < ppm_vec.size(); i++)
		{
			new_vec = StringSplitter::split(ppm_vec[i], " ");
			for (int i = 0; i < new_vec.size() -1; i += 3)
			{
				if (stoi(new_vec[i]) + h > 0)
					setRed(255 - stoi(new_vec[i]));
				if (stoi(new_vec[i]) + h <= 0)
					setRed(0);
				new_vec[i] = getRed();
			}
			for (int i = 1; i < new_vec.size(); i += 3)
			{
				if (stoi(new_vec[i]) + h > 0)
					setGreen(255 - stoi(new_vec[i]));
				if (stoi(new_vec[i]) + h <= 0)
					setGreen(0);
				new_vec[i] = getGreen();
			}
			for (int i = 2; i < new_vec.size(); i += 3)
			{
				if(stoi(new_vec[i]) + h > 0)
					setBlue(255 - stoi(new_vec[i]));
				if (stoi(new_vec[i]) + h <= 0)
					setBlue(0);
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
		if (stoi(getRed()) > 255 / 2)
			setRed(255);
		if (stoi(getRed()) <= 255 / 2)
			setRed(0);
		if (stoi(getBlue()) > 255 / 2)
			setBlue(255);
		if (stoi(getBlue()) <= 255 / 2)
			setBlue(0);
		if (stoi(getGreen()) > 255 / 2)
			setGreen(255);
		if (stoi(getGreen()) <= 255 / 2)
			setGreen(0);
		break;
	case 9:
		//grayscale
		int k = ((stoi(getRed()) + stoi(getBlue()) + stoi(getGreen())) / 3);
		setRed(k);
		setBlue(k);
		setGreen(k);
		break;
	//case 10:
		//Flip Horizontally

	}
	

	stream.close();
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
