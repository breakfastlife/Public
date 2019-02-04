#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

void search1(string item, vector<string> vectorSearch, int& deathCount)
{
	int deathCounter(0);
	for (int i = 0; i < 3; i++)
	{
		if (item == vectorSearch[i])
			deathCounter = stoi(vectorSearch[3]);
	}
	deathCount += deathCounter;
}

void search2(string first, string second, vector<string> vectorSearch, int& deathCount)
{
	int deathCounter(0);
	for(int i=0; i < 4 ; i++)
	{
		if (first == vectorSearch[i])
		{
			for (int j = 0; j < 4; j++)
			{
				if (second == vectorSearch[j])
				{
					deathCounter = stoi(vectorSearch[3]);
				}
			}
		}
		if (second == vectorSearch[i])
		{
			for (int k = 0; k < 4; k++)
			{
				if (first == vectorSearch[k])
				{
					deathCounter = stoi(vectorSearch[3]);
				}
			}
		}
	}
	deathCount += deathCounter;
}

void search3(vector<string> vectorSearch, int& deathCount)
{
	int deathCounter(0);
	if (vectorSearch[0] != "year")
		try {
		deathCounter = stoi(vectorSearch[3]);
	}
	catch (...) {
		deathCounter = 0;
	}
	else
		deathCounter = 0;
	deathCount += deathCounter;
}

void search4(string state, string cause, string year, vector<string> vectorSearch, int& deathCount)
{
	int deathCounter(0);
	if (state == vectorSearch[2] && cause == vectorSearch[1] && year == vectorSearch[0])
		{
		deathCounter = stoi(vectorSearch[3]);
		}
	deathCount += deathCounter;
}