/*	CS161 Ch 3 Demo code
 *	Date:  10/07/2008
 *	Author:  Jeremy Hall
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	string fname;
	string lname;
	double currentSalary;
	double percentPayIncrease;
	double updatedSalary;

	ifstream infile;
	infile.open ("Ch3_Ex8Data.txt");
	ofstream outfile;
	outfile.open ("Ch3_Ex8Output.txt");

	infile >> lname >> fname >> currentSalary >> percentPayIncrease;
	
	updatedSalary = (currentSalary * percentPayIncrease / 100) + currentSalary;
	
	outfile << fixed << setprecision (2) << setw (10) << left << fname << setw (10) << lname << setw (20)
		<< setw (10) << updatedSalary << endl;
	
	infile >> lname >> fname >> currentSalary >> percentPayIncrease;
	
	updatedSalary = (currentSalary * percentPayIncrease / 100) + currentSalary;
	
	outfile << fixed << setprecision (2) << setw (10) << left << fname << setw (10) << lname << setw (20)
		<< setw (10) << updatedSalary << endl;

	infile >> lname >> fname >> currentSalary >> percentPayIncrease;
	
	updatedSalary = (currentSalary * percentPayIncrease / 100) + currentSalary;
	
	outfile << fixed << setprecision (2) << setw (10) << left << fname << setw (10) << lname << setw (20)
		<< setw (10) << updatedSalary << endl;

	cout << "Done." << endl;
	infile.close ();
	outfile.close ();
	
	return 0;
}