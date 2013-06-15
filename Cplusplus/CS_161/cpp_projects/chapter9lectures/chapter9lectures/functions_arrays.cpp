#include <iostream>

using namespace std;

// Function protoype
void init(int [], int);

const int N = 5;

int main()
{
	int i = 0;
	int list[N] = {0};

	init(list, N);

	cout << "Your list is: " << endl;

	for(int i = 0; i < N; i++);
		cout << list[i] << " ";
	
		cout << endl;

	return 0;
}

void init(int list[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		list[i] = -1;
}