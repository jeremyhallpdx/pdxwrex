#ifndef PERSON_H
#define PERSON_H

class person {
public:
	person();
	person(int, int);
	void set_age(int);
	void set_height(int);
	int get_age();
	void print();
private:
	int age;
	int height;
};
#endif
