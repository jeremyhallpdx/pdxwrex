#include <iostream>

using namespace std;

struct person {
	int age;
	int height;
};

void print();
void set_height(int);
void set_age(int);


person brandon;

int main()
{
	set_age(29);
	set_height(77);

	print();

	return 0;
}

void print() {

	cout << "Brandon's age is: " << brandon.age << endl;
}

void set_age(int inAge) {
	brandon.age = inAge;
}

void set_height(int inHeight) {
	brandon.height = inHeight;
}