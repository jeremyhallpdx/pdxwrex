#include <iostream>

using namespace std;


int main()
{
	int number;

	cout << "Enter an integer: " << endl;
	cin >> number;

	while (cin)
	{
		cout << number << endl;
		cin >> number;
	}

	/*while (!cin)
	{
		cin.clear();
		cin.ignore (100, '\n');
		cout << "Invalid input! Please try again." << endl;
		cin >> number;
	}*/
	cin.ignore (100, '\n');

	//cout << "Your number is: " << number << endl;

	return 0;
}