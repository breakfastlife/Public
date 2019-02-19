#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "stringSplitter.h"
#include "RGB.h"


using namespace std;
//vector<string> readFile(ifstream& some_file);
//vector<string> readFile(ifstream&& some_file);
//vector<string> readFile(string file_name);

int main()
{
	int user_input(0);
	string input_file, output_file;
	do
	{
		cout << "PPM Image Manipulator\n";
		cout << "Enter input file: ";
		cin >> input_file;
		cout << endl << "Enter output file: ";
		cin >> output_file;
		cout << "Image Effects Menu\n";
		cout << "1. Remove Red\t 2.Remove Green\t 3. Remove Blue\t 4. Negate Red\n";
		cout << "5. Negate Green\t 6. Negate Blue\t 7. Add Random Noise\t 8. High Contrast\n";
		cout << "9. Grayscale\t 10. Flip Horizontal\t 11. Flip Vertical\t 12. Rotate 90\t";
		cout << "13. Blur\t 14. Pixelate\t 15. Exit Program\n\n";
		cout << "Selection: ";
		cin >> user_input;
		if (user_input != 15)
		{
			RGB bun(user_input, input_file, output_file);
			cout << "Effect applied\n";
		}
		if (user_input == 15)
			cout << "Exiting Program\n\n";
	} while (user_input != 15);
	//system("pause");
	return 0;
}


