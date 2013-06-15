#include <iostream>
#include <fstream>

using namespace std;

	// Function prototypes
void check_file(ifstream&);

int main()
{
	ifstream inFile;
	char fileName[31];

	strcpy(fileName, "input.txt");

	inFile.open(fileName);
	check_file(inFile);

	inFile.close();

	return 0;
}
void check_file(ifstream& in)
{
	if(!in)
		cout << "Open unsuccessful." << endl;
	else
		cout << "Open successful." << endl;
}