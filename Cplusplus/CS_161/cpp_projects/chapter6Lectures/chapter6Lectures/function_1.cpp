#include <iostream>

using namespace std;

// Function prototypes:
void header();
int larger(int, int);
void user_input();

int main()
{
	header();
	user_input();

	return 0;
}
// This function displays my header.
void header()
{
	cout << "\nName: Jeremy Hall";
	cout << "\nAssignment: User Defined Functions";
	cout << "\nDate Created: 28-October-2008";
	cout << "\nSources: None" << endl;
	cout << endl;
}
// This function calculates the larger of two integers.
int larger(int a, int b)
{
	if (a > b)
		return a;
	else return b;
}
// This function accepts user input.
void user_input()
{
	int x, y, large;

	cout << "Enter two integers: ";
	cin >> x >> y;

	large = larger(x, y);
	cout << "\nThe larger of the 2 numbers is: " << large << endl;
}