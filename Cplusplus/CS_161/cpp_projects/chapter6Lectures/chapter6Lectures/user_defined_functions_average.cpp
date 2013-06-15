#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

//function to calculate average
double avg(double a, double b)
{
	double avg;
	avg = (a + b) / 2;

	return avg;
}
int main()
{
	double x, y;

	cout << "Enter two numbers and I will give you the average: ";
	cin >> x >> y;
	cout << fixed << showpoint << setprecision(2);

	// Call function and store the variable.
	average = avg(x, y);

	cout << "Average = " << average << endl;

	return 0;
}






double schoolScores (double, double)
{
		if (school == 'c' || school == 'C')
		{
			c++;
			ccScores += score;

			return ccScores;
		}
		else if (school == 'u' || school == 'U')
		{
			u++;
			unScores += score;
			
			return unScores;
		}
}