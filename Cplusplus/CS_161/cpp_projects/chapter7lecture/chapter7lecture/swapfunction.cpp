#include <iostream>

using namespace std;

void swap(int&, int&);

int main()
{
	int x = 5, y = 10;

	cout << "Before function call: x = " << x << " y = " << y << endl;

	swap(x, y);

	cout << "After function call: x = " << x << " y = " << y << endl;

	return 0;
}
void swap(int &x, int &y)
{
	int temp;
	
	temp = x;
	x = y;
	y = temp;
}