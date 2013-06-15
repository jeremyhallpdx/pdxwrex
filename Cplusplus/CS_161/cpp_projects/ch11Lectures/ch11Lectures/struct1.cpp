#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct studentType
{
	string firstName;
	string lastName;
	string id_no;
	double gpa;
};

int main()
{
	studentType pccStudent;

	cout << "Enter first name: ";
	cin >> pccStudent.firstName;		// To input directly into struct member.
	cout << "Enter last name: ";
	cin >> pccStudent.lastName;			// Use inFile/outFile to read in from a file.
	cout << "Enter ID No.: ";
	cin >> pccStudent.id_no;
	cout << "Enter GPA: ";
	cin >> pccStudent.gpa;
	
//	Output
	cout << '\n' << pccStudent.firstName << '\n' << pccStudent.lastName
		 << '\n' << pccStudent.id_no << '\n' << fixed << setprecision(1) << pccStudent.gpa << endl;

	return 0;
}
