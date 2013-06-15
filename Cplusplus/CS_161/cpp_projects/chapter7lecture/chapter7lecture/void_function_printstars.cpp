#include <iostream>

using namespace std;

void print_stars(int);

int main()
{
	int x;
	cout << "Enter the No. of stars: ";
	cin >> x;
	print_stars(x);

	return 0;
}

void print_stars(int a)
{
	int i;
	for (i = 0; i < a; i++)
		cout << "*" << ' ';

	cout << endl;
}