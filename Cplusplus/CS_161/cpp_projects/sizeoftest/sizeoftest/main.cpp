#include <iostream>

using namespace std;

int main()
{
	cout << "sizeof(char) = " << sizeof(char) << endl;
	cout << "sizeof(int) = " << sizeof(int) << endl;
	cout << "sizeof(float) = " << sizeof(float) << endl;
	cout << "sizeof(double) = " << sizeof(double) << endl;

	int intarray[10];	//this is an array of 10 ints... 10*sizeof(int) 
	int* ptr;
	ptr = intarray;
	
	cout << "sizeof(ptr) = " << sizeof(ptr) << endl;
	cout << "sizeof(intarray[10]) = something incorrect: " << sizeof(intarray) << endl;
	cout << "sizeof(intarray[10}) = correctly: " << sizeof(int)*10 << endl;


	return 0;
}