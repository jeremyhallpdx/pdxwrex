/*
 *	Chapter 4 Lecture:  Control Structures
 *	10/14/08
 */

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const double CHECKING_SERV_CHARGE = 25.00;
const double SAVINGS_SERV_CHARGE = 10.00;
const double CHECKING_INTEREST = 0.05;
const double SAVINGS_INTEREST = 0.04;
const double OVERBALANCE_CHECKING_INTEREST = 0.03;

int main()
{
	int accountNumber;
	char accountType;
	double minBalance;
	double currentBalance;
	double newBalance;

	cout << "Please enter your account number: " << endl;
	cin >> accountNumber;
	if (!cin)
	{	cout << "Invalid input.  Program terminating." << endl;
		return (-1);
	}
	
	cout << "Please enter your account type using 'S' for Savings or 'C' for Checking: " << endl;
	cin >> accountType;
	if (!cin)
	{	cout << "Invalid input.  Program terminating." << endl;
		return (-1);
	}

	cout << "Please enter the minimum balance for this account: " << endl;
	cin >> minBalance;
	if (!cin)
	{	cout << "Invalid input.  Program terminating." << endl;
		return (-1);
	}

	cout << "Please enter the current balance for this account: " << endl;
	cin >> currentBalance;
	if (!cin)
	{	cout << "Invalid input.  Program terminating." << endl;
		return (-1);
	}
	if (accountType == 'S' || accountType == 's')
		newBalance = currentBalance + currentBalance * SAVINGS_INTEREST;
	else if (accountType == 'C' || accountType == 'c')
	{
		if (currentBalance > minBalance + 5000.00)
			newBalance = currentBalance + currentBalance * OVERBALANCE_CHECKING_INTEREST;
		else
			newBalance = currentBalance + currentBalance * CHECKING_INTEREST;
	}

	cout << "Account Number: " << accountNumber << "\nAccount Type: " << accountType << "\nMinimum Monthly Balance: " 
		 << minBalance << "\nCurrent Balance: " << newBalance << endl;

	return 0;
}