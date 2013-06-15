/********************************************************************
 *	CS_162:		Assignment 1										*
 *	Author:		Jeremy Hall											*
 *	Date:		16-February-2009									*
 *	Sources:	Brandon Fasching, Greg Chambers, www.cplusplus.com.	*
 *	Desc:		MyBank is a program designed to store and maintain	*
 *				a small database of banking customers and their		*
 *				account information such as balance and account #.	*
 ********************************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

//	Enumerated List for account types.
enum accountType {
	UNKNOWN = -1, CHECKING, SAVINGS, CREDITCARD, INSTANTACCESS
};
//	Variable of accountType.
accountType type;
//	Global Constants.
const int SIZE = 50;				//	Constant for max number of chars in a name.
const int MAX_PEOPLE_TYPE = 2;		//	Constant for max record types in database.
const int MAX_ACCOUNTS = 50;		//	Constant for max records in database.
const int CUSTOMER = 0;				//	Constant for Customer Account.
const int EMPLOYEE = 1;				//	Constant for Employee Account.

// Database record.
struct personType{
	char firstName[SIZE];
	char lastName[SIZE];
	float amount;
	string accountNumber;
	accountType type;
};

//	Funcs for Menu's:
void main_menu();
void access_menu(char, personType [][MAX_ACCOUNTS], int[]);
void customer_interface(personType[][MAX_ACCOUNTS], int[]);
void employee_interface(personType[][MAX_ACCOUNTS], int[]);
void manager_interface(personType[][MAX_ACCOUNTS], int[]);

//	Funcs to get user inputs:
int get_option();

//	Funcs for operations:
void customer_functions(int, personType[][MAX_ACCOUNTS], int[]);
void employee_functions(int, personType[][MAX_ACCOUNTS], int[]);
void manager_functions(int, personType[][MAX_ACCOUNTS], int[]);
int database_load(personType[][MAX_ACCOUNTS]);
void database_dump(personType[][MAX_ACCOUNTS], int[]);
int find_customer_index(personType[][MAX_ACCOUNTS]);
int find_customer_index_for_transfer(personType[][MAX_ACCOUNTS], string);


//	Funcs for database manip.
void deposit_funds(personType[][MAX_ACCOUNTS]);
void withdraw_funds(personType[][MAX_ACCOUNTS]);
void balance_inquiry(personType[][MAX_ACCOUNTS]);
void xfer_funds(personType[][MAX_ACCOUNTS]);
void add_person(personType[][MAX_ACCOUNTS], int[]);
//	void del_customer(persontType[][], const int);
void search_customerName(personType[][MAX_ACCOUNTS]);
void list_dollars(personType[][MAX_ACCOUNTS], int counter[]);
//	void list_customers(personType[][], const int);
//	void list_deposits(personType[][], const int);
//	void list_withdrawls(personType[][], const int);
//	void list_transactions(personType[][], cosnt int);

//	Main:
int main() {												
	personType database[MAX_PEOPLE_TYPE][MAX_ACCOUNTS];		//	Array of structs to contain database records and the type of record.
	int counter[MAX_PEOPLE_TYPE] = {0, 0};				//	Array to keep track of the number of accounts of each type.
	int count = database_load(database);		//	Calls function to load records into database[][] and assign number of records to count.
	int selection;

	cout << "* Welcome to MyBANK *" << endl;
	cout << '\n' << count << " records successfully imported." << endl;
	counter[0] = count;
	do {
		main_menu();
		selection = get_option();
		access_menu(selection, database, counter);
	}while(selection != 4);

	database_dump(database, counter);		//	Outputs the array database[][] into a text file.
	return 0;
}

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
void access_menu(char selection, personType database[][MAX_ACCOUNTS], int counter[]) {
	switch(selection) {
	case 1: 
		customer_interface(database, counter);
		break;
	case 2: 
		employee_interface(database, counter);
		break;
	case 3: 
		manager_interface(database, counter);
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
void customer_interface(personType database[][MAX_ACCOUNTS], int counter[]) {
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
		customer_functions(option, database, counter);
	}while(option != 5);
}


//	Customer functions.
void customer_functions(int option, personType database[][MAX_ACCOUNTS], int counter[]) {
		switch(option) {
		case 1:
			withdraw_funds(database);
			break;
		case 2:
			deposit_funds(database);
			break;
		case 3:
			xfer_funds(database);
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
void employee_interface(personType database[][MAX_ACCOUNTS], int counter[]) {
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
		employee_functions(option, database, counter);
	}while(option != 8);
}

//	Employee Functions.
void employee_functions(int option, personType database[][MAX_ACCOUNTS], int counter[]) {
	switch(option) {
		case 1:
			withdraw_funds(database);
			break;
		case 2:
			deposit_funds(database);
			break;
		case 3:
			xfer_funds(database);
			break;
		case 4:
			balance_inquiry(database);
			break;
		case 5:
			add_person(database, counter);
			break;
		case 6:
			cout << "del_customer();" << endl;
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
void manager_interface(personType database[][MAX_ACCOUNTS], int counter[]) {
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
		cout << "10." << " " << "List all deposits by date" << endl;
		cout << "11." << " " << "List all withrawls by date" << endl;
		cout << "12." << " " << "List all transactions by date" << endl;
		cout << "13." << " " << "Exit Manager Menu" << endl;
		
		option = get_option();
		manager_functions(option, database, counter);
	}while(option != 13);
}

//	Manager Functions.
void manager_functions(int option, personType database[][MAX_ACCOUNTS], int counter[]) {
	switch(option) {
		case 1:
			withdraw_funds(database);
			break;
		case 2:
			deposit_funds(database);
			break;
		case 3:
			xfer_funds(database);
			break;
		case 4:
			balance_inquiry(database);
			break;
		case 5:
			add_person(database, counter);
			break;
		case 6:
			cout << "del_customer();" << endl;
			break;
		case 7:
			search_customerName(database);
			break;
		case 8:
			list_dollars(database, counter);
			break;
		case 9:
			cout << "list_customers();" << endl;
			break;
		case 10:
			cout << "list_deposits();" << endl;
			break;
		case 11:
			cout << "list_withdrawls();" << endl;
			break;
		case 12:
			cout << "list_transactions();" << endl;
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
void deposit_funds(personType database[][MAX_ACCOUNTS]) {
	float amount1 = 0.0;
	int index = find_customer_index(database);
	cout << "\nPlease enter the amount you wish to deposit: $";
	cin >> amount1;

	database[CUSTOMER][index].amount += amount1;

	cout << "\nYou deposited: $" << fixed << showpoint << setprecision(2) << amount1 << endl;
	cout << "The new balance is: $" << database[CUSTOMER][index].amount << endl;
}

	//	Function to withdraw funds from account.
void withdraw_funds(personType database[][MAX_ACCOUNTS]) {
	float amount1 = 0.0;
	int index = find_customer_index(database);
	cout << "\nPlease enter the amount you wish to withdrawl: $";
	cin >> amount1;

	database[CUSTOMER][index].amount -= amount1;

	cout << "\nYou withdrew: $" << fixed << showpoint << setprecision(2) << amount1 << endl;
	cout << "The new balance is: $" << database[CUSTOMER][index].amount << endl;
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
void xfer_funds(personType database[][MAX_ACCOUNTS]) {
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