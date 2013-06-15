#include <iostream>;

using namespace std;

int main()
{
	int i = 0, j = 0;

	for (; i < 5; i)
	{
		for (j = 0; j < 3; j++)
			cout << "* ";
		cout << endl;
	}

	cout << endl;

	return 0;
}