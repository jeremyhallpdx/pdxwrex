/*
 *	CS161
 *	Date:  09/30/08
 *	Author:  Jeremy Hall
 *	Desc:  This program takes the input of 5 test scores.  Then, it returns the average test score.
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
	float score1, score2, score3, score4, score5;
	float avg;

	cout << "sizeof(double) = " << sizeof(double);

	cout << "Please enter a test score: " ;
	cin >> score1;
	cout << "Please enter a test score: " ;
	cin >> score2;
	cout << "Please enter a test score: " ;
	cin >> score3;
	cout << "Please enter a test score: " ;
	cin >> score4;
	cout << "Please enter a test score: " ;
	cin >> score5;

	avg = (score1 + score2 + score3 + score4 + score5) / 5;

	cout << "\nThe average test score is: \a" << avg << endl;

	return 0;

}