/*
 *	CS161 - Assignment 1
 *	Date: 10/03/2008
 *	Author: Jeremy Hall
 *	Sources: None
 *	Desc: This program carries a short and simple dialog between the user and a Crystal Ball.
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string user_input (string);
	string name;
	string subject;
	
	cout << "Welcome to Jeremy Hall's Crystal Ball!" << endl;
	
	name = user_input ("What is your name please? ");
	cout << "\nHello, " << name << ". My name is Jeremy. " << endl;
	
	subject = user_input ("What subject are you studying? ");
	cout << "\nWell, " << name << ", Jeremy's Crystal Ball says you will do very well in " << subject << " this term." << endl;
	
	cout << "Good luck!" << endl;

	return 0;

}

string user_input (string msg)
{	
	string input;

	cout << msg;			
	cin >> input;
	cin.ignore (100, '\n');
	while (!cin)
	{
		cout << "Invalid input! Please try again." << endl;
		cout << msg;
		cin >> input;
	}
	return input;
}

