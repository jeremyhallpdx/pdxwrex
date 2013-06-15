#include <iostream>
#include <string>

using namespace std;

int main()
{
	string title[3] = {"The Last Oracle", "Seizure", "Jack and Jill"};
	string author[3] = {"James Rollins", "Michael Crichton", "James Patterson"};
	char option;
	int count = 0;
	string searchName, searchTitle;
	do
	{
		cout << "\nEnter (Q) to Quit, Search (A)uthor, Search (T)itle, (S)how All: ";
		cin >> option;
		cin.ignore(100, '\n');

		switch(option)
		{
		case 'a':
		case 'A':
			cout << "Author's name:";
			getline(cin, searchName);
			for(int i = 0; i < count; i++)
			{
				if(searchName.length() < author[i].length())
					cout << "\nFound:\n Author: " << author[i]
						 << "\tTitle: " << title[i] << endl;
			}
			break;
		case 't':
		case 'T':
			cout << "Enter title or part of the title:";
			getline(cin, searchTitle);
			for(int i = 0; i < count; i++)
			{
				if(title[i].find(searchTitle) < strlen(title[i].c_str()))
					cout << "\nFound:\n Author: " << author[i] << "\tTitle: "
						 << title[i] << endl;
			}
			break;
		case 'q':
		case 'Q':
			break;
		default:
			cout << "Invalid input!" << endl;
		}
	}while(tolower(option) != 'q');
}

