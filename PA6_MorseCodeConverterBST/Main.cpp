#include "BST.hpp"
#include <cctype>

int main() {
	BST<char, string> tree;

	cout << "Printing Entire Tree: " << endl;
	tree.print();
	cout << endl;

	ifstream inputFile("Convert.txt");

	string buffer;
	char c;

	cout << endl << "Converting text to morse code" << endl;
	if (inputFile)
	{
		while (getline( inputFile, buffer ))
		{
			for (int i = 0; i < buffer.size(); i++)
			{
				if (buffer[i] == ' ')
				{
					cout << " ";
				}
				else 
				{
					c = buffer[i];
					if (isalpha(c))
					{
						c = toupper(c);
					}
					cout << tree.search(c) << " ";
				}
			}
			cout << endl;
		}
		cout << endl;
	}

	inputFile.close();

	return 0;
}