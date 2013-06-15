#ifndef MENUS_H
#define MENUS_H

#include <string>
#include <fstream>
using namespace std;


//	Funcs for Menu's:
void main_menu();
void access_menu(char, list, int[], ofstream&, ofstream&, ofstream&);
void customer_interface(list, int[], ofstream&, ofstream&, ofstream&);
void employee_interface(list, int[], ofstream&, ofstream&, ofstream&);
void manager_interface(list, int[], ofstream&, ofstream&, ofstream&);

	//	Funcs to get user inputs:
int get_option();

	//	Funcs for operations:
void customer_functions(int, list, int[], ofstream&, ofstream&, ofstream&);
void employee_functions(int, list, int[], ofstream&, ofstream&, ofstream&);
void manager_functions(int, list, int[], ofstream&, ofstream&, ofstream&);
int database_load(list);
void database_dump(list, int[]);
int find_customer_index(list);
int find_customer_index_for_transfer(list, string);

	//	Funcs for database manip.
void deposit_funds(list, ofstream&, ofstream&);
void withdraw_funds(list, ofstream&, ofstream&);
void balance_inquiry(list);
void xfer_funds(list, ofstream&, ofstream&, ofstream&);
void add_person(list, int[]);
void del_person(list, int[]);
void search_customerName(list);
void list_dollars(list, int counter[]);
void list_customers(list, int counter[]);
void list_deposits();
void list_withdrawls();
void list_transactions();

#endif