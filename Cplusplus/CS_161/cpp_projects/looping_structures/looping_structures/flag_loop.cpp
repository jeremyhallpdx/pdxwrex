#include <iostream>

using namespace std;


int main()
{
	bool flag = true;
	char ans;

	while (flag)
	{
		cout << "Do you want to continue?" << endl;
		cin >> ans;

		if (ans == 'n' || ans == 'N')
			flag = false;
	}

	return 0;
}