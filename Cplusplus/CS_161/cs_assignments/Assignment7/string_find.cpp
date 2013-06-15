#include <iostream>
#include <string>

using namespace std;

int main()
{
	string title[3] = {"The Last Oracle", "Seizure", "Jack and Jill"};
	string author[3] = {"James Rollins", "Michael Crichton", "James Patterson"};
	char option;
	string aname, atitle;
	do
	{
		cout << "\n\nPlease choose one of the following:" << endl;
		cout << "a: Search by Author" << endl;
		cout << "t: Search by Title" << endl;
		cout << "q: Quit" << endl;
		cin >> option;

		cin.ignore(100, '\n');

		switch(option)
		{
		case 'a':
		case 'A':
			cout << "Enter author's name or part of the name:";
			getline(cin, aname);
			for(int i = 0; i < 3; i++)
			{
				if(author[i].find(aname) < strlen(author[i].c_str()))
					cout << "\nFound:\n Author: " << author[i] << "\tTitle: "
						 << title[i] << endl;
			}
			break;
		case 't':
		case 'T':
			cout << "Enter title or part of the title:";
			getline(cin, atitle);
			for(int i = 0; i < 3; i++)
			{
				if(title[i].find(atitle) < strlen(title[i].c_str()))
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

