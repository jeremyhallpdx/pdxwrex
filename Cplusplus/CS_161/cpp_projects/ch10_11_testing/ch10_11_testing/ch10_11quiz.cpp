#include <iostream>

using namespace std;

void selectionSort(int list[], int length);

int main()
{
	int list[] = {6, 7, 4, 1, 3, 8, 2};
	int i;

	selectionSort(list, 7);

	cout << "output: ";

	for (i = 0; i < 6; i++)
		cout << list[i] << " ";

	cout << endl;

	return 0;
}

void selectionSort(int list[], int length)
{
	int index;
	int smallestIndex;
	int minIndex;
	int temp;

	for(index = 0; index < length - 1; index++)
	{
		smallestIndex = index;
		
		for(minIndex = index + 1; minIndex < length; minIndex++)
			if(list[minIndex] < list[smallestIndex])
				smallestIndex = minIndex;
		
		temp = list[smallestIndex];
		list[smallestIndex] = list[index];
		list[index] = temp;
			
	}
}
