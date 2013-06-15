#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str = "goofy";
	string newStr = "";

	for(int j = 0; j < str.length(); j++)
		newStr = str[j] + newStr;

	cout << newStr << endl;

	return 0;
}