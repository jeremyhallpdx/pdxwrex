#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//	Enumerated List for account types.
enum accountType {
	Unknown = -1, Checking, Savings, CreditCard, InstantAccess
};
//	Variable of accountType.
accountType type;

//	Global Constants.
const int FIRST = 15; 
const int LAST = 25;
const int MAX_PEOPLE_TYPE = 3;
const int MAX_ACCOUNTS = 50;

// Database record.
struct csRecord{
	char name[FIRST][LAST];
	float amount;
	accountType type;
};

//	Funcs for Menu's:
void main_menu();
void access_menu(char selection);
void customer_interface();
int customer_menu();
void employee_interface();
int employee_menu();
void manager_interface();
int manager_menu();

//	Funcs to get user inputs:
char get_selection();
int get_option();
string get_accountNum();

//	Funcs for operations:
void customer_functions(int option);
void employee_functions(int option);
void manager_functions(int option);

//	Funcs for database manip.
//	void deposit_funds();
//	void withdraw_funds();
//	void balance_inquiry();
//	void xfer_funds();
//	void add_customer();
//	void del_customer();
//	void search_customer();
//	void list_dollars();
//	void list_customers();
//	void list_deposits();
//	void list_withdrawls();
//	void list_transactions();

//	Main:
int main() {
	char selection;
	cout << "* Welcome to MyBANK *" << endl;
	do {
		main_menu();
		selection = get_selection();
		access_menu(selection);
	}while(selection != 'q');
		
	return 0;
}

/******************
* Function Def's: *
*******************/

//	Gets character selection from user.
char get_selection() {
	
	char option;

	cin.clear();
	cout << "\nPlease make your selection: ";
	cin >> option;
	cin.ignore(100, '\n');	//	Removes any left over characters.
	cout << endl;

	return tolower(option);
}

//	Gets integer selection from user.
int get_option() {
	
	int option;

	cin.clear();
	cout << "Please make your selection: ";
	cin >> option;
	cin.ignore(100, '\n');	//	Removes any left over characters.
	cout << endl;

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
	cout << "\n(C)ustomer Access" << endl;
	cout << "(E)mployee Access" << endl;
	cout << "(M)anager Access" << endl;
	cout << "(Q)uit Program" << endl;
}

//	Switch between Main Menu and desired interface.
void access_menu(char selection) {
	switch(selection) {
	case 'c': 
		customer_interface();
		break;
	case 'e': 
		employee_interface();
		break;
	case 'm': 
		manager_interface();
		break;
	case 'q':
		cout << "Exiting program..." << endl;
		break;
	default:
		cout << "Invalid input! Please try again..." << endl;
		cout << endl;
		break;
	}//	Ends switch statement.
}

//	Root for Customer functions.
void customer_interface() {
	int option = 0;

	do {
		option = customer_menu();
		customer_functions(option);
	}while(option != 5);
}

//	Selection screen for Customer functions.
int customer_menu() {
	int option = 0;

	cout << "\nHow may I assist you today?" << endl;
	cout << endl;
	cout << "1." << "  " << "Withdraw Funds" << endl;
	cout << "2." << "  " << "Deposit Funds" << endl;
	cout << "3." << "  " << "Transfer Funds" << endl;
	cout << "4." << "  " << "Balance Inquiry" << endl;
	cout << "5." << "  " << "Exit Customer Menu" << endl;
	
	option = get_option();

	return option;
}

//	Customer functions.
void customer_functions(int option) {
		switch(option) {
		case 1:
			cout << "withdraw_funds(string accountNum);" << endl;
			break;
		case 2:
			cout << "deposit_funds(string accountNum);" << endl;
			break;
		case 3:
			cout << "xfer_funds(string accountNum);" << endl;
			break;
		case 4:
			cout << "balance_inquiry(string accountNum);" << endl;
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
void employee_interface() {
	int option = 0;
	
	do {
		option = employee_menu();
		employee_functions(option);
	}while(option != 8);
}

//	Selection screen for Employee Menu.
int employee_menu() {
	int option = 0;

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

	return option;
}

//	Employee Functions.
void employee_functions(int option) {
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
			cout << "add_customer();" << endl;
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
void manager_interface() {
	int option = 0;
	
	do {
		option = manager_menu();
		manager_functions(option);
	}while(option != 13);
}

//	Selection screen for Manager Menu.
int manager_menu() {
	int option = 0;

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
	
	return option;
}

//	Manager Functions.
void manager_functions(int option) {
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
			cout << "add_customer();" << endl;
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