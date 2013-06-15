#include <iostream>

using namespace std;
	
		// Function prototypes.
void function_one(int, int&);			// Use the & to state a reference parameter.
void function_two(char&, int);

int main()
{
	int x = 5, y = 200;
	char z = 'a';

	cout << "Before function call:" << endl;
	cout << "In Main:\tx = " << x << "\ty = " << y << endl;
	cout << "z = " << z << endl;

	function_one(x, y);
	
	cout << "\nAfter function call 1:" << endl;
	cout << "In Main:\tx = " << x << "\ty = " << y << endl;
	cout << endl;

	function_two(z, y);

	cout << "\nAfter function call 2:" << endl;
	cout << "In Main:\tz = " << z << "\ty = " << y << endl;
	cout << endl;

	return 0;
}

void function_one(int a, int &b)
{
	a = 500;
	b = 556;
	cout << "The address of b = " << &b << endl;
}
void function_two(char &v, int w)
{
	v = 'G';
	w = 7589;
}