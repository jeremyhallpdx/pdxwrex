/*
 *	CS161		Assignment 7
 *	Date:		12-December-2008
 *	Author:		Jeremy Hall
 *	Sources:	GD Iyer
 *	Desc:		This program reads a database file and allows the user to search the data.
 */

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Book
{
	string title;
	string author;
};

//	Global declarations:
const int ARRAY_SIZE = 1000;
Book books[ARRAY_SIZE];

//	Function prototypes:
string input_path();
int loadData(string pathName);
void showAll(int count);
int showBooksByAuthor(int count, string name);
int showBooksByTitle(int count, string title);

int main()
{
	char option;
	string pathName;
	string name;
	string title;
	ifstream inFile;
	int count = 0;
	int countA = 0;
	int j = 0;

	cout << "Welcome to Jeremy's Library Database." << endl;
	cout << endl;
	pathName = input_path();
	count = loadData(pathName);
	cout << count << " records loaded successfully." << endl;
	
	do
	{
		loadData(pathName);
		cout << "\nEnter (Q) to Quit, Search (A)uthor, Search (T)itle, (S)how All: ";
		cin >> option;
		cin.ignore(100, '\n');
		j = 0;		//	Used for record entries.

		switch(option)
		{
		case 'A':
		case 'a':
			cout << "\nAuthor's name: ";
			getline(cin, name);
			countA = showBooksByAuthor(count, name);
			cout << '\n' << countA << " records found." << endl;
			break;
		case 'T':
		case 't':
			cout << "\nTitle: ";
			getline(cin, title);
			countA = showBooksByTitle(count, title);
			cout << '\n' << countA << " records found." << endl;
			break;
		case 'S':
		case 's':
			showAll(count);
			cout << '\n' << count << " records found." << endl;
			break;
		case 'Q':
		case 'q':
			break;
		default:
			cout << "\nInvalid input!" << endl;
		}

	}while(tolower(option) != 'q');		

	inFile.close();

	return 0;	
}


// Gets and returns input file.
string input_path()
{
	string path;

	cout << "Please enter the full name of the backup file: ";
	getline(cin, path);

	return path;
}

//	Opens input file and outputs number of records stored.
int loadData(string pathName)
{
	ifstream inFile;
	int countA = 0;
	int i = 0;

	inFile.open(pathName.c_str());
	if (!inFile)
	{
		cout << "\nFile not found! Program terminating." << endl;
		exit (0);
	}

	while(!inFile.eof())
	{
		++countA;
		getline(inFile, bookTitle[i]);
		getline(inFile, bookAuthor[i]);
		i++;
	}
	return countA;
}

//	Outputs the stored data in a different format.
void showAll(int count)
{
	cout << endl;
	for(int i = 0; i < count; i++)
		cout << bookTitle[i] << "  "<< "(" << bookAuthor[i] << ")" << endl;
}

int showBooksByAuthor(int count, string name)
{	
	int j = 0;

	for(int i = 0; i < count; i++)
	{
		if(bookAuthor[i].find(name) < strlen(bookAuthor[i].c_str()))
		{	
			++j;
			cout << bookTitle[i] << "  " << "(" << bookAuthor[i] << ")" << endl;
		}
	}

	return j;
}


int showBooksByTitle(int count, string title)
{
	int j = 0;

	for(int i = 0; i < count; i++)
	{
		if(bookTitle[i].find(title) < strlen(bookTitle[i].c_str()))
		{
			++j;
			cout << bookTitle[i] << "  " << "(" << bookAuthor[i] << ")" << endl;
		}
	}
	return j;
}