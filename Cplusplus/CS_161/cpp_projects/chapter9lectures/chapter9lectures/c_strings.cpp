#include <iostream>

using namespace std;

const int SIZE_CHAR = 10;

int main()
{
	char name[SIZE_CHAR + 1];
	//name = "a";	// doesn't work
	strcpy(name, "a");
	cout << "Please enter your full name followed by enter. ";
	cin.get(name, SIZE_CHAR);
	cout << name << endl;

	return 0;
}
