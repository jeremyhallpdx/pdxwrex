#include <iostream>

using namespace std;

const int ROWS = 3;
const int COLS = 3;

void read_input(int x[][COLS]);		// in 2D arrays, the sencond array dimension must be declared in prototype.
void output(int x[][COLS]);

int main()
{
	int x[ROWS][COLS] = {0};
	read_input(x);
	output(x);

	return 0;
}

void read_input(int x[][COLS])
{
	int i, j;
	
	cout << "Enter 9 numbers: ";
	for(i = 0; i < ROWS; i++)
	{
		for(j = 0; j < COLS; j++)
			cin >> x[i][j];
	}
}
void output(int x[][COLS])
{
	int i, j;
	cout << "Your output is: " << endl;
	for(i = 0; i < ROWS; i++)
	{
		for(j = 0; j < COLS; j++)
			cout << x[i][j] << " ";
		cout << endl;
	}
}