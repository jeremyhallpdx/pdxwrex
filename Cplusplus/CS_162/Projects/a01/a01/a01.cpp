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

#include "functions.h"

	//	Main:
int main() {
	personType database[PEOPLE_TYPES][MAX_ACCOUNTS];		//	Array of structs to contain database records and the type of record.
	int counter[PEOPLE_TYPES] = {0, 0};				//	Array to keep track of the number of accounts of each type.
	int count = database_load(database);		//	Calls function to load records into database[][] and assign number of records to count.
	int selection;
	ofstream depositLog;
	ofstream withdrawlLog;
	ofstream logFile;

	logFile.open("log.txt");					//	Opens text file for output of all transactions.
	depositLog.open("deposits.txt");			//	Opens text file for output of all deposits.
	withdrawlLog.open("withdrawls.txt");		//	Opens text file for output of all withdrawls.

	cout << "* Welcome to MyBANK *" << endl;
	cout << '\n' << count << " records successfully imported." << endl;
	counter[0] = count;
	do {
		main_menu();
		selection = get_option();
		access_menu(selection, database, counter, depositLog, withdrawlLog, logFile);
	}while(selection != 4);

	database_dump(database, counter);		//	Outputs the array database[][] into a text file.
	logFile.close();						//	Closes text file for transactions.
	depositLog.close();						//	Closes text file for deposits.
	withdrawlLog.close();					//	Closes text file for withdrawls.

	return 0;
}