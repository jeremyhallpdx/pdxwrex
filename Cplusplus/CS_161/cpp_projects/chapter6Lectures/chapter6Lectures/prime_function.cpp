#include <iostream>
#include <cstdlib>

using namespace std;

// Function prototypes:

bool is_prime(int);


int main()
{
	int num = 0;

	cout << "Please enter an integer: " << endl;
	cin >> num;
	cin.ignore(100, '\n');
	while (!cin)
	{
		cin.clear();
		cout << "Invalid input! Please try again." << endl;
		cout << "Please enter an integer: " << endl;
		cin >> num;
	}
		
	if (is_prime (num))
		cout << "The number " << num << " is prime." << endl;
	else
		cout << "The number " << num << " is not prime." << endl;

	return 0;
}

// Function to check for prime.
bool is_prime(int num)
{
	int j;
	bool prime = true;

	for (j = 2; j < num; j++)
	{
		if (num % j == 0)
		{
			prime = false;
			break;
		}
	}
	return prime;
}