#include "Decoder.h"



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
				}
			}
			catch (...)
			{

			}
		}
	}

	setMessage(to_string(pixels[0][0][0]));
	cout << getMessage();

	setX(pixels[0][0][1]);
	setY(pixels[0][0][2]);

	while ((getX() != 0) && (getY() != 0))
	{
		setMessage(to_string(pixels[getX()][getY()][0]));
		int x_temp = getX();
		setX(pixels[getX()][getY()][1]);
		setY(pixels[x_temp][getY()][2]);
		cout << getMessage();
	}
	

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