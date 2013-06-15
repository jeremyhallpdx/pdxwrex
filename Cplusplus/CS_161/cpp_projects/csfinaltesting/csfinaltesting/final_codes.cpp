#include <iostream>
#include <iomanip>

using namespace std;

void strange(int& u, char& ch);

int main()
{
	int one = 5;
	char letter = 'A';
	strange (one, letter);

	cout << one << " " << letter << endl;

	return 0;
}

void strange(int& u, char& ch)
{
	int a;

	a = u++;
	u = 2 * u;
	a = static_cast<int> (ch);
	a++;
	ch = static_cast<char> (a);
}

/*int main()
{
	int x = 14;
	int y = 60;

	while(((y - x) % 3) != 0)
	{
		cout << y << " ";
		y = y - 5;
	}

	return 0;
}*/

