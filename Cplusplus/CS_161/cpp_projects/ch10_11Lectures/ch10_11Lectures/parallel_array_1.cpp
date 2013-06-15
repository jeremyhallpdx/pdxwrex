#include <iostream>
#include <string>

using namespace std;

const int N = 3;
string name[N];		// Arrays are declared at file scope.
char grade[N];

void populate();		// funct. proto.
void search();		// funct. proto.


int main()
{
	populate();
	search();
	
	return 0;
}

void populate()
{
	for (int i = 0; i < N; i++)
	{
		cout << "Enter name: ";
		getline(cin, name[i]);
		cout << "Enter grade: ";
		cin >> grade[i];
		cin.ignore(100, '\n');
	}
}

void search()
{
	string studentName;
	int i;

	cout << "Enter name to search: ";
	getline(cin, studentName);

	for(i = 0; i < N; i++)
	{
		if (name[i].find(studentName))
		break;
	}
	if(i == N)
		cout << "Record not found." << endl;
	else
		cout << "Your grade is: " << grade[i] << endl;
}