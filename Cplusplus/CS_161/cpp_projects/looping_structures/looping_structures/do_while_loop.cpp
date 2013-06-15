#include <iostream>

using namespace std;

int main()
{

	int feet, inches;
	double cms;
	char answer;

do
	{
		cout << "Enter feet and inches: " << endl;
		cin >> feet >> inches;
	
		cms = ((feet * 12) + inches) * 2.54;
		cout << "Centimeters = " << cms << endl;

		cout << "Do you want to continue? ";
		cin >> answer;

	}while (answer == 'y' || answer == 'Y');

	return 0;

}