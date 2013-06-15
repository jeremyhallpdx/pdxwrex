#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
#include "classlist.h"
#include "classrecord.h"
#include "menus.h"

//	Default Constructor
personType::personType() {
	string firstName = "";
	string lastName = "";
	string accountNumber = "";
	float amount = 0.0;
	accountType type = UNKNOWN;
}

//	DB Load: Public function
void personType::set_record(string tempFName, string tempLName, string tempAccount, int tempType, float tempAmount){
	firstName = tempFName;
	lastName = tempLName;
	accountNumber = tempAccount;
	switch(tempType) {	//	Switch statement for assignment of enum type.
			case -1:
				type = UNKNOWN;
				break;
			case 0:
				type = CHECKING;
				break;
			case 1:
				type = SAVINGS;
				break;
			case 2:
				type = CREDITCARD;
				break;
			case 3:
				type = INSTANTACCESS;
				break;
		}	//	Ends switch statement.
	amount = tempAmount;
}

//	DB Dump: Public function
void personType::print_record(ofstream& outFile) {
	outFile << '\n' << firstName << " " << lastName << " " << accountNumber << " ";
	outFile << fixed << showpoint << setprecision(2) << amount << " " << type;
}


//	findcustomerindex by account!
//	public
bool personType::index_search(string account) {
	if(accountNumber == account) {
		return true;
	}
	else
		return false;
}


//	DEPOSIT FUNDS: Public Function
float personType::call_deposit(float amount1) {
	float tempAmt = add_deposit(amount1);
	return tempAmt;
}
//	DEPOSIT FUNDS: Private functions
float personType::add_deposit(float amount1) {
	amount += amount1;
	return amount;
}
void personType::deposit_log(ofstream &depositLog, float amount1) {
	print_deposit(depositLog, amount1);
}

void personType::print_deposit(ofstream &depositLog, float amount1) {
	depositLog << fixed << showpoint << setprecision(2)
			   << accountNumber << ": +$" << amount1 << endl;
}


//	Functions for logFile
void personType::log_file(ofstream &logFile, float amount1, int transType) {
	if(transType == DEPOSIT) {
		logFile << fixed << showpoint << setprecision(2)
				<< accountNumber << ": +$" << amount1 << endl;
	}
	else
		logFile << fixed << showpoint << setprecision(2)
				<< accountNumber << ": -$" << amount1 << endl;
}

//	WITHDRAW FUNDS: Public function
float personType::call_withdrawl(float amount1) {
	float tempAmt = sub_withdrawl(amount1);
	return tempAmt;
}
//	WITHDRAW FUNDS: Private functions
float personType::sub_withdrawl(float amount1) {
	amount -= amount1;
	return amount;
}
void personType::withdrawl_log(ofstream &withdrawlLog, float amount1) {
	print_withdrawl(withdrawlLog, amount1);
}
void personType::print_withdrawl(ofstream &withdrawlLog, float amount1) {
	withdrawlLog << fixed << showpoint << setprecision(2)
				 << accountNumber << ": -$ " << amount1 << endl;
}



//	BALANCE INQUIRY: public
void personType::print_balance() {
	cout << "Account: " << accountNumber;
	cout << cout << fixed << showpoint << setprecision(2) << ": $" << amount << endl;
}


//	FIND CUSTOMER BY NAME
//Public:
bool personType::index_searchName(string name1) {
	if(lastName == name1) {
		return true;
	}
	else
		return false;
}


//	Show customer data on screen
//	Public:
void personType::show_record() {
	cout << "\nRecord Found:" << endl;
	cout << '\n' << firstName << " " << lastName << endl;
	cout << "Account: " << accountNumber << fixed << showpoint << setprecision(2)
		 << "  $" << amount << " "; 
	 
	if(type == 0)
		cout << "Checking" << endl;
	else if(type == 1)
		cout << "Savings" << endl;
	else if(type == 2)
		cout << "Credit Card" << endl;
	else
		cout << "Instant Access" << endl;
}


//	Get NEW Cusomter data
void personType::get_data() {
	int choice = 0;

	cout << "\nPlease enter the following information:" << endl;
	cout << "\nFirst Name: ";
	cin >> firstName;
	cout << "\nLast Name: "; 
	cin >> lastName;
	cout << "\nAccount Number: ";
	cin >> accountNumber;
	cout << "\nOpening Balance: $";
	cin >> amount;
	cout << "\nAccount Type:" << endl;
	cout << "1. Checking" << endl;
	cout << "2. Savings" << endl;
	cout << "3. Credit Card" << endl;
	cout << "4. Instant Access" << endl;
	cin >> choice;
	switch(choice) {
		case 1:
			type = CHECKING;
			break;
		case 2:
			type = SAVINGS;
			break;
		case 3:
			type = CREDITCARD;
			break;
		case 4:
			type = INSTANTACCESS;
			break;
		default:
			type = UNKNOWN;
			break;
	}	//	Ends switch statement.
}

//	Function to sum the dollars in vault
float personType::get_sum() {
	float tempSum = amount;
	return tempSum;
}

//	Function to list the names of all customers.
void personType::print_name() {
	cout << firstName << " " << lastName << endl;
}

//	Function to delete record.
void personType::del_record(string deletedAccountNum) {
	if(accountNumber != deletedAccountNum) {
		accountNumber = deletedAccountNum;
		amount = -1;
		type = UNKNOWN;
		cout << "\nRecord successfully deleted." << endl;
	}
	else
		cout << "\nRecord not found." << endl;
}