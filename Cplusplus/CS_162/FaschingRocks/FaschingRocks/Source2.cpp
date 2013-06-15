#include <iostream>

using namespace std;

struct person {
public:
	int age;
	int height;
private:
	int hisRealAge;

};

void print();
void set_height(int);
void set_age(int);



const int MAX_PEOPLE = 2;
person people[MAX_PEOPLE];

int main()
{
	int age;

	for(int i = 0; i < MAX_PEOPLE; ++i) {
		cout << "Enter the age for person (" << i + 1 << " of " << MAX_PEOPLE << ") :";
		cin >> age;
		set_age(age, i);
		
		cout << "Enter the height for person (" << i + 1 << " of " << MAX_PEOPLE << ") :";
		cin >> height;
		set_height(height, i);

		print(i);
	}

	return 0;
}

void print(int i) {
	cout << people[i] << "'s age is: " << people[i].age << endl;
}

void set_age(int inAge, int who) {
	people[who].age = inAge;
}

void set_height(int inHeight, int who) {
	people[who].height = inHeight;
}