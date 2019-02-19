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

