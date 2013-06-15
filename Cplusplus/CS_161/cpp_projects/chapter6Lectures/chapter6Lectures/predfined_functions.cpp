#include <iostream>
#include <cmath>
#include <cstdlib>


using namespace std;

int main()
{
	//double num;
	char ans;

	cout << "Enter a character: ";
	cin >> ans;
	cout << "Your Uppercase character is " << static_cast<char>(toupper(ans)) << endl;
	cout << "Your Lowercase character is " << static_cast<char>(tolower(ans)) << endl;

	/*cout << "Enter a whole number: ";
	cin >> num;

	cout << "Ceiling of num is " << ceil(num) << endl;
	cout << "Floor of num is " << floor(num) << endl;

	if (num >= 0)
		cout << "Absolute value of num is " << num << endl;
	else
		cout << "Absolute value of num is " << abs(num) << endl;*/
	
	return 0;
}