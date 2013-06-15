#include <iostream>

using namespace std;

const int SENTINEL = -999;

int main()
{
	int number;
	int sum = 0;
	int count = 0;

	cout << "Line 1: Enter integers ending with " << SENTINEL << endl;
	cin >> number;

	while (number != SENTINEL)
	{
		sum = sum + number;
		count++;
		cin >> number;
	}

	cout << "Line 7: The sum of the " << count << " numbers is " << sum << endl;

	if (count != 0)
		cout << "Line 9: The average is " << sum / count << endl;
	
	else
		cout << "Line 11: No input." << endl;

	return 0;
}