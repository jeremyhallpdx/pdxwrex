#include <iostream>
#include <cstdlib>

using namespace std;

//Function prototypes:
void swap(int, int);		// Swap function


int main()
{
	int x, y;

	cout << "Enter two numbers: " << endl;
	cin >> x >> y;

	swap(x, y);

	cout << "In main:\nX = " << x << "\nY = " << y << endl;

	return 0;
}
void swap(int x, int y)
{
	int temp;

	temp = x;
	x = y;
	y = temp;

	cout << "In function swap:\nx = " << x << "\nY = " << y << endl;
}
