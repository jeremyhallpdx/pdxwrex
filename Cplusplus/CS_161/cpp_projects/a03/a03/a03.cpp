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
	cout << "\nAre you driving a vehicle on to the ferry? (y/n): ";					
	cin >> reply;
	cin.ignore (100, '\n');
	
	while (!(reply == 'y' || reply == 'Y' || reply == 'n' || reply == 'N'))
	{
		cout << "\nInvalid input! Please try again. ";
		cout << "\nAre you driving a vehicle on to the ferry? (y/n): ";
		cin >> reply;		

		while (cin.get() != '\n')		// While loop kills the input buffer.
			;
	}
	
	if (reply == 'n' || reply == 'N')
	{
		cout << "\nHow many Adults (age 19 - 64) in your group? ";
		cin >> passenger;
		cin.ignore (100, '\n');
		while (!cin)
		{
			cin.clear();
			cin.ignore (100, '\n');
			cout << "\nInvalid input! Please try again. ";
			cout << "\nHow many Adults (age 19 - 64) in your group? ";
			cin >> passenger;
		}

		totalFare = totalFare + passenger * A_FARE;

		cout << "\nHow many Senior Citizens (age 65 or older), or disabled persons in your group? ";
		cin >> passenger;
		cin.ignore (100, '\n');
		while (!cin)
		{
			cin.clear();
			cin.ignore (100, '\n');
			cout << "\nInvalid input! Please try again. ";
			cout << "\nHow many Senior Citizens (age 65 or older), or disabled persons in your group? ";
			cin >> passenger;
		}
	
		totalFare = totalFare + passenger * S_FARE;

		cout << "\nHow many Youth (age 5 - 18) in your group? ";
		cin >> passenger;
		cin.ignore (100, '\n');
		while (!cin)
		{
			cin.clear();
			cin.ignore (100, '\n');
			cout << "\nInvalid input! Please try again. ";
			cout << "\nHow many Youth (age 5 - 18) in your group? ";
			cin >> passenger;
		}

		totalFare = totalFare + passenger * Y_FARE;

		cout << "\nHow many people in your group are traveling with a bicycle? ";
		cin >> passenger;
		cin.ignore (100, '\n');
		while (!cin)
		{
			cin.clear();
			cin.ignore (100, '\n');
			cout << "\nInvalid input! Please try again. ";
			cout << "\nHow many people in your group are traveling with a bicycle? ";
			cin >> passenger;
		}

		totalFare = totalFare + passenger * BICYCLE_SURCHARGE;
		
	}
		
	else if (reply == 'y' || reply == 'Y')
	{	
		char senior;		// Input for user prompt.

		cout << "\nIs the driver a senior cititzen (65 or older) or disabled? (y/n): ";					
		cin >> senior;
		cin.ignore (100, '\n');

		while (!(senior == 'y' || senior == 'Y' || senior == 'n' || senior == 'N'))
		{
			cout << "\nInvalid input! Please try again. ";					
			cout << "\nIs the driver a senior citizen (65 or older) or disabled? (y/n): ";
			cin >> senior;		

			while (cin.get() != '\n')		// While loop kills the input buffer.
				;
		}

		cout << "\nHow many passengers in your vehicle (excluding driver)?" << endl;		
		cout << "Number of Adults(age 19-64): ";
		cin >> passenger;
		cin.ignore (100, '\n');
		while (!cin)
		{
			cin.clear();
			cin.ignore (100, '\n');
			cout << "\nInvalid input! Please try again. ";
			cout << "\nNumber of Adults(age 19-64): ";
			cin >> passenger;
		}
		
		totalFare = totalFare + passenger * A_FARE;

		cout << "Number of Senior Citizens(age 65 or older) : ";
		cin >> passenger;
		cin.ignore (100, '\n');
		while (!cin)
		{
			cin.clear();
			cin.ignore (100, '\n');
			cout << "\nInvalid input! Please try again. ";
			cout << "\nNumber of Senior Citizens(age 65 or older) : ";
			cin >> passenger;
		}
		
		totalFare = totalFare + passenger * S_FARE;

		cout << "Number of Children(age 5-18): ";
		cin >> passenger;
		cin.ignore (100, '\n');
		while (!cin)
		{
			cin.clear();
			cin.ignore (100, '\n');
			cout << "\nInvalid input! Please try again. ";
			cout << "\nNumber of Children(age 5-18): ";
			cin >> passenger;
		}
		
		totalFare = totalFare + passenger * Y_FARE;

		cout << "\nIs your vehicle over 7 feet, 6 inches in height? (y/n): ";					
		cin >> vehicleHeight;
		cin.ignore (100, '\n');

		while (!(vehicleHeight == 'y' || vehicleHeight == 'Y' || vehicleHeight == 'n' || vehicleHeight == 'N'))
		{
			cout << "\nInvalid input! Please try again. ";
			cout << "\nIs your vehicle over 7 feet, 6 inches in height? (y/n): ";
			cin >> vehicleHeight;		

			while (cin.get() != '\n')		// While loop kills the input buffer.
				;
		}
		
		cout << "\nHow long is your vehicle in feet? ";
		cin >> vehicleLength;
		cin.ignore (100, '\n');
		while (!cin)
		{
			cin.clear();
			cin.ignore (100, '\n');
			cout << "\nInvalid input! Please try again. ";
			cout << "\nHow long is your vehicle in feet? ";
			cin >> vehicleLength;
		}
	
		switch (vehicleHeight)
		{	
			case 'y':
			case 'Y':		// Yes case for Tall charge.
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

				break;		// Break out of 'Y' case in switch.
			}		// Closes 'Y' case in switch.
			case 'n':
			case 'N':		// No case for Tall charge.
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

				break;		// Break out of 'N' case in switch.
			}		// Closes 'N' case in switch.
		
		}		// Closes the switch.
		
	}		// This is the end of the else if statement.
	
	
	if (error)		// Error is generated if input for vehicle length is over 40.
		cout << "\nVehicles over 40' in length are prohibited." << endl;
	else
	{
		cout << "\nYour total fare is: $" << totalFare << endl;
		cout << "\nThank you for using Jeremy's Fare Calculator." << endl;
	}

	return 0;
}