#include <iostream>

using namespace std;

void one(int x, int& y);
void two(int& s,int t);

int main()
{
	int u = 1;
	int v = 2;

	one(u, v);
	cout << u << " " << v << endl;
	two(u, v);
	cout << u << " " << v << endl;

	return 0;

}

void one(int x, int& y)
{
	int a;

	a = x;
	x = y;
	y = a;
}

void two(int& s, int t)
{
	int b;

	b = s - t;
	s = t + b + 2;
	t = 4 * b;
}