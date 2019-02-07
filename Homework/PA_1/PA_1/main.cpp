//Bryce Ellard
//colaborators: Jacob Castro, Madison Clark-Tito, Matthew Bahloul

// github: https://github.com/breakfastlife/Spring2019-CS211

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "CsvReader.h"

using namespace std;

void search(string year, string state, string cause, int &num, vector<vector<string>> file);


int main()
{
	CsvStateMachine deathStuff( "death_rates.csv" );
	deathStuff.processFile();


	int yearDeath{ 0 };
	string queryAnswer("Y");
	do {
		int total(0);
		string stateSearch, searchCause, yearSearch;
		cout << "****Death Rate Data Analysis ****\n";
		cout << "Enter State (-1 for all states): ";
		getline(cin, stateSearch);
		//cin >> stateSearch;
		if (stateSearch == "-1")
			stateSearch = "all states";
		cout << "\nEnter Cause (-1 for all causes): ";
		getline(cin, searchCause);
		//cin >> searchCause;
		if (searchCause == "-1")
			searchCause = "all causes";
		cout << "\nEnter Year (-1 for all years): ";
		getline(cin, yearSearch);
		if (yearSearch == "-1")
			yearSearch = "all years";
		
		search(yearSearch, stateSearch, searchCause, total, deathStuff.getTable());

		cout << "\n\nTotal deaths in " << stateSearch << " from ";
		cout << searchCause << " in " << yearSearch << ": " << total;

		cout << "\n\nWould you like to run another query (Y/N)?";
		getline(cin, queryAnswer);

	} while (queryAnswer == "y" || queryAnswer == "Y");


	return 0;
}

void search(string year, string state, string cause, int &num, vector<vector<string>> file)
{
	for (auto row : file)
	{
		if (row[2] == state || state == "all states")
		{
			if (row[1] == cause || cause == "all causes")
			{
				if (row[0] == year || year == "all years")
				{
					string search;
					search = row[3];
					stringstream intString(search);
					int intString_input;
					intString >> intString_input;
					num += intString_input;
				}
			}
		}
	}
}