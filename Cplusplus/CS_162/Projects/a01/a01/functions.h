#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
using namespace std;

//	Enumerated List for account types.
enum accountType {
	UNKNOWN = -1, CHECKING, SAVINGS, CREDITCARD, INSTANTACCESS
};


	//	Global Constants.
const int SIZE = 50;				//	Constant for max number of chars in a name.
const int PEOPLE_TYPES = 2;			//	Constant for max record types in database.
const int MAX_ACCOUNTS = 50;		//	Constant for max records in database.
const int CUSTOMER = 0;				//	Constant for Customer Account.
const int EMPLOYEE = 1;				//	Constant for Employee Account.
const int TRANSACTION_TYPES = 3;	//	Constant for max transaction types.
const int MAX_TRANSACTIONS = 1000;	//	Constant for max transactions.

	// Database record.
struct personType {
	char firstName[SIZE];
	char lastName[SIZE];
	float amount;
	string accountNumber;
	accountType type;				//	Variable of enum accountType.
};

//	Funcs for Menu's:
void main_menu();
void access_menu(char, personType[][MAX_ACCOUNTS], int[], ofstream&, ofstream&, ofstream&);
void customer_interface(personType[][MAX_ACCOUNTS], int[], ofstream&, ofstream&, ofstream&);
void employee_interface(personType[][MAX_ACCOUNTS], int[], ofstream&, ofstream&, ofstream&);
void manager_interface(personType[][MAX_ACCOUNTS], int[], ofstream&, ofstream&, ofstream&);

	//	Funcs to get user inputs:
int get_option();

	//	Funcs for operations:
void customer_functions(int, personType[][MAX_ACCOUNTS], int[], ofstream&, ofstream&, ofstream&);
void employee_functions(int, personType[][MAX_ACCOUNTS], int[], ofstream&, ofstream&, ofstream&);
void manager_functions(int, personType[][MAX_ACCOUNTS], int[], ofstream&, ofstream&, ofstream&);
int database_load(personType[][MAX_ACCOUNTS]);
void database_dump(personType[][MAX_ACCOUNTS], int[]);
int find_customer_index(personType[][MAX_ACCOUNTS]);
int find_customer_index_for_transfer(personType[][MAX_ACCOUNTS], string);

	//	Funcs for database manip.
void deposit_funds(personType[][MAX_ACCOUNTS], ofstream&, ofstream&);
void withdraw_funds(personType[][MAX_ACCOUNTS], ofstream&, ofstream&);
void balance_inquiry(personType[][MAX_ACCOUNTS]);
void xfer_funds(personType[][MAX_ACCOUNTS], ofstream&);
void add_person(personType[][MAX_ACCOUNTS], int[]);
void del_person(personType[][MAX_ACCOUNTS], int[]);
void search_customerName(personType[][MAX_ACCOUNTS]);
void list_dollars(personType[][MAX_ACCOUNTS], int counter[]);
void list_customers(personType[][MAX_ACCOUNTS], int counter[]);
void list_deposits();
void list_withdrawls();
void list_transactions();

#endif