#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
#include "classlist.h"
#include "classrecord.h"
#include "menus.h"

//	Default constructor
list::list() {
	head = NULL;
}


//	Function to create list from text file.
list::list(char fileName[], int &count) {
	fstream in;
	string tempFName;
	string tempLName;
	string tempAccount;
	float tempAmount;
	int tempType;
	Node *temp;

	head = NULL;

	in.open(fileName);

	if(!in) {
		cout << "Database record does not exist or is corrupted!" << endl;
		cout << "Program Terminating." << endl;
		exit (-1);
	}
	while(!in.eof()) {
		in >> tempFName >> tempLName >> tempAccount >> tempAmount >> tempType;
		temp = new Node;
		temp->record.set_record(tempFName, tempLName, tempAccount, tempType, tempAmount);
		temp->next = head;
		head = temp;
		temp = NULL;
	}
	in.close();
}


//	Function to output database to text file.
void list::dump(char fileName[]) const {
	ofstream out;
	Node *temp;

	out.open(fileName);

	temp = head;

	while(temp)
	{
		temp->record.print_record(out);		
		temp = temp->next;
	}
	out.close();
}


//	Destructor
list::~list() {
        Node * temp = NULL;
       
        while(head) {
               temp = head;
               head = head->next;
			   delete temp->record;		//	Not sure what's going on here...
			   delete temp;
        }
}

