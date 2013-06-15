/*
 *	CS161:		Assignment 2
 *	Author:		Jeremy Hall
 *	Date:		10/12/2008
 *	Sources:	None
 *	Desc:		This program will accept the number of various denomenations in US Currency and output the total in
 *				United States Dollars, Pounds Sterling, and Euros for Continental Europe.
 */

#include <iostream>
#include <iomanip>

using namespace std;
const double POUND_CONVERSION = 0.4943;
const double EURO_CONVERSION = 0.7070;
const double DOLLAR = 1.00;
const double QUARTER = 0.25;
const double DIME = 0.10;
const double NICKEL = 0.05;
const double PENNY = 0.01;

int main()
{
	double numberByCurrency;
	double usDollars = 0.00;
		
	cout << "Welcome to Jeremy Hall's Currency Converter!" << endl;
	cout << "\nHow many dollars do you have? ";
	cin >> numberByCurrency;
	cin.clear();
	cin.ignore (100, '\n');
	usDollars = usDollars + numberByCurrency * DOLLAR;

	cout << "\nHow many quarters do you have? ";
	cin >> numberByCurrency;
	cin.clear();
	cin.ignore (100, '\n');
	usDollars = usDollars + numberByCurrency * QUARTER;

	cout << "\nHow many dimes do you have? ";
	cin >> numberByCurrency;
	cin.clear();
	cin.ignore (100, '\n');
	usDollars = usDollars + numberByCurrency * DIME;

	cout << "\nHow many nickels do you have? ";
	cin >> numberByCurrency;
	cin.clear();
	cin.ignore (100, '\n');
	usDollars = usDollars + numberByCurrency * NICKEL;

	cout << "\nHow many pennies do you have? ";
	cin >> numberByCurrency;
	cin.clear();
	cin.ignore (100, '\n');
	usDollars = usDollars + numberByCurrency * PENNY;

	cout << fixed << showpoint << setprecision (2);
	cout << "\nYou have: $" << usDollars << "." << endl;
	cout << "\nThis is equivalent to " << usDollars * POUND_CONVERSION << " Pounds and "
		 << usDollars * EURO_CONVERSION << " Euros." << endl;
	cout << "\nThanks for using Jeremy Hall's Currency Converter!" << endl;


	return 0;
}