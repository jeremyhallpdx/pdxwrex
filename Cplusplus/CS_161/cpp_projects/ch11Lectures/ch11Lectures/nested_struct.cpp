#include <iostream>
#include <string>

using namespace std;

struct name
{
	string fname;
	string lname;
};

struct address
{
	string street;
	string city;
};

struct mydate
{
	string day;
	string month;
	string year;
};

struct EType
{
	string emp_id;
	name empname;
	address empaddress;
	mydate hiredate;
};

int main()
{
	EType newemp;

	cout << "Please enter first name: ";
	cin >> newemp.empname.fname;
	cout << "Please enter employee ID: ";
	cin >> newemp.emp_id;

	cout << newemp.empname.fname << '\t' << newemp.emp_id << endl;
 
	return 0;
}
