#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


enum accountType {
	UNKNOWN = -1, CHECKING, SAVINGS, CREDITCARD, INSTANTACCESS
};

class customerType {
public:
	customerType();
	//void deposit_funds();
	//void withdraw_funds();
	//void xfer_funds();
	//void balance_inquiry();
	void get_data();
	void print();
	void search_name();

private:
	string firstName;
	string lastName;
	string accountNumber;
	float amount;
	accountType type;

	void add_person();
	int find_customer_index();
	//void del_person();
};

customerType::customerType() {
	string firstName = "";
	string lastName = "";
	string accountNumber = "";
	float amount = 0.0;
	accountType type = UNKNOWN;
}

void customerType::get_data() {
	add_person();
}

void customerType::add_person() {
	int choice = 0;
	
	cout << "\nPlease enter the following information:" << endl;
	cout << "\nFirst Name: ";
	cin >> firstName;
	cout << "\nLast Name: "; 
	cin >> lastName;
	cout << "\nAccount Number: ";
	cin >> accountNumber;
	cout << "\nOpening Balance: $";
	cin >> amount;
	cout << "\nAccount Type:" << endl;
	cout << "1. Checking" << endl;
	cout << "2. Savings" << endl;
	cout << "3. Credit Card" << endl;
	cout << "4. Instant Access" << endl;
	cin >> choice;
	
	switch(choice) {
		case 1:
			type = CHECKING;
			break;
		case 2:
			type = SAVINGS;
			break;
		case 3:
			type = CREDITCARD;
			break;
		case 4:
			type = INSTANTACCESS;
			break;
		default:
			type = UNKNOWN;
			break;
	}	//	Ends switch statement.
}

void customerType::print() {
	cout << fixed << showpoint << setprecision(2)
		 << firstName << " " << lastName 
		 << '\n' << accountNumber << " $" << amount;
	if(type == 0)
		cout << " Checking" << endl;
	else if(type == 1)
		cout << " Savings" << endl;
	else if(type == 2)
		cout << " Credit Card" << endl;
	else if(type == 3)
		cout << " Instant Access" << endl;
	else
		cout << " Unknown" << endl;
}


int main() {

	customerType myCustomer;
	myCustomer.get_data();
	myCustomer.print();
	
	return 0;
}