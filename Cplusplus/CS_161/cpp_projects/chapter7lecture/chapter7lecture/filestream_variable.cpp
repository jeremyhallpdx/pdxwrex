#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

void read_file(ifstream&);

int main()
{
	ifstream inFile;
	string fileName = "myScores.txt";
	inFile.open(fileName.c_str());
	if(!inFile)
	{
		cout << "File does not exist!";
		return (-1);
	}
	read_file(inFile);

	inFile.clear();		// Resets the inFile.
	inFile.seekg(0);	// Starts at a specific position in the file.

	inFile.close();

	return 0;
}
void read_file(ifstream &inFile)
{
	string name;
	double score1, score2, score3;

	while(!inFile.eof())
	{
		inFile >> name >> score1 >> score2 >> score3;
		cout << showpoint << fixed << setprecision(2);
		cout << name << '\t' << (score1 + score2 + score3) / 3 << endl;
	}
}