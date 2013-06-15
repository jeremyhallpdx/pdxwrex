#ifndef CLASSRECORD_H
#define CLASSRECORD_H

#include <string>
#include <fstream>
using namespace std;


//	Enumerated List for account types.
enum accountType {
	UNKNOWN = -1, CHECKING, SAVINGS, CREDITCARD, INSTANTACCESS
};

	//	Global Constants.
const int PEOPLE_TYPES = 2;			//	Constant for max record types in database.
const int MAX_ACCOUNTS = 50;		//	Constant for max records in database.
const int WITHDRAWL = 0;
const int DEPOSIT = 1;
const int TRANSACTION_TYPES = 3;	//	Constant for max transaction types.
const int MAX_TRANSACTIONS = 1000;	//	Constant for max transactions.

	// Database record.
class personType {
public:
	personType();
	personType(string, string, string, int, float);
	void set_record(string, string, string, int, float);
	void print_record(ofstream&);
	void show_record();
	void print_balance();
	bool index_search(string);
	bool index_searchName(string);
	float call_deposit(float);
	float call_withdrawl(float);
	void deposit_log(ofstream&, float);
	void withdrawl_log(ofstream&, float);
	void log_file(ofstream&, float, int);
	void get_data();
	float get_sum();
	void print_name();
	void del_record(string);

private:
	string firstName;
	string lastName;
	string accountNumber;
	float amount;
	accountType type;				//	Variable of enum accountType.
	
	float add_deposit(float);
	float sub_withdrawl(float);
	void print_deposit(ofstream&, float);
	void print_withdrawl(ofstream&, float);
};

#endif