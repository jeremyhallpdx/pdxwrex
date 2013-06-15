#ifndef MENUS_H
#define MENUS_H

#include <string>
#include <fstream>
using namespace std;


//	Funcs for Menu's:
void main_menu();
void access_menu(char, personType[], int[], ofstream&, ofstream&, ofstream&);
void customer_interface(personType[], int[], ofstream&, ofstream&, ofstream&);
void employee_interface(personType[], int[], ofstream&, ofstream&, ofstream&);
void manager_interface(personType[], int[], ofstream&, ofstream&, ofstream&);

	//	Funcs to get user inputs:
int get_option();

	//	Funcs for operations:
void customer_functions(int, personType[], int[], ofstream&, ofstream&, ofstream&);
void employee_functions(int, personType[], int[], ofstream&, ofstream&, ofstream&);
void manager_functions(int, personType[], int[], ofstream&, ofstream&, ofstream&);
int database_load(personType[]);
void database_dump(personType[], int[]);
int find_customer_index(personType[]);
int find_customer_index_for_transfer(personType[], string);

	//	Funcs for database manip.
void deposit_funds(personType[], ofstream&, ofstream&);
void withdraw_funds(personType[], ofstream&, ofstream&);
void balance_inquiry(personType[]);
void xfer_funds(personType[], ofstream&, ofstream&, ofstream&);
void add_person(personType[], int[]);
void del_person(personType[], int[]);
void search_customerName(personType[]);
void list_dollars(personType[], int counter[]);
void list_customers(personType[], int counter[]);
void list_deposits();
void list_withdrawls();
void list_transactions();

#endif