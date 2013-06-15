#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

struct menuItemType		// These go after the namespace declaration.
{
	string itemName;
	double itemPrice;
};

int main()
{
	menuItemType item[5];		// Every item has itemName and itemPrice.
	ifstream inFile;
	ofstream outFile;

	// Open file:
	inFile.open("menu.txt");
	if(!inFile)
	{
		cout << "Cannot find file!  Program terminating!";
		return (-1);
	}

	// Read data:
	for(int i = 0; i < 5; i++)
	{
		getline(inFile, item[i].itemName, ';');
		inFile.ignore(100, '$');
		inFile >> item[i].itemPrice;
		inFile.ignore(100, '\n');
	}

	for(int i = 0; i < 5; i++)
	{
		cout << item[i].itemName << '\t' << item[i].itemPrice << endl;
	}

	return 0;
}