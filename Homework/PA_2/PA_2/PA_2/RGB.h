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
	void remove_red(vector<string> file_vec, ofstream& s);
	void remove_green(vector<string> file_vec, ofstream& s);
	void remove_blue(vector<string> file_vec, ofstream& s);
	void negate_red(vector<string> file_vec, ofstream& s);
	void negate_green(vector<string> file_vec, ofstream& s);
	void negate_blue(vector<string> file_vec, ofstream& s);
	void random_noise(vector<string> file_vec, ofstream& s);
	void high_contrast(vector<string> file_vec, ofstream& s);
	void grayscale(vector<string> file_vec, ofstream& s);
	string average(string a, string b);
	string average(string a, string b, string c);
	string average(string a, string b, string c, string d);
	string average(string a, string b, string c, string d, string e);
};

RGB::RGB(int option, string file_in, string file_out)
{
	//Local variable set up
	setRed(0);
	setBlue(0);
	setGreen(0);
	int h(0), num(0), len(0), width(0), r(0), c(0);
	vector<vector<string>> table, table_flip;
	vector<string> ppm_vec = readFile(file_in);
	vector<string> new_vec, vec_o, temp_vec, flip_vec;


	//setting up the header for the files

	ofstream stream(file_out);
	/*stream << "P3" << endl;
	stream << "300 188" << endl;
	stream << "255" << endl;*/
	temp_vec = StringSplitter::split(ppm_vec[0], " ");
	stream << temp_vec[0] << endl;
	temp_vec = StringSplitter::split(ppm_vec[1], " ");
	if(option == 12)
		stream << temp_vec[1] << " " << temp_vec[0] << endl;
	else
		stream << temp_vec[0] << " " << temp_vec[1] << endl;
	len = stoi(temp_vec[0]);
	width = stoi(temp_vec[1]);
	temp_vec = StringSplitter::split(ppm_vec[2], " ");
	stream << temp_vec[0] << endl;

	temp_vec = StringSplitter::split(ppm_vec[3], " ");
	int pixel = temp_vec.size() / 3; // 3 comes from the RGB set up of a pixel
	int RGB_pixel = temp_vec.size() / pixel;
	//cout << pixel;


	switch (option)
	{
	case 1:
		//remove red
		remove_red(ppm_vec, stream);

		break;
	case 2:
		//remove green
		remove_green(ppm_vec, stream);

		break;
	case 3:
		//remove_blue
		remove_blue(ppm_vec, stream);
		break;
	case 4:
		//negate Red
		negate_red(ppm_vec, stream);
		break;
	case 5:
		//negate green
		negate_green(ppm_vec, stream);
		break;
	case 6:
		//negate Blue
		negate_blue(ppm_vec, stream);
		break;
	case 7:
		//random noise
		random_noise(ppm_vec, stream);
		break;
	case 8:
		//High Contrast
		
		high_contrast(ppm_vec, stream);
	
		break;
	case 9:
		//grayscale
		grayscale(ppm_vec, stream);

		break;
	case 10:
		//Flip Horizontally
		cout << "making the table\n";

		temp_vec = StringSplitter::split(ppm_vec[3], " ");
		for (int t = 0; t < width; t++)
		{
			int index = (3 + (t * len / pixel));
			int size = (((len * RGB_pixel) / (temp_vec.size() - 1)) + (t * len / pixel) + 3);
			
			 //t * len / pixel is how many pixel vectors per line needed
				//so the (t * len/pixel) component is for each individual line of len * 3
			//run the file through a splitter and store into a new vector then push the values of that vector 
			//into another vector but at length pixels long instead of 5 (pixel)
			//then move onto the next line of lenght long (the t values)

			for (int i = index; i < size; i++)
			{
				new_vec = StringSplitter::split(ppm_vec[i], " ");
				for (int y = 0; y < new_vec.size() - 1; y++)
					vec_o.push_back(new_vec[y]);
				//stream << endl;
			}
			//stream << endl;
			//cout << vec_o.size() << endl;
			//vec_o.push_back("\n");
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
				swap(row[w + 2], row[(row.size() - 1) - w]);
			}
			for (int q = 0; q < row.size(); q++)
			{
				stream << row[q] << " ";
			}
			stream << endl;
		}


		break;
	case 11:
		//Flip Vertical
		temp_vec = StringSplitter::split(ppm_vec[3], " ");
		for (int t = 0; t < width; t++)
		{
			int index = (3 + (t * len / pixel));
			int size = (((len * RGB_pixel) / (temp_vec.size() - 1)) + (t * len / pixel) + 3);
			//cout << pixel;
			 //t * len / pixel is how many pixel vectors per line needed
				//so the (t * len/pixel) component is for each individual line of len * 3
			//run the file through a splitter and store into a new vector then push the values of that vector 
			//into another vector but at length pixels long instead of 5 (pixel)
			//then move onto the next line of lenght long (the t values)

			for (int i = index; i < size; i++)
			{
				new_vec = StringSplitter::split(ppm_vec[i], " ");
				for (int y = 0; y < new_vec.size() - 1; y++)
					vec_o.push_back(new_vec[y]);
				//stream << endl;
			}
			//stream << endl;
			//cout << vec_o.size() << endl;
			//vec_o.push_back("\n");
			table.push_back(vec_o);
			vec_o.clear();
		}
		cout << "Processing table\n";
		for (int i = 0; i < width / 2; i++)
		{
			for (int j = 0; j < len * 3; j += 3)
			{
				swap(table[i][j], table[width - i - 1][j]);
				swap(table[i][j + 1], table[width - i - 1][j + 1]);
				swap(table[i][j + 2], table[width - i - 1][j + 2]);
			}
		}
		for (auto row : table)
		{
			for (auto col : row)
			{
				stream << col << " ";
			}
			stream << endl;
		}

		break;

	case 12: //Rotate 90 degrees
		cout << "Making table\n";
		for (int t = 0; t < width; t++)
		{

			int index = (3 + (t * len / pixel));
			int size = (((len * RGB_pixel) / (temp_vec.size() - 1)) + (t * len / pixel) + 3);
			//cout << pixel;
			 //t * len / pixel is how many pixel vectors per line needed
				//so the (t * len/pixel) component is for each individual line of len * 3
			//run the file through a splitter and store into a new vector then push the values of that vector 
			//into another vector but at length pixels long instead of 5 (pixel)
			//then move onto the next line of lenght long (the t values)

			for (int i = index; i < size; i++)
			{
				new_vec = StringSplitter::split(ppm_vec[i], " ");
				for (int y = 0; y < new_vec.size() - 1; y++)
					vec_o.push_back(new_vec[y]);
				//stream << endl;
			}
			//stream << endl;
			//cout << vec_o.size() << endl;
			//vec_o.push_back("\n");
			table.push_back(vec_o);
			vec_o.clear();
		}
		//cout << width << endl;
		cout << "Rotating the table\n";
		/*for (int r = 0; r < width; r++)
		{*/

		while ((len * 3 - r - 3) != 0)
		{
			if (c == width)
			{
				c = 0;
				r += 3;
			}
			//cout << r;
			flip_vec.push_back(table[width - c - 1][len * 3 - r - 3]);
			flip_vec.push_back(table[width - c - 1][len * 3 - r - 2]);
			flip_vec.push_back(table[width - c - 1][len * 3 - r - 1]);
			c++;
		}
		//flip_vec.push_back("\n");


		cout << "Transfering table to output file\n";
		/*for (int i = 0; i < width; i++)
		{
			for (int j = 0; j < (len * 3); j += 3)
			{
				swap(table[i][j], table[width - i - 1][len - j - 3]);
				swap(table[i][j + 1], table[width - i - 1][len - j - 2]);
				swap(table[i][j + 2], table[width - i - 1][len - j - 1]);
			}
		}*/
		for (auto row : flip_vec)
		{
			stream << row << " ";
		}

		break;
	case 13:
		//blur
		cout << "Making table\n";
		for (int t = 0; t < width; t++)
		{

			int index = (3 + (t * len / pixel));
			int size = (((len * RGB_pixel) / (temp_vec.size() - 1)) + (t * len / pixel) + 3);
			//cout << pixel;
			 //t * len / pixel is how many pixel vectors per line needed
				//so the (t * len/pixel) component is for each individual line of len * 3
			//run the file through a splitter and store into a new vector then push the values of that vector 
			//into another vector but at length pixels long instead of 5 (pixel)
			//then move onto the next line of lenght long (the t values)

			for (int i = index; i < size; i++)
			{
				new_vec = StringSplitter::split(ppm_vec[i], " ");
				for (int y = 0; y < new_vec.size() - 1; y++)
					vec_o.push_back(new_vec[y]);
				//stream << endl;
			}
			//stream << endl;
			//cout << vec_o.size() << endl;
			//vec_o.push_back("\n");
			table.push_back(vec_o);
			vec_o.clear();
		}
		while (r < width)
		{
			for (int c = 0; c < len * 3; c += 3)
			{
				//cout << c << " ";
				if (c == 0)
				{
					table[r][c] = average(table[r][c], table[r][c + 3]);
					table[r][c + 1] = average(table[r][c + 1], table[r][c + 4]);
					table[r][c + 2] = average(table[r][c + 1], table[r][c + 5]);
				}
				if (c == len * 3 - 3)
				{
					table[r][c] = average(table[r][c], table[r][c - 3]);
					table[r][c + 1] = average(table[r][c + 1], table[r][c - 2]);
					table[r][c + 2] = average(table[r][c + 1], table[r][c - 1]);
				}
				if (c != 0 && c != len * 3 - 3)
				{
					table[r][c] = average(table[r][c], table[r][c - 3], table[r][c + 3]);
					table[r][c + 1] = average(table[r][c + 1], table[r][c - 2], table[r][c + 4]);
					table[r][c + 2] = average(table[r][c + 2], table[r][c - 1], table[r][c + 5]);
				}
				//cout << endl << r << endl;
				if (r == 0)
				{
					table[r][c] = average(table[r][c], table[r + 1][c]);
					table[r][c + 1] = average(table[r][c + 1], table[r + 1][c + 1]);
					table[r][c + 2] = average(table[r][c + 2], table[r + 1][c + 2]);
				}
				if (r == width - 1)
				{
					table[r][c] = average(table[r][c], table[r - 1][c]);
					table[r][c + 1] = average(table[r][c + 1], table[r - 1][c + 1]);
					table[r][c + 2] = average(table[r][c + 2], table[r - 1][c + 2]);
				}
				if (r != 0 && r != width - 1)
				{
					table[r][c] = average(table[r][c], table[r + 1][c], table[r - 1][c]);
					table[r][c + 1] = average(table[r][c + 1], table[r + 1][c + 1], table[r - 1][c + 1]);
					table[r][c + 2] = average(table[r][c + 2], table[r + 1][c + 2], table[r - 1][c + 2]);
				}
			}
			r++;
		}
		for (auto row : table)
		{
			for (auto col : row)
			{
				stream << col << " ";
			}
			stream << endl;
		}
		break;
	case 14:
		//pixelate
		cout << "Making table\n";
		
		for (int t = 0; t < width; t++)
		{

			int index = (3 + (t * len / pixel));
			int size = (((len * RGB_pixel) / (temp_vec.size() - 1)) + (t * len / pixel) + 3);
			//cout << pixel;
			 //t * len / pixel is how many pixel vectors per line needed
				//so the (t * len/pixel) component is for each individual line of len * 3
			//run the file through a splitter and store into a new vector then push the values of that vector 
			//into another vector but at length pixels long instead of 5 (pixel)
			//then move onto the next line of lenght long (the t values)

			for (int i = index; i < size; i++)
			{
				new_vec = StringSplitter::split(ppm_vec[i], " ");
				for (int y = 0; y < new_vec.size() - 1; y++)
					vec_o.push_back(new_vec[y]);
				//stream << endl;
			}
			//stream << endl;
			//cout << vec_o.size() << endl;
			//vec_o.push_back("\n");
			table.push_back(vec_o);
			vec_o.clear();
		}
		
		table_flip = table;
		while (r < width - width%5) //total rows
		{
			for (int i = 0; i < table[1].size(); i += 3) //pixel to copy, changes by 15 to signifiy the 5 pixels 
			{
				for (int v = 0; v < 5; v++) //to change rows by 5
				{
					for (int z = 0; z < 3; z++) //indivicual pixel values
					{
						try
						{
							table[r + v][i + z] = table_flip[r][i + z];
						}
						catch (...)
						{
						}
					}
				}
					/*table[r][j] = table[r][i];
					table[r][j + 1] = table[r][i + 1];
					table[r][j + 2] = table[r][i + 2];
					table[r + 1][j] = table[r][i];
					table[r + 2][j] = table[r][i];
					table[r + 3][j] = table[r][i];
					table[r + 4][j] = table[r][i];*/
				
			}
			r += 5;
		}

		for (auto row : table)
		{
			for (auto col : row)
			{
				stream << col << " ";
			}
			stream << endl;
		}
		break;

	}






	//stream.close();
}

//vector<vector<int>> makeTable()
//{
//	vector<vector<int>> table;
//	table.push_back(vector<int>{});
//	int counter = 0;
//	int row = 0;
//	for (int i = 3; i < ppm_vec.size(); i++)
//	{
//		vector<string> pieces = StringSplitter::split(_ppm_in_file[i], " ");
//		for (auto piece : pieces)
//		{
//			if (piece != " ")
//			{
//				try
//				{
//					table[row].push_back(stoi(piece));
//					counter++;
//					if (counter == _width_in * 3)
//					{
//						counter = 0;
//						row++;
//						table.push_back(vector<int>{});
//					}
//				}
//				catch (...)
//				{
//				}
//			}
//		}
//	}
//	return table;
//}

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

string RGB::average(string a, string b)
{
	return to_string((stoi(a) + stoi(b)) / 2);
}

string RGB::average(string a, string b, string c)
{
	return to_string((stoi(a) + stoi(b) + stoi(c)) / 3);
}

string RGB::average(string a, string b, string c, string d)
{
	return to_string((stoi(a) + stoi(b) + stoi(c) + stoi(d)) / 4);
}

string RGB::average(string a, string b, string c, string d, string e)
{
	return to_string((stoi(a) + stoi(b) + stoi(c) + stoi(d) + stoi(e)) / 5);
}


// ********* Functions ************//

void RGB::remove_red(vector<string> file_vec, ofstream& s)
{
	for (int i = 3; i < file_vec.size(); i++)
	{
		vector<string> new_vec = StringSplitter::split(file_vec[i], " ");
		for (int i = 0; i < new_vec.size() - 1; i += 3)
		{
			new_vec[i] = "0";
		}

		for (auto row : new_vec)
		{
			s << row << " ";
		}
		s << endl;
	}
	cout << "made it \n";
}

void RGB::remove_green(vector<string> file_vec, ofstream& s)
{
	for (int i = 3; i < file_vec.size(); i++)
	{
		vector<string> new_vec = StringSplitter::split(file_vec[i], " ");
		for (int i = 1; i < new_vec.size(); i += 3)
		{
			new_vec[i] = getGreen();
		}

		for (auto row : new_vec)
		{
			s << row << " ";
		}
		s << endl;
	}
}

void RGB::remove_blue(vector<string> file_vec, ofstream& s)
{
	for (int i = 3; i < file_vec.size(); i++)
	{
		vector<string> new_vec = StringSplitter::split(file_vec[i], " ");
		for (int i = 2; i < new_vec.size(); i += 3)
		{
			new_vec[i] = getBlue();
		}

		for (auto row : new_vec)
		{
			s << row << " ";
		}
		s << endl;
	}
}

void RGB::negate_red(vector<string> file_vec, ofstream& s)
{
	for (int i = 3; i < file_vec.size(); i++)
	{
		vector<string> new_vec = StringSplitter::split(file_vec[i], " ");
		for (int i = 0; i < new_vec.size() - 1; i += 3)
		{
			setRed(255 - stoi(new_vec[i]));
			new_vec[i] = getRed();
		}

		for (auto row : new_vec)
		{
			s << row << " ";
		}
		s << endl;
	}
}

void RGB::negate_green(vector<string> file_vec, ofstream& s)
{
	for (int i = 3; i < file_vec.size(); i++)
	{
		vector<string> new_vec = StringSplitter::split(file_vec[i], " ");
		for (int i = 1; i < new_vec.size(); i += 3)
		{
			setGreen(255 - stoi(new_vec[i]));
			new_vec[i] = getGreen();
		}

		for (auto row : new_vec)
		{
			s << row << " ";
		}
		s << endl;
	}
}

void RGB::negate_blue(vector<string> file_vec, ofstream& s)
{
	for (int i = 3; i < file_vec.size(); i++)
	{
		vector<string> new_vec = StringSplitter::split(file_vec[i], " ");
		for (int i = 2; i < new_vec.size(); i += 3)
		{
			setBlue(255 - stoi(new_vec[i]));
			new_vec[i] = getBlue();
		}

		for (auto row : new_vec)
		{
			s << row << " ";
		}
		s << endl;
	}
}

void RGB::random_noise(vector<string> file_vec, ofstream& s)
{
	srand(time(NULL));
	int h = ((rand() % 20 + 1) - 10);
	for (int i = 3; i < file_vec.size(); i++)
	{
		vector<string> new_vec = StringSplitter::split(file_vec[i], " ");
		for (int i = 0; i < new_vec.size() - 1; i += 3)
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
			s << row << " ";
		}
		s << endl;
	}

}

void RGB::high_contrast(vector<string> file_vec, ofstream& s)
{
	for (int i = 3; i < file_vec.size(); i++)
	{
		vector<string> new_vec = StringSplitter::split(file_vec[i], " ");
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
			s << row << " ";
		}
		s << endl;
	}
}

void RGB::grayscale(vector<string> file_vec, ofstream& s)
{
	for (int i = 3; i < file_vec.size(); i++)
	{
		vector<string> new_vec = StringSplitter::split(file_vec[i], " ");
		for (int i = 0; i < new_vec.size() - 1; i += 3)
		{
			setRed(stoi(new_vec[i]));
			setGreen(stoi(new_vec[i + 1]));
			setBlue(stoi(new_vec[i + 2]));

			int h = ((stoi(getRed()) + stoi(getBlue()) + stoi(getGreen())) / 3);

			setRed(h);
			setGreen(h);
			setBlue(h);

			new_vec[i] = getRed();
			new_vec[i + 1] = getGreen();
			new_vec[i + 2] = getBlue();
		}

		for (auto row : new_vec)
		{
			s << row << " ";
		}
		s << endl;
	}
}

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