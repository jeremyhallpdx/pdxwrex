#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

#include "functions.h"

/************************
* Function Definitions: *
*************************/

	//	Gets integer selection from user.
int get_option() {
	
	int option = 0;
	
	cin.clear();
	cout << "\nPlease make your selection: ";
	cin >> option;
	cin.ignore(100, '\n');
		
	return option;
}

	//	Main Menu screen.
void main_menu() {
	cout << "\nPlease choose your level of access:" << endl;
	cout << "\n1. Customer Access" << endl;
	cout << "2. Employee Access" << endl;
	cout << "3. Manager Access" << endl;
	cout << "4. Quit Program" << endl;
}

	//	Switch between Main Menu and desired interface.
void access_menu(char selection, personType database[][MAX_ACCOUNTS], int counter[], ofstream& depositLog, ofstream& withdrawlLog,ofstream& logFile) {
	switch(selection) {
	case 1: 
		customer_interface(database, counter, depositLog, withdrawlLog, logFile);
		break;
	case 2: 
		employee_interface(database, counter, depositLog, withdrawlLog, logFile);
		break;
	case 3: 
		manager_interface(database, counter, depositLog, withdrawlLog, logFile);
		break;
	case 4:
		cout << "Exiting program..." << endl;
		break;
	default:
		cout << "Invalid input! Please try again..." << endl;
		cout << endl;
		break;
	}//	Ends switch statement.
}

	//	Root for Customer functions.
void customer_interface(personType database[][MAX_ACCOUNTS], int counter[], ofstream& depositLog, ofstream& withdrawlLog, ofstream& logFile) {
	int option = 0;

	do {
		cout << "\nHow may I assist you today?" << endl;
		cout << endl;
		cout << "1." << "  " << "Withdraw Funds" << endl;
		cout << "2." << "  " << "Deposit Funds" << endl;
		cout << "3." << "  " << "Transfer Funds" << endl;
		cout << "4." << "  " << "Balance Inquiry" << endl;
		cout << "5." << "  " << "Exit Customer Menu" << endl;
	
		option = get_option();
		customer_functions(option, database, counter, depositLog, withdrawlLog, logFile);
	}while(option != 5);
}


	//	Customer functions.
void customer_functions(int option, personType database[][MAX_ACCOUNTS], int counter[], ofstream& depositLog, ofstream& withdrawlLog, ofstream& logFile) {
		switch(option) {
		case 1:
			withdraw_funds(database, withdrawlLog, logFile);
			break;
		case 2:
			deposit_funds(database, depositLog, logFile);
			break;
		case 3:
			xfer_funds(database, logFile);
			break;
		case 4:
			balance_inquiry(database);
			break;
		case 5:
			cout << "Exiting Customer Menu..." << endl;
			break;
		default:
			cout << "Invalid Input!" << endl;
			break;
		}//	Ends switch statement.
}

	//	Root for Employee functions.
void employee_interface(personType database[][MAX_ACCOUNTS], int counter[], ofstream& depositLog, ofstream& withdrawlLog, ofstream& logFile) {
	int option = 0;
	
	do {
		cout << "\nHow may I assist you today?" << endl;
		cout << endl;
		cout << "1." << "  " << "Withdraw Funds" << endl;
		cout << "2." << "  " << "Deposit Funds" << endl;
		cout << "3." << "  " << "Transfer Funds" << endl;
		cout << "4." << "  " << "Balance Inquiry" << endl;
		cout << "5." << "  " << "Add Customer" << endl;
		cout << "6." << "  " << "Delete Customer" << endl;
		cout << "7." << "  " << "Search by Customer Name" << endl;
		cout << "8." << "  " << "Exit Employee Menu..." << endl;

		option = get_option();
		employee_functions(option, database, counter, depositLog, withdrawlLog, logFile);
	}while(option != 8);
}

	//	Employee Functions.
void employee_functions(int option, personType database[][MAX_ACCOUNTS], int counter[], ofstream& depositLog, ofstream& withdrawlLog, ofstream& logFile) {
	switch(option) {
		case 1:
			withdraw_funds(database, withdrawlLog, logFile);
			break;
		case 2:
			deposit_funds(database, depositLog, logFile);
			break;
		case 3:
			xfer_funds(database, logFile);
			break;
		case 4:
			balance_inquiry(database);
			break;
		case 5:
			add_person(database, counter);
			break;
		case 6:
			del_person(database, counter);
			break;
		case 7:
			search_customerName(database);
			break;
		case 8:
			cout << "Exiting Employee Menu..." << endl;
			break;
		default:
			cout << "Invalid Input!" << endl;
			break;
	}//	End switch statement.
}

	//	Root for Manager functions.
void manager_interface(personType database[][MAX_ACCOUNTS], int counter[], ofstream& depositLog, ofstream& withdrawlLog, ofstream& logFile) {
	int option = 0;
	string outName;
	
	do {
		cout << "\nHow may I assist you today?" << endl;
		cout << endl;
		cout << "1." << "  " << "Withdraw Funds" << endl;
		cout << "2." << "  " << "Deposit Funds" << endl;
		cout << "3." << "  " << "Transfer Funds" << endl;
		cout << "4." << "  " << "Balance Inquiry" << endl;
		cout << "5." << "  " << "Add Customer" << endl;
		cout << "6." << "  " << "Delete Customer" << endl;
		cout << "7." << "  " << "Search by Customer Name" << endl;
		cout << "8." << "  " << "List total dollars in vault" << endl;
		cout << "9." << "  " << "List all customers in database" << endl;
		cout << "10." << " " << "List all deposits" << endl;
		cout << "11." << " " << "List all withrawls" << endl;
		cout << "12." << " " << "List all transactions" << endl;
		cout << "13." << " " << "Exit Manager Menu" << endl;
		
		option = get_option();
		manager_functions(option, database, counter, depositLog, withdrawlLog, logFile);
	}while(option != 13);
}

	//	Manager Functions.
void manager_functions(int option, personType database[][MAX_ACCOUNTS], int counter[], ofstream& depositLog, ofstream& withdrawlLog, ofstream& logFile) {
	switch(option) {
		case 1:
			withdraw_funds(database, withdrawlLog, logFile);
			break;
		case 2:
			deposit_funds(database, depositLog, logFile);
			break;
		case 3:
			xfer_funds(database, logFile);
			break;
		case 4:
			balance_inquiry(database);
			break;
		case 5:
			add_person(database, counter);
			break;
		case 6:
			del_person(database, counter);
			break;
		case 7:
			search_customerName(database);
			break;
		case 8:
			list_dollars(database, counter);
			break;
		case 9:
			list_customers(database, counter);
			break;
		case 10:
			list_deposits();
			break;
		case 11:
			list_withdrawls();
			break;
		case 12:
			list_transactions();
			break;
		case 13:
			cout << "Exiting Manager Menu..." << endl;
			break;
		default:
			cout << "Invalid Input! Please try again..." << endl;
			break;
	}//	Ends switch statement.
}

	//	Function to add record to database.
void add_person(personType database[][MAX_ACCOUNTS], int counter[]) {
	int i = 0;
	int input = 0;
	int choice;
	
	cout << "Please choose the new account type: " << endl;
	cout << "1. Customer Account" << endl;
	cout << "2. Employee Account" << endl;
	cin >> input;

	if(input == 1)
		input = CUSTOMER;
	else
		input = EMPLOYEE;
	i = counter[input];
	
	cout << "\nPlease enter the following information:" << endl;
	cout << "\nFirst Name: ";
	cin >> database[input][i].firstName;
	cout << "\nLast Name: "; 
	cin >> database[input][i].lastName;
	cout << "\nAccount Number: ";
	cin >> database[input][i].accountNumber;
	cout << "\nOpening Balance: $";
	cin >> database[input][i].amount;
	cout << "\nAccount Type:" << endl;
	cout << "1. Checking" << endl;
	cout << "2. Savings" << endl;
	cout << "3. Credit Card" << endl;
	cout << "4. Instant Access" << endl;
	cin >> choice;
	
	switch(choice) {
		case 1:
			database[input][i].type = CHECKING;
			break;
		case 2:
			database[input][i].type = SAVINGS;
			break;
		case 3:
			database[input][i].type = CREDITCARD;
			break;
		case 4:
			database[input][i].type = INSTANTACCESS;
			break;
		default:
			database[input][i].type = UNKNOWN;
			break;
	}	//	Ends switch statement.

	counter[input]++;
}

	//	Function to write database to text file.
void database_dump(personType database[][MAX_ACCOUNTS], int counter[]) {
	int count = 0;
	ofstream outFile;
	outFile.open("database.txt");

	for(int i = 0; i < counter[count]; i++) {
		outFile << '\n' << database[count][i].firstName << " " << database[count][i].lastName << " "
				<< database[count][i].accountNumber << " ";
		outFile << fixed << showpoint << setprecision(2) << database[count][i].amount << " "
				<< database[count][i].type;
	}
	outFile.close();
}

	//Function to read in database from text file... UNDER CONSTRUCTION!!
int database_load(personType database[][MAX_ACCOUNTS]) {
	int recordType = 0;
	int i = 0;
	int j = 0;					//	Variable for storing number of records in database.
	string tempAccountNum;		//	Temp variable for storing Account Number.
	int tempType = 0;			//	Temp variable for storing Account Type.
	float tempBalance = 0.0;	//	Temp variable for storing Account Balance.
	ifstream inFile;
	
	inFile.open("database.txt");
	if(!inFile) {
		cout << "Database record does not exist or is corrupted!" << endl;
		cout << "Program Terminating." << endl;
		exit (-1);
	}
	while(!inFile.eof()) {
		++j;
		inFile >> database[recordType][i].firstName >> database[recordType][i].lastName
			>> database[recordType][i].accountNumber >> database[recordType][i].amount;
		inFile >> tempType;
		switch(tempType) {	//	Switch statement for assignment of enum type.
			case -1:
				database[recordType][i].type = UNKNOWN;
				break;
			case 0:
				database[recordType][i].type = CHECKING;
				break;
			case 1:
				database[recordType][i].type = SAVINGS;
				break;
			case 2:
				database[recordType][i].type = CREDITCARD;
				break;
			case 3:
				database[recordType][i].type = INSTANTACCESS;
				break;
		}	//	Ends switch statement.
		i++;
	}	//	Ends while loop.
	
	return j;	//	Returns the number of lines(records) to main.
}

	//	Function to locate customer by account number.
int find_customer_index(personType database[][MAX_ACCOUNTS]) {
	int index = -1;
	string account;

	cout << "\nPlease enter the account number: ";
	cin >> account;

	for(int i = 0; i < MAX_ACCOUNTS; i++) {
		if(database[CUSTOMER][i].accountNumber == account)
		{
			index = i;
			break;
		}
	}
	return index;
}

	//	Function to deposit funds from account.
void deposit_funds(personType database[][MAX_ACCOUNTS], ofstream& depositLog, ofstream& logFile) {
	float amount1 = 0.0;
	int index = find_customer_index(database);
	
	cout << "\nPlease enter the amount you wish to deposit: $";
	cin >> amount1;

	database[CUSTOMER][index].amount += amount1;

	cout << "\nYou deposited: $" << fixed << showpoint << setprecision(2) << amount1 << endl;
	cout << "The new balance is: $" << database[CUSTOMER][index].amount << endl;

	depositLog << fixed << showpoint << setprecision(2)
			   << database[CUSTOMER][index].accountNumber << ": +$" << amount1 << endl;

	logFile << fixed << showpoint << setprecision(2)
			<< database[CUSTOMER][index].accountNumber << ": +$" << amount1 << endl;
}

	//	Function to withdraw funds from account.
void withdraw_funds(personType database[][MAX_ACCOUNTS], ofstream& withdrawlLog, ofstream& logFile) {
	float amount1 = 0.0;
	int index = find_customer_index(database);
	cout << "\nPlease enter the amount you wish to withdrawl: $";
	cin >> amount1;

	database[CUSTOMER][index].amount -= amount1;

	cout << "\nYou withdrew: $" << fixed << showpoint << setprecision(2) << amount1 << endl;
	cout << "The new balance is: $" << database[CUSTOMER][index].amount << endl;

	withdrawlLog << fixed << showpoint << setprecision(2)
				 << database[CUSTOMER][index].accountNumber << ": -$ " << amount1 << endl;

	logFile << fixed << showpoint << setprecision(2)
			<< database[CUSTOMER][index].accountNumber << ": -$" << amount1 << endl;
}

	//	Function to print out account balance.
void balance_inquiry(personType database[][MAX_ACCOUNTS]) {
	float amount1 = 0.0;
	int index = find_customer_index(database);
	cout << "Account: " << database[CUSTOMER][index].accountNumber;
	cout << fixed << showpoint << setprecision(2) << ": $" << database[CUSTOMER][index].amount << endl;
}

	//	Function to search by customer last name.
void search_customerName(personType database[][MAX_ACCOUNTS]) {
	int index = -1;
	string name1;

	cout << "\nPlease enter the customer's last name to search: " << endl;
	cout << "Name: ";
	cin >> name1;

	for(int i = 0; i < MAX_ACCOUNTS; i++) {
		if(database[CUSTOMER][i].lastName == name1)
		{
			index = i;
			break;
		}
	}
	cout << "\nRecord Found:" << endl;
	cout << '\n' << database[CUSTOMER][index].firstName << " " << database[CUSTOMER][index].lastName << endl;
	cout << "Account: " << database[CUSTOMER][index].accountNumber << fixed << showpoint << setprecision(2) << "  $" 
		 << database[CUSTOMER][index].amount << " "; 
		 
	if(database[CUSTOMER][index].type == 0)
		cout << "Checking" << endl;
	else if(database[CUSTOMER][index].type == 1)
		cout << "Savings" << endl;
	else if(database[CUSTOMER][index].type == 2)
		cout << "Credit Card" << endl;
	else
		cout << "Instant Access" << endl;
}

	//	Function to transfer funds between accounts.
void xfer_funds(personType database[][MAX_ACCOUNTS], ofstream& logFile) {
	float amount1 = 0.0;

	string msg = "from";
	int index1 = find_customer_index_for_transfer(database, msg);

	msg = "to";
	int index2 = find_customer_index_for_transfer(database, msg);

	cout << "\nPlease enter the amount you wish to transfer: $";
	cin >> amount1;

	database[CUSTOMER][index1].amount -= amount1;
	database[CUSTOMER][index2].amount += amount1;

	cout << fixed << showpoint << setprecision(2) 
		 << "\nAccount: " << database[CUSTOMER][index1].accountNumber << endl;
	cout << "New Balance: $" << database[CUSTOMER][index1].amount << endl;
	cout << "\nAccount: " << database[CUSTOMER][index2].accountNumber << endl;
	cout << "New Balance: $" << database[CUSTOMER][index2].amount << endl;

	logFile << fixed << showpoint << setprecision(2)
			<< database[CUSTOMER][index1].accountNumber << ": -$" << amount1 << endl;
	logFile << fixed << showpoint << setprecision(2)
			<< database[CUSTOMER][index2].accountNumber << ": +$" << amount1 << endl;
}

	//	Function to find transfer from account.
int find_customer_index_for_transfer(personType database[][MAX_ACCOUNTS], string msg) {
	int index = -1;
	string account;

	cout << "\nPlease enter the account number you wish to transfer " << msg << " :";
	cin >> account;

	for(int i = 0; i < MAX_ACCOUNTS; i++) {
		if(database[CUSTOMER][i].accountNumber == account)
		{
			index = i;
			break;
		}
	}
	return index;
}

	//	Function to print sum of all USD to screen.
void list_dollars(personType database[][MAX_ACCOUNTS], int counter[]) {
	float totalDollars = 0.0;
	int count = 0;

	for(int i = 0; i < counter[count]; i++) {
		totalDollars += database[count][i].amount;
	}
	cout << fixed << showpoint << setprecision(2)
		 << "\nVault balance in USD: $" << totalDollars << endl;
}

	//	Function to print names of all customers to screen.
void list_customers(personType database[][MAX_ACCOUNTS], int counter[]) {
	int count = 0;

	cout << "\nCustomer Records by Name:" << endl;
	cout << endl;
	for(int i = 0; i < counter[count]; i++) {
		cout << database[count][i].firstName << " " << database[count][i].lastName << endl;		
	}
}

	//	Function to list deposits.
void list_deposits() {
	ifstream addLog;
	string deposits[MAX_TRANSACTIONS];
	int i = 0;;

	addLog.open("deposits.txt");
	cout << "\nToday's Deposits:" << endl;
	cout << endl;

	while(!addLog.eof()) {
		getline(addLog, deposits[i]);
		cout << deposits[i] << endl;
		i++;
	}
}

	//	Function to list withdrawls.
void list_withdrawls() {
	ifstream subLog;
	string withdrawls[MAX_TRANSACTIONS];
	int i = 0;;

	subLog.open("withdrawls.txt");
	cout << "\nToday's Withdrawls:" << endl;
	cout << endl;

	while(!subLog.eof()) {
		getline(subLog, withdrawls[i]);
		cout << withdrawls[i] << endl;
		i++;
	}
}

	//	Function to list all transactions.
void list_transactions() {
	ifstream inLog;
	string transactions[MAX_TRANSACTIONS];
	int i = 0;

	inLog.open("log.txt");
	cout << "Today's Transactions:" << endl;
	cout << endl;
	while(!inLog.eof()) {
		getline(inLog, transactions[i]);
		cout << transactions[i] << endl;
		i++;
	}
}

	//	Function to delete account record.
void del_person(personType database[][MAX_ACCOUNTS], int counter[]) {
	int input = 0;
	int index = 0;
	string deletedAccountNum = "0000";
			
	cout << "Please choose the account type to delete: " << endl;
	cout << "1. Customer Account" << endl;
	cout << "2. Employee Account" << endl;
	cin >> input;

	if(input == 1)
		input = CUSTOMER;
	else
		input = EMPLOYEE;

	index = find_customer_index(database);

	if(database[input][index].accountNumber != deletedAccountNum) {
		database[input][index].accountNumber = deletedAccountNum;
		database[input][index].amount = -1;
		database[input][index].type = UNKNOWN;
		cout << "\nRecord successfully deleted." << endl;
	}
	else
		cout << "\nRecord not found." << endl;
}