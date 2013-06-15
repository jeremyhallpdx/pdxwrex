#include <iostream>
using namespace std;

int main()
{
	enum {JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, NOV, DEC};
	int value;
	int months[13]; //0 isn't used
	for(int i = 0; i < 13; ++i)
		months[i] = 0;

	cout << "Enter a month (1-12): " << endl;
	cin >> value;

	if(value == JAN)
		months[JAN]++;
	if(value == FEB)
		months[FEB]++;

	for(int i = 1; i < 13; ++i) {
		if(month[i])
			cout << "The month is: " << i << endl;
	}

	return 0;
}