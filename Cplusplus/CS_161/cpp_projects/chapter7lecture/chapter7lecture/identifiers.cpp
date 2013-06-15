#include <iostream>

using namespace std;

int t = 0;


void one(int x);
int main()
{
	int num = 0;
	
	cout << "i" << '\t' << "x" << endl;
	one(num);
	one(num);
	one(num);

	return 0;
}
void one(int a)
{
	int i = 5;
	static int x = 0;

	i += 5;
	x += 5;

	cout << i << '\t' << x << endl;

}