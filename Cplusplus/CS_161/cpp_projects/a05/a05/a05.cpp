/*
 *	CS_161:			Assignment 5
 *	Author:			Jeremy Hall
 *	Date Created:	8-November-2008
 *	Sources:		Brandon Fasching
 *	Desc:			This program outputs all of the Mersenne Prime numbers from 2 through 1,000,000.
 */

#include <iostream>
#include <iomanip>

using namespace std;

		// Function prototypes:
int my_power(int);
bool is_prime(int);

		// Declared global variables:
const int MAX_VAL = 1000000;		// Max-range value of Mersennes primes.

int main()
{
	int power = 0;

	cout << "Mersennes Primes by Jeremy Hall" << endl;
	cout << setw(2) << "n" << '\t' 
		 << setw(14) << "Mersenne Prime" << endl;
	cout << setw(3) << setfill('=') << '\t'
		 << setw(15) << ' ' << endl;
	cout << setfill(' ') << endl;

	for (int n = 2; my_power(n) <= MAX_VAL; ++n)
	{
		power = my_power(n) - 1;

		if (is_prime(power))
		{
			cout << setw(2) << n << '\t'
				 << setw(14) << power << endl;
		}
	}
	cout << "\nPress Q (or any key) followed by 'Enter' to exit. ";
	cin.get();
	cout << endl;

	return 0;
}

	// Function to calulate 2^n.
int my_power(int n)
{	
	int power = 1;

	for (int i = 0; i < n; ++i)
	{
		power *= 2;
	}
	return power;
}

	// Function to determine if the value of 2^n-1 equates to a prime number.
bool is_prime(int power)
{
	bool prime = true;

	for (int j = 2; j < power; ++j)
	{
		if (power % j == 0)
		{
			prime = false;
			break;
		}
	}
	return prime;
}