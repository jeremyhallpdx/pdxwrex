#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
#include "classlist.h"
#include "classrecord.h"
#include "menus.h"


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
void access_menu(char selection, list database, int counter[], ofstream& depositLog, ofstream& withdrawlLog,ofstream& logFile) {
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
void customer_interface(list database, int counter[], ofstream& depositLog, ofstream& withdrawlLog, ofstream& logFile) {
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
void customer_functions(int option, list database, int counter[], ofstream& depositLog, ofstream& withdrawlLog, ofstream& logFile) {
		switch(option) {
		case 1:
			withdraw_funds(database, withdrawlLog, logFile);
			break;
		case 2:
			deposit_funds(database, depositLog, logFile);
			break;
		case 3:
			xfer_funds(database, logFile, withdrawlLog, depositLog);
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
void employee_interface(list database, int counter[], ofstream& depositLog, ofstream& withdrawlLog, ofstream& logFile) {
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
void employee_functions(int option, list database, int counter[], ofstream& depositLog, ofstream& withdrawlLog, ofstream& logFile) {
	switch(option) {
		case 1:
			withdraw_funds(database, withdrawlLog, logFile);
			break;
		case 2:
			deposit_funds(database, depositLog, logFile);
			break;
		case 3:
			xfer_funds(database, logFile, withdrawlLog, depositLog);
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
void manager_interface(list database, int counter[], ofstream& depositLog, ofstream& withdrawlLog, ofstream& logFile) {
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
void manager_functions(int option, list database, int counter[], ofstream& depositLog, ofstream& withdrawlLog, ofstream& logFile) {
	switch(option) {
		case 1:
			withdraw_funds(database, withdrawlLog, logFile);
			break;
		case 2:
			deposit_funds(database, depositLog, logFile);
			break;
		case 3:
			xfer_funds(database, logFile, withdrawlLog, depositLog);
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
void add_person(list database, int counter[]) {
	int i = 0;
	int input = 0;
		
	cout << "Please choose the new account type: " << endl;
	cout << "1. Customer Account" << endl;
	cout << "2. Employee Account" << endl;
	cin >> input;

	if(input == 1)
		input = CUSTOMER;
	else
		input = EMPLOYEE;
	i = counter[input];

	database.get_data();
	
	counter[input]++;
}

	//	Function to write database to text file.
void database_dump(list database, int counter[]) {
	int count = 0;
	ofstream outFile;
	outFile.open("database.txt");

	for(int i = 0; i < counter[count]; i++) {
		database.print_record(outFile);
	}
	outFile.close();
}

	//Function to read in database from text file
int database_load(list database) {
	int recordType = 0;
	int i = 0;
	int j = 0;					//	Variable for storing number of records in database.

	string tempFName;
	string tempLName;
	string tempAccount;
	int tempType = 0;
	float tempAmount = 0.0;
	ifstream inFile;
	
	inFile.open("database.txt");
	if(!inFile) {
		cout << "Database record does not exist or is corrupted!" << endl;
		cout << "Program Terminating." << endl;
		exit (-1);
	}
	while(!inFile.eof()) {
		++j;
		inFile >> tempFName >> tempLName >> tempAccount >> tempAmount >> tempType;
		database.set_record(tempFName, tempLName, tempAccount, tempType, tempAmount);
		i++;
	}	//	Ends while loop.
	return j;	//	Returns the number of lines(records) to main.
}



	//	Function to locate customer by account number.
int find_customer_index(list database) {
	int index = -1;
	string account;
	bool yes = false;

	cout << "\nPlease enter the account number: ";
	cin >> account;

	for(int i = 0; i < MAX_ACCOUNTS; i++) {
		yes = database.index_search(account);
		if(yes)
		{
			index = i;
			break;
		}
	}
	return index;
}

	//	Function to deposit funds from account.
void deposit_funds(list database, ofstream& depositLog, ofstream& logFile) {
	float amount1 = 0.0;
	int transType = DEPOSIT;
	int index = find_customer_index(database);
	
	cout << "\nPlease enter the amount you wish to deposit: $";
	cin >> amount1;

	float printAmt = database.call_deposit(amount1);

	cout << "\nYou deposited: $" << fixed << showpoint << setprecision(2) << amount1 << endl;
	cout << "The new balance is: $" << printAmt << endl;

	database.deposit_log(depositLog, amount1);
	database.log_file(logFile, amount1, transType);
}

	//	Function to withdraw funds from account.
void withdraw_funds(list database, ofstream& withdrawlLog, ofstream& logFile) {
	float amount1 = 0.0;
	int transType = WITHDRAWL;
	int index = find_customer_index(database);

	cout << "\nPlease enter the amount you wish to withdrawl: $";
	cin >> amount1;

	float printAmt = database.call_withdrawl(amount1);

	cout << "\nYou withdrew: $" << fixed << showpoint << setprecision(2) << amount1 << endl;
	cout << "The new balance is: $" << printAmt << endl;

	database.withdrawl_log(withdrawlLog, amount1);
	database.log_file(logFile, amount1, transType);
}

	//	Function to print out account balance.
void balance_inquiry(list database) {
	int index = find_customer_index(database);
	database.print_balance();
}

	//	Function to search by customer last name.
void search_customerName(list database) {
	int index = -1;
	string name1;
	bool yes = false;

	cout << "\nPlease enter the customer's last name as it appears on the Checks/Card for this account: " << endl;
	cout << "Last Name: ";
	cin >> name1;

	for(int i = 0; i < MAX_ACCOUNTS; i++) {
		yes = database.index_searchName(name1);
		if(yes)
		{
			index = i;
			break;
		}
	}
	
	database.show_record();
}

	//	Function to transfer funds between accounts.
void xfer_funds(list database, ofstream& logFile, ofstream& withdrawlLog, ofstream& depositLog) {
	float amount1 = 0.0;

	string msg = "from";
	int index1 = find_customer_index_for_transfer(database, msg);

	msg = "to";
	int index2 = find_customer_index_for_transfer(database, msg);

	cout << "\nPlease enter the amount you wish to transfer: $";
	cin >> amount1;

	database.call_withdrawl(amount1);
	database.call_deposit(amount1);

	database.print_balance();
	database.print_balance();
	
	int transType = WITHDRAWL;
	database.withdrawl_log(withdrawlLog, amount1);
	database.log_file(logFile, amount1, transType);

	transType = DEPOSIT;
	database.deposit_log(depositLog, amount1);
	database.log_file(logFile, amount1, transType);
}

	//	Function to find transfer account(s).
int find_customer_index_for_transfer(list database, string msg) {
	int index = -1;
	string account;
	bool yes = false;

	cout << "\nPlease enter the account number you wish to transfer " << msg << " :";
	cin >> account;

	for(int i = 0; i < MAX_ACCOUNTS; i++) {
		yes = database.index_search(account);
		if(yes) {
			index = i;
			break;
		}
	}
	return index;
}

	//	Function to print sum of all USD to screen.
void list_dollars(list database, int counter[]) {
	float totalDollars = 0.0;
	float sum = 0.0;
	int count = 0;

	for(int i = 0; i < counter[count]; i++) {
		sum = database.get_sum();
		totalDollars += sum;
	}
	cout << fixed << showpoint << setprecision(2)
		 << "\nVault balance in USD: $" << totalDollars << endl;
}

	//	Function to print names of all customers to screen.
void list_customers(list database, int counter[]) {
	int count = 0;

	cout << "\nCustomer Records by Name:" << endl;
	cout << endl;
	for(int i = 0; i < counter[count]; i++) {
		database.print_name();		
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
void del_person(list database, int counter[]) {
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
	database.del_record(deletedAccountNum);
}



