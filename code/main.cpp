#include <unordered_map> //hash table
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

vector<string> readFile(ifstream& some_file);
vector<string> readFile(ifstream&& some_file);
vector<string> readFile(string file_name);

void concordance(string text)
{
	//TODO
	unordered_map<string, int> distribution = {};
	vector<string> file_read = readFile(text);
	for (auto string_file : file_read)
	{
		distribution[string_file]++;
	}
	for (auto pairs : distribution)
	{
		cout << pairs.first << " " << pairs.second << endl;
	}
	//return distribution;
}

bool hasUniqueChars(string text)
{
	//TODO
	int counter = 0;
	for (auto _char : text)
	{
		for (auto compare : text)
		{
			if (_char == compare && counter > text.size())
				return false;
			if (_char == compare)
				counter++;
		}
	}
	return true;
}

bool isAnagram(string first, string second)
{
	//TODO
	if (first.size() != second.size())
		return false;
	int counter = 0;
	for (auto _first : first)
	{
		for (auto _second : second)
		{
			if (_first == _second)
				counter++;
		}
	}
	if (counter == first.size())
		return true;
	return false;
}

string mostCommonSubstring(string text, int size)
{
	if (text.empty())
		return "";
	if (size <= 0 || size > text.size())
		return "";
	int counter = 0;
	vector<string> sub_strings = {};
	while (counter != text.size())
	{
		string temp = text.substr(counter, size);
		if(temp.size() == size)
			sub_strings.push_back(temp);
		counter++;
		cout << temp << " ";
	}
	cout << endl;
	unordered_map<string, int> _map = {};
	for (auto subs : sub_strings)
	{
		_map[subs]++;
	}
	int max = 0;
	string mostCommon = "";
	for (auto values : _map)
	{
		if (values.second > max)
		{
			max = values.second;
			mostCommon = values.first;
		}
	}

	return mostCommon;
}

int main(void)
{
	
	cout << boolalpha;

   //TODO: open test_file, create concordance

   //unique chars test
	cout << "***unique characters test***" << endl;

	//test case #1
	cout << "abcde: " <<
		hasUniqueChars("abcde") 
		<< " (expected: true)"
		<< endl;
 
	//test case #2:
	cout << "aaaa: " <<
		hasUniqueChars("aaaa")
		<< " (expected: false)"
		<< endl;

	//test case #3:
	cout << "(empty string): " <<
		hasUniqueChars("")
		<< " (expected: true)"
		<< endl;

	//test case #4:
	cout << "abcdea: " <<
		hasUniqueChars("abcdea")
		<< " (expected: false)"
		<< endl;

	//anagram tests
	cout << endl << endl;
	cout << "***anagram tests***" << endl;

	//test case #1:
	cout << "tab, bat: " <<
		isAnagram("tab", "bat")
		<< " (expected: true)"
		<< endl;

	//test case #2
	cout << "bat, tab: " <<
		isAnagram("bat", "tab")
		<< " (expected: true)"
		<< endl;

	//test case #3
	cout << "(empty), (empty): " <<
		isAnagram("", "")
		<< " (expected: true)"
		<< endl;

	//test case #4
	cout << "dog, cat: " <<
		isAnagram("dog", "cat")
		<< " (expected: false)"
		<< endl;

	//test case #5
	cout << "castles, castle: " <<
		isAnagram("castles", "castle")
		<< " (expected: false)"
		<< endl;

	//test case #6
	cout << "bat, tabb: " <<
		isAnagram("bat", "tabb")
		<< " (expected: false)"
		<< endl;

	//most common substring
	cout << endl << endl << "***Most common substring***" << endl;

	//test case #1
	cout << "abcabcdefdefabc. 3: " <<
		mostCommonSubstring("abcabcdefdefabc", 3)
		<< " (expected: abc)"
		<< endl;

	//test case #2
	cout << "defdefabcabc, 3: " <<
		mostCommonSubstring("defdefabcabc", 3)
		<< " (expected: def)"
		<< endl;

	//test case #3
	cout << "aaabbcccc, 1: " <<
		mostCommonSubstring("aaabbcccc", 1)
		<< " (expected: c)"
		<< endl;

	//test case #4
	cout << "abcdefhijklmnopqrstuvwxyz, 4: " <<
		mostCommonSubstring("abcdefhijklmnopqrstuvwxyz", 4)
		<< " (expected: abcd)"
		<< endl;

	//test case #5
	cout << "abc, 5: " <<
		mostCommonSubstring("abc", 5)
		<< " (expected: NULL)"
		<< endl;

	//test case #6
	cout << "(Empty), 1: " <<
		mostCommonSubstring("", 1)
		<< " (expected: NULL)"
		<< endl;

	//test case #7
	cout << "abcabcab, 3: " <<
		mostCommonSubstring("abcabcab", 3)
		<< " (expected: abc)"
		<< endl;

	//test case #8
	cout << "abcabcab, 0: " <<
		mostCommonSubstring("abcabcab", 0)
		<< " (expected: NULL)"
		<< endl;

	return 0;
}


vector<string> readFile(ifstream& some_file)
{
	vector<string> result{};
	//is the file open?
	if (some_file.is_open() == true)
	{
		while (some_file.good() == true)
		{
			//two ways to grab data
			string data;;
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