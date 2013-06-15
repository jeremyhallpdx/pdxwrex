/*
 *	CS161 -			Assignment 6
 *	Date Created:	23-November-2008
 *	Author:			Jeremy Hall
 *	Sources:		www.cplusplus.com, www.techonthenet.com
 *	Desc:			This program utilizes an alogrithm to determine a
 *					basic, alphabetic cypher(known as Ceaser Shift) and applies it
 *					to encrypted source text files.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

//	Function prototypes:
int letter_count(int index, int alphabet[]);
char shift_letter(char, int);

//	Global constants:
const int N = 26;
const int LOWER_E = 4;

int main()
{
	int index;
	int maxIndex = 0;
	string inName;
	string outName;
	ifstream inFile;
	ofstream outFile;
	char ch;
	int alphabet[26] = {0};
	
	cout << "Please enter the name of the input file: ";
	getline(cin, inName);
	inFile.open(inName.c_str());
	if (!inFile)
	{
		cout << "\nInput file not found!" << endl;
		cout << "Program terminating." << endl;
		exit (1);
	}
	
	cout << "Please enter the name of the output file: ";
	getline(cin, outName);
	outFile.open(outName.c_str());

	while (inFile.peek() != EOF)
	{
        inFile.get(ch);
		index = static_cast <int> (tolower(ch)) - static_cast <int> ('a');
		alphabet[index]++;
    }

	maxIndex = letter_count(index, alphabet);
	maxIndex -= LOWER_E;

	inFile.clear();
	inFile.seekg(0);
	while (inFile.peek() != EOF)
	{
        inFile.get(ch);
		if(isalpha(ch))
		{
			ch = shift_letter(ch, maxIndex);
			outFile << ch;
		}
		else
			outFile << ch;
	}
	inFile.close();
	outFile.close();

	return 0;
}

int letter_count(int index, int alphabet[])
{
	int i;
	int maxIndex = 0;
	int max = alphabet[0];

	for(i = 1; i < N; i++)
	{
		if(alphabet[i] > max)
		{
			max = alphabet[i];
			maxIndex = i;
		}
	}
	return maxIndex;
}

char shift_letter(char ch, int maxIndex)
{
	if(ch >= 65 && ch <= 90)
	{
		ch -= maxIndex;
		if(ch < 65)
		{
			ch += N;
		}
	}
	else
	{
		ch -= maxIndex;
		if(ch < 97)
			ch += N;
	}
	return ch;
}