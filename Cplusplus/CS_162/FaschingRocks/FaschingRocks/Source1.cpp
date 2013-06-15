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


const int BRANDON = 0;
const int JEREMY = 1;

const int MAX_PEOPLE = 2;
person people[MAX_PEOPLE];

int main()
{
	for(int i = 0; i < MAX_PEOPLE; ++i) {
		set_age(30, i);
		//set_age(29, JEREMY);
		
		set_height(77);

		print();
	}

	return 0;
}

void print() {
	cout << "Brandon's age is: " << brandon.age << endl;
}

void set_age(int inAge, int who) {
	people[who].age = inAge;
}

void set_height(int inHeight) {
	brandon.height = inHeight;
}