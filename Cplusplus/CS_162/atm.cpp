#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>
#include <cctype>

using namespace std;

const int NUMBER_OF_ACCOUNTS = 3;
const int MAX_NUMBER_OF_CUSTOMERS = 20;
const int MANAGER_CUSTOMER_ID = 1;
const int TELLER_CUSTOMER_ID = 2;
const int CUSTOMER_COLUMN = 0;
const int PIN_COLUMN = 1;

enum accountType
{
	unknown       = -1, 
	Checking      = 0, 
	Savings       = 1, 
	CreditCard    = 2, 
	InstantAccess = 3
};

struct accountStruct
{
	accountType type;
	float amount;
};

struct customerRecord
{
	int customerNumber;
	string firstName, lastName;
	int pin;
	string address, town, state, zip, phone;
	accountStruct account[NUMBER_OF_ACCOUNTS];
};

bool loadData(customerRecord dataBase[], int securityDatabase[][2]);
int customerLogin(int securityDataBase[][2]);
bool managerInterface(customerRecord dataBase[], int securityDatabase[][2], ofstream &logFile);
bool tellerInterface(customerRecord dataBase[], int securityDatabase[][2], ofstream &logFile);
void customerInterface(int customerNumber, customerRecord dataBase[], ofstream &logFile);
string accountString(accountType account);

int findCustomerIndex(int customerNumber, customerRecord dataBase[]);
int findCustomerIndexByName(string firstName, string lastName, customerRecord dataBase[]);

void DepositMoney(int customerIndex, customerRecord dataBase[], ofstream &logFile);
void WithdrawlMoney(int customerIndex, customerRecord dataBase[], ofstream &logFile);
void TransferMoney(int customerIndex, customerRecord dataBase[], ofstream &logFile);

void deleteCustomer(customerRecord dataBase[], int securityDatabase[][2]);
void addCustomer(customerRecord dataBase[], int securityDatabase[][2]);

int CountCustomers(customerRecord dataBase[]);
float CountMoney(customerRecord dataBase[]);

void PrintDatabase(customerRecord dataBase[], int securityDatabase[][2]);

int main()
{
	ofstream logFile;
	customerRecord dataBase[MAX_NUMBER_OF_CUSTOMERS];
	int securityDatabase[MAX_NUMBER_OF_CUSTOMERS][2];
	
	for(int i = 0; i < MAX_NUMBER_OF_CUSTOMERS; i++)
	{
		dataBase[i].customerNumber = -1;
		securityDatabase[i][0] = -1;
		securityDatabase[i][1] = -1;
	}
	
	logFile.open("AtmLog.txt");
	logFile << fixed << showpoint;
	logFile << setprecision(2);

	if(loadData(dataBase, securityDatabase) == false)
		return -1;

	cout << fixed << showpoint;
	cout << setprecision(2);
	
	cout <<  "*********************************************" << endl;
	cout << "Welcome to the ATM - Personal Bank Teller" << endl;
	cout <<  "*********************************************" << endl;

	bool quit = false;
	while(quit == false)
	{
		int customerNumber = customerLogin(securityDatabase);
		if (customerNumber == MANAGER_CUSTOMER_ID)
			quit = managerInterface(dataBase, securityDatabase, logFile);
		else if (customerNumber == TELLER_CUSTOMER_ID)
			quit = tellerInterface(dataBase,securityDatabase, logFile);
		else
			customerInterface(customerNumber, dataBase, logFile);
	}
}

void PrintDatabase(customerRecord dataBase[], int securityDatabase[][2])
{
	for(int i =0; i < MAX_NUMBER_OF_CUSTOMERS; i++)
	{
		customerRecord c = dataBase[i];
		cout << c.customerNumber << ", "
		     << c.pin << ","
			 << c.firstName << ", "
			 << c.lastName << endl;
	}
	for(int i =0; i < MAX_NUMBER_OF_CUSTOMERS; i++)
	{
		cout << "Customer=" << securityDatabase[i][CUSTOMER_COLUMN] 
		     << " Pin=" << securityDatabase[i][PIN_COLUMN] << endl;
	}
	
}


bool loadData(customerRecord dataBase[], int securityDatabase[][2])
{
	string inputFile;
	string txtFileName;

	cout << "Please enter the pathname to the .txt file you would like to open." << endl;
	cout << endl;
	//cin >> txtFileName;
	txtFileName = "Customer.txt";
	cout << endl;

	ifstream inData;
	
	inData.open(txtFileName.c_str());
	
	if (!inData)
	{
		cout << "The file could not be found." << endl;
		return false;
	}

	string customerNumber, firstName, lastName, pin, address, town,
		state, zip, phone;
	string savings, savingsAmount, checking, checkingAmount, creditCard, creditCardAmount;
	int count = 0;
	
	while (!inData.eof())
	{
		getline (inData, customerNumber);
		getline (inData, firstName);
		getline (inData, lastName);
		getline (inData, pin);
		getline (inData, address);
		getline (inData, town);
		getline (inData, state);
		getline (inData, zip);
		getline (inData, phone);
		getline (inData, savings);
		getline (inData, savingsAmount);
		getline (inData, checking);
		getline (inData, checkingAmount);
		getline (inData, creditCard);
		getline (inData, creditCardAmount);
		//cout << "customerNumber = " << customerNumber << " pin = " << pin << " firstName = " << firstName
		//     << " lastName = " << lastName << endl;

		dataBase[count].customerNumber = atoi(customerNumber.c_str());
		dataBase[count].firstName = firstName;
		dataBase[count].lastName = lastName;
		dataBase[count].pin = atoi(pin.c_str());
		dataBase[count].address = address;
		dataBase[count].town = town;
		dataBase[count].state = state;
		dataBase[count].zip = zip;
		dataBase[count].phone = phone;
		if(savings != "-1")
		{
			dataBase[count].account[Savings].type = Savings;
			dataBase[count].account[Savings].amount = (float)atof(savingsAmount.c_str());
		}
		else
		{
			dataBase[count].account[Savings].type = unknown;
			dataBase[count].account[Savings].amount = -1;
		}
		if(checking != "-1")
		{
			dataBase[count].account[Checking].type = Checking;
			dataBase[count].account[Checking].amount = (float)atof(checkingAmount.c_str());
		}
		else
		{
			dataBase[count].account[Checking].type = unknown;
			dataBase[count].account[Checking].amount = -1;
		}
		if(creditCard != "-1")
		{
			dataBase[count].account[CreditCard].type = CreditCard;
			dataBase[count].account[CreditCard].amount = (float)atof(creditCardAmount.c_str());
		}
		else
		{
			dataBase[count].account[CreditCard].type = unknown;
			dataBase[count].account[CreditCard].amount = -1;
		}

		getline (inData, creditCardAmount);  // Grab the blank line between customers

		securityDatabase[count][CUSTOMER_COLUMN] = dataBase[count].customerNumber;
		securityDatabase[count][PIN_COLUMN] = dataBase[count].pin;
		
		// Increment count at the end of the customer
		count++;
	}

	return true;
}

int customerLogin(int securityDataBase[][2])
{
	bool customerExists = false;
	int returnCustomerNumber = -1;
	int count = 0;
	while(customerExists == false)
	{
		int customerNumber,pinNumber;
		cout << "Please enter Customer Number: " << endl;
		cin >> customerNumber;
		cout << "Please enter PIN Number: " << endl;
		cin >> pinNumber;

		for(int i = 0; i < MAX_NUMBER_OF_CUSTOMERS; i++)
		{
			if(    securityDataBase[i][CUSTOMER_COLUMN] == customerNumber
				&& securityDataBase[i][PIN_COLUMN] == pinNumber
				|| customerNumber == TELLER_CUSTOMER_ID
				|| customerNumber == MANAGER_CUSTOMER_ID)
			{
				returnCustomerNumber = customerNumber;
				customerExists = true;
				break;
			}
		}

		if(customerExists == true)
			break;
			
		cout << "Invalid ID.  Please try again... Looooser!" << endl;
		count++;
		if(count == 3)
		{
			cout << "Warning police have been notified of your incompetent hacking attempt." << endl;
			cout << "Please step away from the ATM and place your hands on your head!" << endl;
			cout << "Have a nice day!" << endl;
		}
	}

	return returnCustomerNumber;
}

bool managerInterface(customerRecord dataBase[], int securityDatabase[][2], ofstream &logFile)
{
	bool quit = false;
	int customerIndex, customerNumber;
	char cmd;

	cout << "Good Day: Manager" << endl;
	
	bool done = false;
	while(done == false)
	{
		cout << endl << "Choose from the following: (F) Find Customer, (B) Balance, (D) Deposit, (W) Withdrawl, (T) Transfer, (C) Delete Customer, (A) Add Customer, (L) Log out, (Q) Quit ... " << endl << "--> ";
		cout << "(Z) Total Number Customers, (Y) Total Amount of Money in Bank" << endl;
		cin >> cmd;
		cmd = tolower(cmd);	
		
		switch(cmd)
		{
		case 'z':
			cout << "Total Number of Customers: " << CountCustomers(dataBase) << endl;
			break;
		case 'y':
			cout << "Total Amount of Money: " << CountMoney(dataBase) << endl;
			break;
		case 'b':
			cout << "Input the customer number that you wish to use: ";
			cin >> customerNumber;
			// Get the index of the customer number
			customerIndex = findCustomerIndex(customerNumber, dataBase);
			cout << endl << "Accessing Account of " << dataBase[customerIndex].firstName << " " << dataBase[customerIndex].lastName << endl << endl;
			if(dataBase[customerIndex].account[Savings].type == Savings)
				cout << "Savings Balance     -> " << dataBase[customerIndex].account[Savings].amount << endl;
			if(dataBase[customerIndex].account[Checking].type == Checking)
				cout << "Checking Balance    -> " << dataBase[customerIndex].account[Checking].amount << endl;
			if(dataBase[customerIndex].account[CreditCard].type == CreditCard)
				cout << "Credit Card Balance -> " << dataBase[customerIndex].account[CreditCard].amount << endl;
			break;
		case 'd':
			cout << "Input the customer number that you wish to use: ";
			cin >> customerNumber;
			// Get the index of the customer number
			customerIndex = findCustomerIndex(customerNumber, dataBase);
			cout << endl << "Accessing Account of " << dataBase[customerIndex].firstName << " " << dataBase[customerIndex].lastName << endl << endl;
			DepositMoney(customerIndex, dataBase, logFile);
			break;
		case 'w':
			cout << "Input the customer number that you wish to use: ";
			cin >> customerNumber;
			// Get the index of the customer number
			customerIndex = findCustomerIndex(customerNumber, dataBase);
			cout << endl << "Accessing Account of " << dataBase[customerIndex].firstName << " " << dataBase[customerIndex].lastName << endl << endl;
			WithdrawlMoney(customerIndex, dataBase, logFile);
			break;
		case 't':
			cout << "Input the customer number that you wish to use: ";
			cin >> customerNumber;
			// Get the index of the customer number
			customerIndex = findCustomerIndex(customerNumber, dataBase);
			cout << endl << "Accessing Account of " << dataBase[customerIndex].firstName << " " << dataBase[customerIndex].lastName << endl << endl;
			TransferMoney(customerIndex, dataBase, logFile);
			break;
		case 'c':
			deleteCustomer(dataBase, securityDatabase);
			break;
		case 'a':
			addCustomer(dataBase, securityDatabase);
			break;
		case 'f':
			{
				string firstName, lastName;
				cout << "Enter First Name to search for: ";
				cin >> firstName;
				cout << "Enter Last Name to search for: ";
				cin >> lastName;
				int index = findCustomerIndexByName(firstName, lastName, dataBase);
				if(index == -1)
				{
					cout << "Couldn't find the customer: " << firstName << " " << lastName << endl;
				}
				else
				{
					cout << "Found customer.  ID = " << dataBase[index].customerNumber << endl;
				}
			}
			break;
		case 'l':
			done = true;
			break;
		case 'q':
			quit = true;
			done = true;
			break;
		default:
			cout << "I didn't understand the input :" << cmd << ": Please try again." << endl;
		}
	}
	
	return quit;
}

// Returns a bool indicating whether the teller wishes to quit
bool tellerInterface(customerRecord dataBase[], int securityDatabase[][2], ofstream &logFile)
{
	bool quit = false;
	int customerIndex, customerNumber;
	char cmd;

	cout << "Good Day: Teller" << endl;
	
	bool done = false;
	while(done == false)
	{
		cout << endl << "Choose from the following: (F) Find Customer, (B) Balance, (D) Deposit, (W) Withdrawl, (T) Transfer, (C) Delete Customer, (A) Add Customer, (L) Log out, (Q) Quit ... " << endl << "--> ";
		cin >> cmd;
		cmd = tolower(cmd);
		
		
		switch(cmd)
		{
		case 'b':
			cout << "Input the customer number that you wish to use: ";
			cin >> customerNumber;
			// Get the index of the customer number
			customerIndex = findCustomerIndex(customerNumber, dataBase);
			cout << endl << "Accessing Account of " << dataBase[customerIndex].firstName << " " << dataBase[customerIndex].lastName << endl << endl;
			if(dataBase[customerIndex].account[Savings].type == Savings)
				cout << "Savings Balance     -> " << dataBase[customerIndex].account[Savings].amount << endl;
			if(dataBase[customerIndex].account[Checking].type == Checking)
				cout << "Checking Balance    -> " << dataBase[customerIndex].account[Checking].amount << endl;
			if(dataBase[customerIndex].account[CreditCard].type == CreditCard)
				cout << "Credit Card Balance -> " << dataBase[customerIndex].account[CreditCard].amount << endl;
			break;
		case 'd':
			cout << "Input the customer number that you wish to use: ";
			cin >> customerNumber;
			// Get the index of the customer number
			customerIndex = findCustomerIndex(customerNumber, dataBase);
			cout << endl << "Accessing Account of " << dataBase[customerIndex].firstName << " " << dataBase[customerIndex].lastName << endl << endl;
			DepositMoney(customerIndex, dataBase, logFile);
			break;
		case 'w':
			cout << "Input the customer number that you wish to use: ";
			cin >> customerNumber;
			// Get the index of the customer number
			customerIndex = findCustomerIndex(customerNumber, dataBase);
			cout << endl << "Accessing Account of " << dataBase[customerIndex].firstName << " " << dataBase[customerIndex].lastName << endl << endl;
			WithdrawlMoney(customerIndex, dataBase, logFile);
			break;
		case 't':
			cout << "Input the customer number that you wish to use: ";
			cin >> customerNumber;
			// Get the index of the customer number
			customerIndex = findCustomerIndex(customerNumber, dataBase);
			cout << endl << "Accessing Account of " << dataBase[customerIndex].firstName << " " << dataBase[customerIndex].lastName << endl << endl;
			TransferMoney(customerIndex, dataBase, logFile);
			break;
		case 'c':
			deleteCustomer(dataBase, securityDatabase);
			break;
		case 'a':
			addCustomer(dataBase, securityDatabase);
			break;
		case 'f':
			{
				string firstName, lastName;
				cout << "Enter First Name to search for: ";
				cin >> firstName;
				cout << "Enter Last Name to search for: ";
				cin >> lastName;
				int index = findCustomerIndexByName(firstName, lastName, dataBase);
				if(index == -1)
				{
					cout << "Couldn't find the customer: " << firstName << " " << lastName << endl;
				}
				else
				{
					cout << "Found customer.  ID = " << dataBase[index].customerNumber << endl;
				}
			}
			break;
		case 'l':
			done = true;
			break;
		case 'q':
			quit = true;
			done = true;
			break;
		default:
			cout << "I didn't understand the input :" << cmd << ": Please try again." << endl;
		}
	}
	
	return quit;
}

void deleteCustomer(customerRecord dataBase[], int securityDatabase[][2])
{
	int customerNumber, customerIndex;
	
	cout << "Input the customer number that you wish to use: ";
	cin >> customerNumber;
	
	// Get the index of the customer number
	customerIndex = findCustomerIndex(customerNumber, dataBase);
	
	if(customerIndex >= 0)
	{
		cout << "Deleting customer: " << dataBase[customerIndex].firstName << " " << dataBase[customerIndex].lastName << endl;
		dataBase[customerIndex].customerNumber = -1;
		securityDatabase[customerIndex][CUSTOMER_COLUMN] = -1;
	}
	else
	{
		cout << "Unable to find the customer number: " << customerNumber << endl;
	}
}

void customerInterface(int customerNumber, customerRecord dataBase[], ofstream &logFile)
{
	int customerIndex = findCustomerIndex(customerNumber, dataBase);
	char cmd;

	cout << "Good Day: " << dataBase[customerIndex].firstName << " " 
		<< dataBase[customerIndex].lastName << endl;
	
	bool done = false;
	while(done == false)
	{
		cout << endl << "Choose from the following: (B) Balance, (D) Deposit, (W) Withdrawl, (T) Transfer, (L) Log out ... " << endl << "--> ";
		cin >> cmd;
		cmd = tolower(cmd);
		switch(cmd)
		{
		case 'b':
			if(dataBase[customerIndex].account[Savings].type == Savings)
				cout << "Savings Balance     -> " << dataBase[customerIndex].account[Savings].amount << endl;
			if(dataBase[customerIndex].account[Checking].type == Checking)
				cout << "Checking Balance    -> " << dataBase[customerIndex].account[Checking].amount << endl;
			if(dataBase[customerIndex].account[CreditCard].type == CreditCard)
				cout << "Credit Card Balance -> " << dataBase[customerIndex].account[CreditCard].amount << endl;
			break;
		case 'd':
			DepositMoney(customerIndex, dataBase, logFile);
			break;
		case 'w':
			WithdrawlMoney(customerIndex, dataBase, logFile);
			break;
		case 't':
			TransferMoney(customerIndex, dataBase, logFile);
			break;

		case 'l':
			done = true;
			break;
		default:
			cout << "I didn't understand the input :" << cmd << ": Please try again." << endl;
		}
	}

	
}

void DepositMoney(int customerIndex, customerRecord dataBase[], ofstream &logFile)
{
	cout << "Which account would you like to deposit into:" << endl;
	if(dataBase[customerIndex].account[Savings].type == Savings)
		cout << "(s) Savings" << endl;
	if(dataBase[customerIndex].account[Checking].type == Checking)
		cout << "(c) Checking " << endl;
	if(dataBase[customerIndex].account[CreditCard].type == CreditCard)
		cout << "(d) Credit Card " << endl;
	cout << "--> ";
	
	char cmd;
	cin >> cmd;
	accountType account;
	if(cmd == 's')
		account = Savings;
	else if(cmd == 'c')
		account = Checking;
	else if(cmd == 'd')
		account = CreditCard;
	else
	{
		cout << "I didn't understand your response of :" << cmd << ": Aborting transaction" << endl;
		return;
	}
	
	cout << "How much would you like to deposit?" << endl << "--> ";

	float amount;
	cin >> amount;

	dataBase[customerIndex].account[account].amount += amount;
	cout << "Deposited $" << amount << " to your" << accountString(account) << " account.  Current Balance = "<<  dataBase[customerIndex].account[account].amount << endl;
	
	logFile << dataBase[customerIndex].customerNumber << " " 
	        << dataBase[customerIndex].firstName << " "
			<< dataBase[customerIndex].lastName << " "
			<< accountString(account) << " "
			<< "Deposit "
			<< amount << endl;
}

void WithdrawlMoney(int customerIndex, customerRecord dataBase[], ofstream &logFile)
{
	cout << "Which account would you like to withdraw from:" << endl;
	if(dataBase[customerIndex].account[Savings].type == Savings)
		cout << "(s) Savings" << endl;
	if(dataBase[customerIndex].account[Checking].type == Checking)
		cout << "(c) Checking " << endl;
	if(dataBase[customerIndex].account[CreditCard].type == CreditCard)
		cout << "(d) Credit Card " << endl;
	cout << "--> ";
	
	char cmd;
	cin >> cmd;
	accountType account;
	if(cmd == 's')
		account = Savings;
	else if(cmd == 'c')
		account = Checking;
	else if(cmd == 'd')
		account = CreditCard;
	else
	{
		cout << "I didn't understand your response of :" << cmd << ": Aborting transaction" << endl;
		return;
	}
	
	cout << "How much would you like to withdraw?" << endl << "--> ";

	float amount;
	cin >> amount;

	if(account != CreditCard && dataBase[customerIndex].account[account].amount - amount < 0)
	{
		cout << "This amount will place you less than zero.  Can't do it. Sorry" << endl;
	}
	else
	{
		dataBase[customerIndex].account[account].amount -= amount;
		cout << "Withdrew $" << amount << " from your account." << endl;
		logFile << dataBase[customerIndex].customerNumber << " " 
	        << dataBase[customerIndex].firstName << " "
			<< dataBase[customerIndex].lastName << " "
			<< accountString(account) << " "
			<< "Withdrawl "
			<< amount << endl;
	}
}

void TransferMoney(int customerIndex, customerRecord dataBase[], ofstream &logFile)
{
	cout << "Which account would you like to withdraw from:" << endl;
	if(dataBase[customerIndex].account[Savings].type == Savings)
		cout << "(s) Savings" << endl;
	if(dataBase[customerIndex].account[Checking].type == Checking)
		cout << "(c) Checking " << endl;
	if(dataBase[customerIndex].account[CreditCard].type == CreditCard)
		cout << "(d) Credit Card " << endl;
	cout << "--> ";
	
	char cmd;
	cin >> cmd;
	accountType withdrawlAccount;
	if(cmd == 's')
		withdrawlAccount = Savings;
	else if(cmd == 'c')
		withdrawlAccount = Checking;
	else if(cmd == 'd')
		withdrawlAccount = CreditCard;
	else
	{
		cout << "I didn't understand your response of :" << cmd << ": Aborting transaction" << endl;
		return;
	}
	
	cout << "How much would you like to withdrawl?" << endl << "--> ";

	float amount;
	cin >> amount;

	if(withdrawlAccount != CreditCard && dataBase[customerIndex].account[withdrawlAccount].amount - amount < 0)
	{
		cout << "This amount will place you less than zero.  Can't do it. Sorry" << endl;
	}
	else
	{
		cout << "Which account would you like to deposit into:" << endl;
		if(dataBase[customerIndex].account[Savings].type == Savings)
			cout << "(s) Savings" << endl;
		if(dataBase[customerIndex].account[Checking].type == Checking)
			cout << "(c) Checking " << endl;
		if(dataBase[customerIndex].account[CreditCard].type == CreditCard)
			cout << "(d) Credit Card " << endl;
		cout << "--> ";
		
		char cmd;
		cin >> cmd;
		accountType depositAccount;
		if(cmd == 's')
			depositAccount = Savings;
		else if(cmd == 'c')
			depositAccount = Checking;
		else if(cmd == 'd')
			depositAccount = CreditCard;
		else
		{
			cout << "I didn't understand your response of :" << cmd << ": Aborting transaction" << endl;
			return;
		}
		
		dataBase[customerIndex].account[withdrawlAccount].amount -= amount;
		cout << "Withdrew $" << amount << " from your account." << endl;
		logFile << dataBase[customerIndex].customerNumber << " " 
	        << dataBase[customerIndex].firstName << " "
			<< dataBase[customerIndex].lastName << " "
			<< accountString(withdrawlAccount) << " "
			<< "Withdrawl "
			<< amount << endl;
		dataBase[customerIndex].account[depositAccount].amount += amount;
		cout << "Deposited $" << amount << " to your account." << endl;
		logFile << dataBase[customerIndex].customerNumber << " " 
	        << dataBase[customerIndex].firstName << " "
			<< dataBase[customerIndex].lastName << " "
			<< accountString(depositAccount) << " "
			<< "Deposit "
			<< amount << endl;
	}
}

void addCustomer(customerRecord dataBase[], int securityDatabase[][2])
{
	// Find the first -1 customer number.  It is the first empty slot.
	int index = findCustomerIndex(-1, dataBase);
	
	string customerNumber, firstName, lastName, pin, address, town,
		state, zip, phone;
	string savings, savingsAmount, checking, checkingAmount, creditCard, creditCardAmount;
	cout << "Enter Customer Number: ";
	cin >> customerNumber;
	cout << "Enter First Name: ";
	cin >> firstName;
	cout << "Enter Last Name: ";
	cin >> lastName;
	cout << "Enter Pin: ";
	cin >> pin;
	cout << "Enter Address: ";
	cin >> address;
	cout << "Enter Town: ";
	cin >> town;
	cout << "Enter State: ";
	cin >> state;
	cout << "Enter Zip: ";
	cin >> zip;
	cout << "Enter Phone: ";
	cin >> phone;
	cout << "Do you want a Saving Account (Yes/No): ";
	cin >> savings;
	if(savings == "Yes")
	{
		cout << "How much to start the account with: ";
		cin >> savingsAmount;
	}
	cout << "Do you want a Checking Account (Yes/No): ";
	cin >> checking;
	if(checking == "Yes")
	{
		cout << "How much to start the account with: ";
		cin >> checkingAmount;
	}
	cout << "Do you want a Credit Card Account (Yes/No): ";
	cin >> creditCard;
	if(creditCard == "Yes")
	{
		cout << "How much to start the account with: ";
		cin >> creditCardAmount;
	}
	
	dataBase[index].customerNumber = atoi(customerNumber.c_str());
	dataBase[index].firstName = firstName;
	dataBase[index].lastName = lastName;
	dataBase[index].pin = atoi(pin.c_str());
	dataBase[index].address = address;
	dataBase[index].town = town;
	dataBase[index].state = state;
	dataBase[index].zip = zip;
	dataBase[index].phone = phone;
	if(savings == "Yes")
	{
		dataBase[index].account[Savings].type = Savings;
		dataBase[index].account[Savings].amount = (float)atof(savingsAmount.c_str());
	}
	else
	{
		dataBase[index].account[Savings].type = unknown;
		dataBase[index].account[Savings].amount = -1;
	}
	if(checking == "Yes")
	{
		dataBase[index].account[Checking].type = Checking;
		dataBase[index].account[Checking].amount = (float)atof(checkingAmount.c_str());
	}
	else
	{
		dataBase[index].account[Checking].type = unknown;
		dataBase[index].account[Checking].amount = -1;
	}
	if(creditCard == "Yes")
	{
		dataBase[index].account[CreditCard].type = CreditCard;
		dataBase[index].account[CreditCard].amount = (float)atof(creditCardAmount.c_str());
	}
	else
	{
		dataBase[index].account[CreditCard].type = unknown;
		dataBase[index].account[CreditCard].amount = -1;
	}
	
	securityDatabase[index][CUSTOMER_COLUMN] = dataBase[index].customerNumber;
	securityDatabase[index][PIN_COLUMN] = dataBase[index].pin;
	
}


int findCustomerIndex(int customerNumber, customerRecord dataBase[])
{
	int index = -1;
	for(int i = 0; i < MAX_NUMBER_OF_CUSTOMERS; i++)
	{
		if(dataBase[i].customerNumber == customerNumber)
		{
			index = i;
			break;
		}
	}

	return index;
}

int findCustomerIndexByName(string firstName, string lastName, customerRecord dataBase[])
{
	int index = -1;
	for(int i = 0; i < MAX_NUMBER_OF_CUSTOMERS; i++)
	{
		if(dataBase[i].firstName == firstName && dataBase[i].lastName == lastName)
		{
			index = i;
			break;
		}
	}
	return index;
}

int CountCustomers(customerRecord dataBase[])
{
	int count = 0;
	
	for(int i = 0; i < MAX_NUMBER_OF_CUSTOMERS; i++)
	{
		if(dataBase[i].customerNumber != -1)
			count++;
	}
	
	return count;
}

float CountMoney(customerRecord dataBase[])
{
	float total = 0.0;
	
	for(int i = 0; i < MAX_NUMBER_OF_CUSTOMERS; i++)
	{
		if(dataBase[i].account[Savings].type == Savings)
			total += dataBase[i].account[Savings].amount;
		if(dataBase[i].account[Checking].type == Checking)
			total += dataBase[i].account[Checking].amount;
		if(dataBase[i].account[CreditCard].type == CreditCard)
			total += dataBase[i].account[CreditCard].amount;
	}
	
	return total;
}

string accountString(accountType account)
{
	if(account == Savings)
		return "Savings";
	if(account == Checking)
		return "Checking";
	if(account == CreditCard)
		return "CreditCard";
	if(account == unknown)
		return "unknown";
	return "UnknownValue";
}