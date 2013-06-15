#include <iostream>

using namespace std;

void mystery(int&, int);

int main()
{	
	int x = 10;
	int y = 15;

	mystery(x, y);

	cout << x << " " << y << endl;

	return 0;
}

void mystery(int& one, int two)
{
	int temp;

	temp = one;
	one = two;
	two = temp;
}