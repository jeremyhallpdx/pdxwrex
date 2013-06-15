#include <iostream>

using namespace std;

int letter_count(int, int);

int letter_count(int index, int alphabet[])  // Function needs return statement...
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