#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int loadDatabase(string inName);


int main() {
	ifstream inFile;
	ofstream outFile;
	string inName = "database_in.txt";

	int count = loadDatabase(inName.c_str());
	inFile.close();

	cout << "this is the number of lines:";	
	cout << count;
	
	return 0;
}



int loadDatabase(string inName)
{
	char name[10];
	ifstream inFile;
	int countA = 0;
	int i = 0;

	inFile.open(inName.c_str());
	if (!inFile)
	{
		cout << "\nFile not found! Program terminating." << endl;
		exit (0);
	}

	while(!inFile.eof())
	{
		++countA;
		inFile >> name[i];
		i++;
	}
	return countA;
}
