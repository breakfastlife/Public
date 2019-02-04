// Bryce Ellard
// CS 211
// 1/29/2019
// PA 1

#include <iostream>
#include <vector>
#include <string>
#include "CsvReader.h"

using namespace std;

int main()
{

	
	
	
	int yearDeath{ 0 };
	string queryAnswer("Y");
	do {
		CsvStateMachine deathStats{ "death_rates.csv" };
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
		//cin.ignore();
		//cout << deathStats.search(stateSearch, searchCause, yearSearch);

		cout << "\n\nTotal deaths in " << stateSearch << " from ";
		cout << searchCause << " in " << yearSearch << ": ";
		deathStats.processFile(stateSearch, searchCause, yearSearch);

		cout << "\n\nWould you like to run another query (Y/N)?";
		getline(cin, queryAnswer);
		
	} while (queryAnswer == "y" || queryAnswer == "Y");

	

	return 0;
}
