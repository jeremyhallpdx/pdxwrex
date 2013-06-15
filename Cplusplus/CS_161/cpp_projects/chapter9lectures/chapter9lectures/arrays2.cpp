#include <iostream>

using namespace std;

const int N = 5;

int main()
{
	int list[N] = {0};

	list[2] = 5;
	list[3] = 6;

	cout << "Element number 1 = " << list[0] << endl;
	cout << "Element number 3 = " << list[2] << endl;
	cout << "Element number 4 = " << list[3] << endl;

	return 0;
}