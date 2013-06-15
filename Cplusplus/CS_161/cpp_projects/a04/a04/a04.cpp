/*
 *	CS_161:		Assignement 4												     
 *	Author:		Jeremy Hall														 
 *	Date:		2-November-2008													 
 *	Sources:	www.cplusplus.com												 
 *	Desc:		This program reads the data from an input file and processes	 
 *				sum and average calculations on the data.						 
 *				The data is then output to the screen.							 																			 	
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

		// Function prototypes:
double total_avg (double, double, int);
double score_avg (double, int);
string input_path ();
void user_output (double, double, double, double, int, int, int, int, int);

int main()
{
	char gender;
	double score = 0.0;
	double maleScore = 0.0;
	double femaleScore = 0.0;
	double ccScore = 0.0;
	double unScore = 0.0;
	double totalAverage = 0.0;
	double scoreAverage = 0.0;
	ifstream inFile;
	int count = 0;								// Counter for lines read from input file.
	int m = 0;									// Counter for males.
	int f = 0;									// Counter for females.
	int c = 0;									// Counter for community college.
	int u = 0;									// Counter for university.
	string pathName;							// Variable for path to input file.
	string school, name;
	
	pathName = input_path();
	inFile.open (pathName.c_str());
	//inFile.open ();
	if (!inFile)
	{
		cout << "\nFile not found! Program terminating." << endl;
		exit (0);
	}
	cout << endl;

	while (!inFile.eof())
	{
		++count;
		inFile >> name >> gender >> school; 
		inFile.ignore ();
		inFile >> score;
		
		cout << setw(15) << left << name << setw(5) << left << gender 
			 << setw(5) << left << school << setw(6) << left << score << endl;

		if (gender == 'm' || gender == 'M')
		{
			m++;
			maleScore += score;
		}
		else if (gender == 'f' || gender == 'F')
		{
			f++;
			femaleScore += score;
		}
		if (school == "cc" || school == "CC")
		{
			c++;
			ccScore += score;
		}
		else if (school == "un" || school == "UN")
		{
			u++;
			unScore += score;
		}
	}
	user_output (maleScore, femaleScore, unScore, ccScore, m, f, c, u, count);
	inFile.close();

	return 0;
}

		// Function to calculate Total Average score.
double total_avg(double a, double b, int i)
{
	double avg;
	avg = (a + b) / i;

	return avg;
}

		// Function to calculate average scores.
double score_avg(double a, int b)	
{
	double avg;
	avg = a / b;

	return avg;
}
		// Function to read in path for file.	
string input_path()
{
	string path;

	cout << "Please enter the full path for the source file: " << endl;
	cout << "Path: ";
	getline(cin, path);

	return path;
}

		// Function to further calculate and display input.
void user_output (double maleScore, double femaleScore, double unScore, double ccScore, int m, int f, int c, int u, int count)
{
	cout << fixed << showpoint << setprecision(2);
	cout << "\nAverage score for male students: " << score_avg (maleScore, m) << endl;
	cout << "Average score for female students: " << score_avg (femaleScore, f) << endl;
	cout << "Average score for University students: " << score_avg (unScore, u) << endl;
	cout << "Average score for Community College students: " << score_avg (ccScore, c) << endl;
	cout << "\nAverage score for all students: " << total_avg (maleScore, femaleScore, count) << endl;
	cout << endl;
}