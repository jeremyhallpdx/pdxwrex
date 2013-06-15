#ifndef MENUS_H
#define MENUS_H

#include <string>
#include <fstream>
using namespace std;


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
void xfer_funds(personType[][MAX_ACCOUNTS], ofstream&, ofstream&, ofstream&);
void add_person(personType[][MAX_ACCOUNTS], int[]);
void del_person(personType[][MAX_ACCOUNTS], int[]);
void search_customerName(personType[][MAX_ACCOUNTS]);
void list_dollars(personType[][MAX_ACCOUNTS], int counter[]);
void list_customers(personType[][MAX_ACCOUNTS], int counter[]);
void list_deposits();
void list_withdrawls();
void list_transactions();

#endif