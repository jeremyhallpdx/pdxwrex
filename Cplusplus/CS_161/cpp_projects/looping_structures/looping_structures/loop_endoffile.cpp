#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	ifstream inFile;
	ofstream outFile;
	string fname, lname;
	double bonus;
	double salary;
	double total;
	
	inFile.open ("salary.txt");		//this is to open the input file. For now, file must be located inside of project folder!!

	if (!inFile)	//error check for input file.
	{
		cout << "File not found! Program terminating!" << endl;
		exit (0);
	}

	while (!inFile.eof())
	{
		inFile >> fname >> lname >> salary >> bonus;
		total = salary + bonus;
		cout << setw (25) << left << fname
				<< setw (25) << left << lname
				<< setw (25) << left << total << endl;
	}

	inFile.close();	
	return 0;
}