#pragma once
#include <string>
#include <iostream>

using namespace std;

class RGB {
private:
	int red;
	int green;
	int blue;

public:
	RGB();
	RGB(int color1, int color2, string option);
	RGB(int red, int green, int blue);
	~RGB();
	const int getRed() const;
	const int getBlue() const;
	const int getGreen() const;
	void setRed(int color);
	void setBlue(int color);
	void setGreen(int color);
};

RGB::RGB(int color1, int color2, string option)
{
	switch (stoi(option))
	{
	case 0:



	}

}


RGB::RGB(int red, int green, int blue)
{
	setRed(red);
	setGreen(green);
	setBlue(blue);
}


