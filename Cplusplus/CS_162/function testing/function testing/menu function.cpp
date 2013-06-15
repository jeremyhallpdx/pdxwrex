#include <iostream>

using namespace std;

void mainMenu();
char getSelection();
int getOption();
void accessMenu(char selection);
void customerInterface();
int customerMenu();
void customerFunctions(int option);
void employeeInterface();
void managerInterface();

int main() {
	char selection;
	cout << "* Welcome to MyBANK *" << endl;
	mainMenu();
	selection = getSelection();
	accessMenu(selection);
	 
	
	return 0;
}

void mainMenu() {
	cout << "Please choose your access:" << endl;
	cout << "\n(C)ustomer Access" << endl;
	cout << "(E)mployee Access" << endl;
	cout << "(M)anager Access" << endl;
	cout << "(Q)uit Program" << endl;
	cout << endl;
}

//	Gets character selection from user.
char getSelection() {
	
	char option;

	cin.clear();
	cout << "Please make your selection: ";
	cin >> option;
	cin.ignore(100, '\n'); //remove any left over chars
	cout << endl;

	return tolower(option);
}

//	Gets integer selection from user.
int getOption() {
	
	int option;

	cout << "Please make your selection: ";
	cin >> option;
	cin.ignore(100, '\n'); //remove any left over chars
	cout << endl;

	return option;
}
void accessMenu(char selection) {
	switch(selection) {
	case 'c': 
		customerInterface();
		break;
	case 'e': 
		employeeInterface();
		break;
	case 'm': 
		managerInterface();
		break;
	case 'q': 
		cout << "Program Terminating..." << endl;
		break;
	default:
		cout << "Invalid selection! Program terminating." << endl;
		break;
	}
}

//	Root for customer functions.
void customerInterface() {
	int option = 0;

	option = customerMenu();
	customerFunctions(option);

	
}

//	Root for employee functions.
void employeeInterface() {
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
	cout << endl;
	cout << "Or (Q) to quit" << endl;
	
	option = getSelection();
}

//	Root for manager functions.
void managerInterface() {
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
	cout << endl;
	cout << "Or (Q) to quit" << endl;
		
	option = getSelection();
}

//	Selection screen for customer functions.
int customerMenu() {
	int option = 0;

	cout << "\nHow may I assist you today?" << endl;
	cout << endl;
	cout << "1." << "  " << "Withdraw Funds" << endl;
	cout << "2." << "  " << "Deposit Funds" << endl;
	cout << "3." << "  " << "Transfer Funds" << endl;
	cout << "4." << "  " << "Balance Inquiry" << endl;
	cout << "5." << "  " << "Exit Customer Menu" << endl;
		
	option = getOption();
	return option;
}

//	Customer functions.
void customerFunctions(int option) {
	switch(option) {
	case 1:
		cout << "withdrawfunds();" << endl;
		break;
	case 2:
		cout << "depositFunds();" << endl;
		break;
	case 3:
		cout << "xferFunds();" << endl;
		break;
	case 4:
		cout << "balanceInquiry();" << endl;
		break;
	case 5:
		cout << "Exiting Customer Menu..." << endl;
		break;
	default:
		cout << "Invalid Input!" << endl;
		break;
	}
}