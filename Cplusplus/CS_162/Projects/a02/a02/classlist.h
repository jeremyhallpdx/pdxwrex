#ifndef CLASSLIST_H
#define CLASSLIST_H
#include "classrecord.h"
#include <string>
#include <fstream>

struct Node {
	personType record;
	Node * next;
};

class list
{
public:
    list();
	list(char[], int&);
	~list();
	void dump(char[]) const;
private:
    Node * head;
};

#endif