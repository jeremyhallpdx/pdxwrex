#include <iostream>

using namespace std;

	// Function prototypes:
int my_power(int, int);

int main()
{
	int base = 0, exponent = 0;

	cout << "Enter a base number: ";
	cin >> base;
	cout << "Enter the number to raise the base to: ";
	cin >> exponent;

	cout << base << " to the power of " << exponent << " is: " << my_power(base, exponent) << endl;

	return 0;
}

int my_power(int base, int exponent)
{	
	int power = 1;

	for (int i = 0; i < exponent; ++i)
	{
		power *= (base) - 1;
	}

	return power;
}
