#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

enum accountType {
	UNKNOWN = -1, CHECKING, SAVINGS, CREDITCARD, INSTANTACCESS
};

const int SIZE = 50;

class customer {
public:
	customer();
	void deposit_funds();
	void withdraw_funds();
	void xfer_funds();
	void balance_inquiry();
	void customer_interface();
	void get_data();
	void print_data();
		
private:
	string firstName;
	string lastName;
	float amount;
	string accountNumber;
	accountType type;
	void get_name();
	void get_amount();
	void get_accountNum();
	void get_accType();
};
customer::customer() {

}

void get_data() {
	get_name();
	get_accountNum();
	get_amount();
	get_accType();
}

void print_data() {
	cout << fixed << showpoint << setprecision(2)
		 << myCustomer.firstName << " " << myCustomer.lastName << '\n' << myCustomer.accountNumber
		 << " $" << myCustomer.amount << " ";
	if(myCustomer.type == CHECKING)
		cout << "Checking";
	else if(myCustomer.type == SAVINGS)
		cout << "Savings";
	else if(myCustomer.type == CREDITCARD)
		cout << "Credit Card";
	else if(myCustomer.type == INSTANTACCESS)
		cout << "Instant Access";
	else
		cout << "Unknown Account Type";
}

void customer::get_name() {
	string tempName;

	cout << "Please enter a first name: ";
	cin >> tempName;
	myCustomer.firstName = tempName;
	tempName = "";
	cout << "Please enter a last name: ";
	cin >> tempName;
	myCustomer.lastName = tempName;
}

void customer::get_accountNum() {
	string tempAccount;

	cout << "Please enter the account number:";
	cin >> tempAccount;
	myCustomer.accountNumber = tempAccount;
}

void customer::get_amount() {
	float tempAmount = 0.0;
		
	cout << "Please enter a starting balance:";
	cin >> tempAmount;
	myCustomer.amount = tempAmount;
}

void customer::get_accType() {
	int tempType = 0;

	cout << "Please enter the type of account:";
	cin >> tempType;

	switch(tempType) {
		case 1:
			myCustomer.type = CHECKING;
			break;
		case 2:
			myCustomer.type = SAVINGS;
			break;
		case 3:
			myCustomer.type = CREDITCARD;
			break;
		case 4:
			myCustomer.type = INSTANTACCESS;
			break;
		default:
			myCustomer.type = UNKNOWN;
	}
}


int main() {
	customer myCustomer;
	myCustomer.get_data();
		
	

	return 0;
}