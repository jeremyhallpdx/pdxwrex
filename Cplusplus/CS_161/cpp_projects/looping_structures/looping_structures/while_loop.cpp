#include <iostream>

using namespace std;


int main()
{
	double score;
	int count = 0;
	double totalScore = 0;
	double average;

	cout << "Please enter your test scores (-1 to quit): ";
	cin >> score;

	while (score != -1)
	{
		totalScore += score;
		count++;
		cin >> score;
		//count++;
	}

	average = totalScore / count;
	cout << "Your average is :" << average << endl;

	return 0;
}