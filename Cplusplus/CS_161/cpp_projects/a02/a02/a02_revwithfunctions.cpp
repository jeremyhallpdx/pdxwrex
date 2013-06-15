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
#include <string>

using namespace std;

		// Function protoypes:
int user_input (string);
void data_output (double, double, double);

		// Named constants:
const double POUND_CONVERSION = 0.4943;
const double EURO_CONVERSION = 0.7070;
const double DOLLAR = 1.00;
const double QUARTER = 0.25;
const double DIME = 0.10;
const double NICKEL = 0.05;
const double PENNY = 0.01;

int main()
{
	double numberByCurrency = 0.0;
	double usDollars = 0.00;
	
	cout << "Welcome to Jeremy Hall's Currency Converter!" << endl;
	
	numberByCurrency = int user_input("\nHow many dollars do you have? ");
	usDollars += numberByCurrency * DOLLAR;

	numberByCurrency = int user_input("\nHow many quarters do you have? ");
	usDollars = usDollars + numberByCurrency * QUARTER;

	numberByCurrency = int user_input("\nHow many dimes do you have? ");
	usDollars = usDollars + numberByCurrency * DIME;

	numberByCurrency = int user_input("\nHow many nickels do you have? ");
	usDollars = usDollars + numberByCurrency * NICKEL;

	numberByCurrency = int user_input("\nHow many pennies do you have? ");
	usDollars = usDollars + numberByCurrency * PENNY;

	void data_output (usDollars, POUND_CONVERSION, EURO_CONVERSION);

	cout << "\nThanks for using Jeremy Hall's Currency Converter!" << endl;

	return 0;
}

int user_input (string msg)
{
	int amountOfCurrency = 0;

	cout << msg;
	cin >> amountOfCurrency;
	cin.ignore (100, '\n');
	while (!cin)
	{
		cout << "\nInvalid input! Please try again. ";
		cout << msg;
		cin >> amountOfCurrency;		
	}

	return amountOfCurrency;
}
void data_output (double usDollars, double POUND_CONVERSION, double EURO_CONVERSION)
{
	cout << fixed << showpoint << setprecision (2);
	cout << "\nYou have: $" << usDollars << "." << endl;
	cout << "\nThis is equivalent to " << usDollars * POUND_CONVERSION << " Pounds and "
		 << usDollars * EURO_CONVERSION << " Euros." << endl;
}