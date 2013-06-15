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
const int SIZE = 50;
const int MAX_PEOPLE_TYPE = 3;
const int MAX_ACCOUNTS = 50;
const int CUSTOMER = 0;
const int EMPLOYEE = 1;
const int MANAGER = 2;

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
string get_accountNum();

//	Funcs for operations:
void customer_functions(int, personType[][MAX_ACCOUNTS], int[]);
void employee_functions(int, personType[][MAX_ACCOUNTS], int[]);
void manager_functions(int, personType[][MAX_ACCOUNTS], int[]);
int database_load(personType[][MAX_ACCOUNTS]);
void database_dump(personType[][MAX_ACCOUNTS], int[]);

//	Funcs for database manip.
//	void deposit_funds(personType[][], const int);
//	void withdraw_funds(personType[][], const int);
//	void balance_inquiry(personType[][], const int);
//	void xfer_funds(personType[][], const int);
void add_person(personType[][MAX_ACCOUNTS], int[]);
//	void del_customer(persontType[][], const int);
//	void search_customer(personType[][], const int);
//	void list_dollars(personType[][], const int);
//	void list_customers(personType[][], const int);
//	void list_deposits(personType[][], const int);
//	void list_withdrawls(personType[][], const int);
//	void list_transactions(personType[][], cosnt int);

//	Main:
int main() {
	personType database[MAX_PEOPLE_TYPE][MAX_ACCOUNTS];		//	Two-dimensional array to contain database records and the type of record.
	int counter[MAX_PEOPLE_TYPE] = {0};	//	Array to keep track of the number of accounts of each type.
	int count = database_load(database);	//	Calls function to load records into database[][] and assign number of records to count.
	char selection;
	
	cout << "* Welcome to MyBANK *" << '\n' << count << " records successfully imported." << endl;
	
	do {
		main_menu();
		selection = get_option();
		access_menu(selection, database, counter);
	}while(selection != 4);

	database_dump(database, counter);
	return 0;
}

/******************
* Function Def's: *
*******************/

//	Gets integer selection from user.
int get_option() {
	
	int option = 0;
	
	cin.clear();
	cout << "\nPlease make your selection: ";
	cin >> option;
	cin.ignore(100, '\n');
		
	return option;
}

//	Gets account number from user.
string get_account_num() {
	string accountNum;
	cout << "Please enter your account number: " << endl;
	getline(cin, accountNum);

	return accountNum;
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
			cout << "withdraw_funds(database, CUSTOMER);" << endl;
			break;
		case 2:
			cout << "deposit_funds(database, CUSTOMER);" << endl;
			break;
		case 3:
			cout << "xfer_funds(database, CUSTOMER);" << endl;
			break;
		case 4:
			cout << "balance_inquiry(database, CUSTOMER);" << endl;
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
			cout << "withdraw_funds();" << endl;
			break;
		case 2:
			cout << "deposit_funds();" << endl;
			break;
		case 3:
			cout << "xfer_funds();" << endl;
			break;
		case 4:
			cout << "balance_inquiry(database);" << endl;
			break;
		case 5:
			add_person(database, counter);
			break;
		case 6:
			cout << "del_customer();" << endl;
			break;
		case 7:
			cout << "search_customer();" << endl;
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
			cout << "withdraw_funds();" << endl;
			break;
		case 2:
			cout << "deposit_funds();" << endl;
			break;
		case 3:
			cout << "xfer_funds();" << endl;
			break;
		case 4:
			cout << "balance_inquiry();" << endl;
			break;
		case 5:
			cout << "add_person();" << endl;
			break;
		case 6:
			cout << "del_customer();" << endl;
			break;
		case 7:
			cout << "search_customer();" << endl;
			break;
		case 8:
			cout << "list_dollars();" << endl;
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
		input = 0;
	else
		input = 1;
	i = counter[input];
	
	cout << "\nPlease enter the following information:" << endl;
	cout << "\nFirst Name: ";
	cin >> database[input][i].firstName;
	cout << "\nLast Name: "; 
	cin >> database[input][i].lastName;
	cout << "\nAccount Number: ";
	cin >> database[input][i].accountNumber;
	cout << "\nOpening Balance: ";
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
			cout << "Invalid Selection!" << endl;
			break;
	}	//	Ends switch statement.

	counter[input]++;
}

//	Function to write database to text file.
void database_dump(personType database[][MAX_ACCOUNTS], int counter[]) {
	int capacity = 0;
	string outName = "database.txt";
	ofstream outFile;	
	outFile.open(outName.c_str());

	for(int i = 0; i < counter[capacity]; ++i) {
		outFile << database[capacity][i].firstName << " " << database[capacity][i].lastName << " "
				<< database[capacity][i].accountNumber << " " << database[capacity][i].type << " "
				<< database[capacity][i].amount << endl;
	}
	outFile.close();
}

	//Function to read in database from text file... UNDER CONSTRUCTION!!
int database_load(personType database[][MAX_ACCOUNTS]) {
	int capacity = 0;
	int j = -1;					//	Variable for storing number of records in database.
	string tempFName;		//	Temp variable for storing First Name.
	string tempLName;		//	Temp variable for storing Last Name.
	string tempAccountNum;		//	Temp variable for storing Account Number.
	string tempName;
	int tempType;				//	Temp variable for storing Account Type.
	float tempBalance;			//	Temp variable for storing Account Balance.
	ifstream inFile;
	
	inFile.open("database.txt");
	if(!inFile) {
		cout << "Database record does not exist or is corrupted!" << endl;
		cout << "Program Terminating." << endl;
		return 0;
	}
	while(!inFile.eof()) {
		inFile >> tempFName >> tempLName >> tempAccountNum >> tempType >> tempBalance;
		j++;

		for(int i = 0; i < MAX_ACCOUNTS; i++) {
			database[capacity][i].firstName = tempFName.c_str();
			database[capacity][i].lastName = tempName.c_str();
			database[capacity][i].amount = tempBalance;
			database[capacity][i].accountNumber = tempAccountNum;
			switch(tempType) {	//	Switch statement for assignment of enum type.
				case -1:
					database[capacity][i].type = UNKNOWN;
					break;
				case 0:
					database[capacity][i].type = CHECKING;
					break;
				case 1:
					database[capacity][i].type = SAVINGS;
					break;
				case 2:
					database[capacity][i].type = CREDITCARD;
					break;
				case 3:
					database[capacity][i].type = INSTANTACCESS;
					break;
			}	//	Ends switch statement.
		}	//	Ends for loop.
	}	//	Ends while loop.
	
	inFile.close();
	return j;	//	Returns the number of lines(records) to main.
}