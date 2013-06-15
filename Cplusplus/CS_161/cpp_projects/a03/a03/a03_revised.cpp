/*	
 *	CS161	-	Assignment 03
 *	Date:		26-October-2008
 *	Author:		Jeremy Hall
 *	Sources:	Brandon Fasching 
 *	Desc:		This program figures the fare for a ferry trip to Friday Harbor from Anacortes, WA. It asks the user for
 *				specific data and calculates the appropriate fare based on the user's entries.
 */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Function prototypes:
char get_char_input(string);
char check_value(char, string);
int get_integer_input(string);
double get_double_input (string);

const double A_FARE = 13.15;					// Adult Fare
const double S_FARE = 6.55;						// Senior Fare
const double Y_FARE = 10.55;					// Youth Fare
const double BICYCLE_SURCHARGE = 4.00;			// Bicycle Surcharge
const double UNDER20_DRIVER_FARE = 51.20;		// Charge for vehicles under 20' with Adult driver.
const double UNDER20_SENIOR_FARE = 44.60;		// Charge for vehicles under 20' with Senior/Disabled driver.
const double TALL_SURCHARGE = 51.20;			// Charge for vehicles over 7'6".
const double SHORT_FARE_20TO29 = 76.80;			// Charge based on vehicle length.
const double TALL_FARE_20TO29 = 153.60;			// Charge based on vehicle length.  ** Includes surcharge for height over 7'6". **
const double FARE_30TO39 = 204.80;				// Charge based on vehicle length.


int main()
{
	bool error = 0;							
	int passenger = 0;
	char reply;
	char vehicleHeight;
	double vehicleLength = 0.0;
	double totalFare = 0.0;

	cout << fixed << showpoint << setprecision (2);
	cout << "Welcome to Jeremy's Fare Calculator!" << endl;
		
	reply = get_char_input("\nAre you driving a vehicle on to the ferry? (y/n): ");
	
	if (reply == 'n' || reply == 'N')
	{
		passenger = get_integer_input("\nHow many Adults (age 19 - 64)in your group? ");
		totalFare = totalFare + passenger * A_FARE;

		passenger = get_integer_input("\nHow many Senior Citizens (age 65 or older), or disabled persons in your group? ");
		totalFare = totalFare + passenger * S_FARE;

		passenger = get_integer_input("\nHow many Youth (age 5 - 18) in your group? ");
		totalFare = totalFare + passenger * Y_FARE;

		passenger = get_integer_input("\nHow many people in your group are traveling with a bicycle? ");
		totalFare = totalFare + passenger * BICYCLE_SURCHARGE;
	}
		
	else if (reply == 'y' || reply == 'Y')
	{	
		char senior;		// Input for user prompt.
		
		senior = get_char_input("\nIs the driver a senior cititzen (65 or older) or disabled? (y/n): ");
	
		cout << "\nHow many passengers in your vehicle (excluding driver)?" << endl;
		passenger = get_integer_input("Number of Adults(age 19-64): ");
		totalFare = totalFare + passenger * A_FARE;

		passenger = get_integer_input("Number of Senior Citizens(age 65 or older) : ");
		totalFare = totalFare + passenger * S_FARE;

		passenger = get_integer_input("Number of Children(age 5-18): ");
		totalFare = totalFare + passenger * Y_FARE;

		vehicleHeight = get_char_input("\nIs your vehicle over 7 feet, 6 inches in height? (y/n): ");

		vehicleLength = get_double_input("\nHow long is your vehicle in feet? ");

		if (vehicleHeight == 'y' || vehicleHeight == 'Y') 
		{
			if (vehicleLength <= 19 && senior == 'y' || senior == 'Y')
				totalFare = totalFare + TALL_SURCHARGE + UNDER20_SENIOR_FARE;
			else if (vehicleLength <= 19 && senior == 'n' || senior == 'N')
				totalFare = totalFare + TALL_SURCHARGE + UNDER20_DRIVER_FARE;
			else if (vehicleLength >= 20 && vehicleLength <= 29)
				totalFare = totalFare + TALL_FARE_20TO29;
			else if (vehicleLength >= 30 && vehicleLength <= 39) 
				totalFare = totalFare + FARE_30TO39;
			else
				error = true;
		}		// Closes if statement for vehicleHeight.
		
		else if (vehicleHeight == 'n' || vehicleHeight == 'N')
		{	
			if (vehicleLength <= 19 && senior == 'y' || senior == 'Y')
				totalFare = totalFare + UNDER20_SENIOR_FARE;
			else if (vehicleLength <= 19 && senior == 'n' || senior == 'N')
				totalFare = totalFare + UNDER20_DRIVER_FARE;
			else if (vehicleLength >= 20 && vehicleLength <= 29)
				totalFare = totalFare + SHORT_FARE_20TO29;
			else if (vehicleLength >= 30 && vehicleLength <= 39) 
				totalFare = totalFare + FARE_30TO39;
			else
				error = true;
		}		// Closes elseIf statement for vehicleHeight.
	}		// Closes elseIf statement for Driving a vehicle on to the ferry.
	
	if (error)		// Error is generated if input for vehicle length is over 40'.
		cout << "\nVehicles over 40' in length are prohibited." << endl;
	else
	{
		cout << "\nYour total fare is: $" << totalFare << endl;
		cout << "\nThank you for using Jeremy's Fare Calculator." << endl;
	}

	return 0;
}

char get_char_input(string msg)
{
	char reply;

	cout << msg;					
	cin >> reply;
	cin.ignore (100, '\n');

	return check_value(reply, msg);
}

char check_value(char reply, string errorMessage)
{

	while (!(reply == 'y' || reply == 'Y' || reply == 'n' || reply == 'N'))
	{
		cout << "\nInvalid input! Please try again. ";
		cout << errorMessage;
		cin >> reply;		

		while (cin.get() != '\n')		// While loop kills the input buffer.
			;
	}

	return reply;
}
int get_integer_input(string msg)
{
	int passenger = 0;
	
	cout << msg;					
	cin >> passenger;
	cin.ignore(100, '\n');
	while (!cin)
	{
		cout << "\nInvalid input! Please try again. ";
		cin.clear();
		cout << msg;
		cin >> passenger;		
	}

	return passenger;
}

double get_double_input(string msg)
{
	double tempValue = 0.0;
	
	
	cout << msg;					
	cin >> tempValue;
	cin.ignore (100, '\n');
	while (!cin)
	{
		cout << "\nInvalid input! Please try again. ";
		cout << msg;
		cin >> tempValue;		

	}

	return tempValue;

}