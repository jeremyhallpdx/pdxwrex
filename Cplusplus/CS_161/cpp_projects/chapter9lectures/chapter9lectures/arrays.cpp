#include <iostream>

using namespace std;

const int N = 5;

int main()
{
	double score[N] = {0};

	int i;
	double sum = 0;
	double avg = 0;

	cout << "Please enter 5 scores: " << endl;

	for(i = 0; i < N; i++)
		cin >> score[i];
	
	for (i = 0; i < N; i++)
		sum += score[i];

	avg = sum / N;
	
	cout << "The sum of scores is: " << sum << endl;
	cout << "The average score is: " << avg << endl;
	
	return 0;
}

