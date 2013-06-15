#include <iostream>
#include <string>

using namespace std;

int add_customer(int counter);

enum accountType {
	UNKNOWN = -1, CHECKING, SAVINGS, CREDITCARD, INSTANTACCESS
};
//	Variable of accountType.
accountType type;

const int SIZE = 50;

struct custType {
	char firstName[SIZE];
	char lastName[SIZE];
	float amount;
	string accountNumber;
	accountType type;
};
custType customer[SIZE];

int main() {
	int i =0;
	int counter = i;

	customer[SIZE];

	i = add_customer(counter);
	cout << i << endl;
	

	return 0;

}

int add_customer(int counter) {
	int tempType;

	cout << "Please enter the following information:" << endl;
	cout << "First Name: ";
	cin >> customer[counter].firstName;
	cout << endl;
	cout << "Last Name: "; 
	cin >> customer[counter].lastName;
	cout << endl;
	cout << "Account Number: ";
	cin >> customer[counter].accountNumber;
	cout << endl;
	cout << "Opening Balance: ";
	cin >> customer[counter].amount;
	cout << "Account Type:" << endl;
	cout << "1. Checking" << endl;
	cout << "2. Savings" << endl;
	cout << "3. Credit Card" << endl;
	cout << "4. Instant Access" << endl;
	cin >> tempType;
	
	if(tempType = 1)
		customer[counter].type = CHECKING;
	else if(tempType = 2)
		customer[counter].type = SAVINGS;
	else if(tempType = 3)
		customer[counter].type = CREDITCARD;
	else if(tempType = 4)
		customer[counter].type = INSTANTACCESS;
	else
		cout << "Invalid Selection!" << endl;
	
	++counter;
	return counter;
}