#include <iostream>
#include "person.h"

using namespace std;



const int MAX_PEOPLE = 2;

int main()
{
	int age;
	int height;
	person people[MAX_PEOPLE];
	person thisPerson(29, 77);

	for(int i = 0; i < MAX_PEOPLE; ++i) {
		cout << "Enter the age for person (" << i + 1 << " of " << MAX_PEOPLE << ") :";
		cin >> age;
		people[i].set_age(age);
				
		cout << "Enter the height for person (" << i + 1 << " of " << MAX_PEOPLE << ") :";
		cin >> height;
		people[i].set_height(height);

		people[i].print();
	}

	int someInt = people[0].get_age();

	return 0;
}

person::person() 
{
	age = 0;
	height = 0;
}


person::person(int inAge, int inHeight) {
	age = inAge;
	height = inHeight;
}


void person::set_age(int inAge) {
	age = inAge;
}

void person::set_height(int inHeight) {
	height = inHeight;
}

void person::print() {
	cout << age << endl;
	cout << height << endl;
}

int person::get_age() {
	return age;
}