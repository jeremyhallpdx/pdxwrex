/*	
 *	CS161	-	Assignment 03
 *	Date:		19-October-2008
 *	Author:		Jeremy Hall
 *	Sources:	None
 *	Desc:		This program figures the fare for a ferry trip to Friday Harbor from Anacortes, WA. It asks the user for
 *				specific data and calculates the appropriate fare based on the user's entries.
 */

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const double ADULT_FARE = 10.95;
const double SENIOR_FARE = 5.45;
const double YOUTH_FARE = 8.80;
const double BICYCLE_SURCHARGE = 2.00;
const double VEHICLE_UNDER20_PLUSDRIVER_FARE = 37.90;
const double VEHICLE_UNDER20_PLUSSENIOR_FARE = 32.40;
const double VEHICLE_TALL_SURCHARGE = 37.90;
const double VEHICLE_20TO29_SHORT_FARE = 56.85;
const double VEHICLE_20TO29_TALL_FARE = 113.70;
const double VEHICLE_30TO39_FARE = 151.60;


int main()
{
	int vehicleLength = 0;
	char reply;
	char senior;
	char vehicleHeight;
	double adultPassenger = 0.0;
	double seniorPassenger = 0.0;
	double youthPassenger = 0.0;
	double numPassengers = 0.0;
	double passengerFare = 0.0;
	double vehicleFare = 0.0;
	double totalFare = 0.0;

	cout << fixed << showpoint << setprecision (2);
	cout << "Welcome to Jeremy's Fare Calculator!" << endl;								
	cout << "Are you driving a vehicle on to the ferry? (y/n): ";					
	cin >> reply;		
	cin.ignore (100, '\n');
	
	if (reply == 'y' || reply == 'Y')
		cout << endl;
	else if(reply == 'n' || reply == 'N')
	{
		int age;

		cout << "Are you riding a bicycle on to the ferry? (y/n): ";
		cin >> reply;
		cin.ignore (100, '\n');
		
		cout << "Please enter your age: ";
			cin >> age;
			cin.ignore (100, '\n');
			
			if (age <= 18 && age >= 5)
				totalFare = totalFare + YOUTH_FARE;
			else if (age > 19 && age < 64)
				totalFare = totalFare + ADULT_FARE;
			else if(age >= 65)
				totalFare = totalFare + SENIOR_FARE;

		if (reply == 'y' || reply == 'Y')
			
			totalFare = totalFare + BICYCLE_SURCHARGE;

		cout << endl;	
		cout << "Your total fare is: $" << totalFare << endl;
		return 0;
	}
	else
	{	
		cout << "\nInvalid input!  Programming terminating." << endl;
		return (-1);
	}

	cout << "Is the driver a senior cititzen (65 or older) or disabled? (y/n): ";
	cin >> senior;
	cin.ignore (100, '\n');
	if (senior == 'y' || senior == 'Y')
		cout << endl;
	else if (senior == 'n' || senior == 'N')
		cout << endl;
	else
	{	
		cout << "\nInvalid input! Program terminating." << endl;
		return (-1);
	}

	cout << "How many passengers in your vehicle (excluding driver)?" << endl;		
	cout << "Number of Adults(age 19-64): ";
	cin >> adultPassenger;
	cin.ignore (100, '\n');
	if (!cin)
	{
		cout << "\nInvalid input! Program terminating." << endl;
		return (-1);
	}

		adultPassenger = adultPassenger * ADULT_FARE;

	cout << "Number of Senior Citizens(age 65 or older) : ";
	cin >> seniorPassenger;
	cin.ignore (100, '\n');
	if (!cin)
	{
		cout << "\nInvalid input! Program terminating." << endl;
		return (-1);
	}

		seniorPassenger = seniorPassenger * SENIOR_FARE;

	cout << "Number of Children(age 5-18): ";
	cin >> youthPassenger;
	cin.ignore (100, '\n');
	if (!cin)
	{
		cout << "\nInvalid input! Program terminating." << endl;
		return (-1);
	}

		youthPassenger = youthPassenger * YOUTH_FARE;

		passengerFare = adultPassenger + seniorPassenger + youthPassenger;

	cout << "Is your vehicle over 7 feet, 6 inches in height? (y/n): ";
	cin >> vehicleHeight;
	cin.ignore (100, '\n');

	switch (vehicleHeight)
	{	
	case 'y':
	case 'Y':
		cout << "How long is your vehicle in feet? ";
		cin >> vehicleLength;
		cin.ignore (100, '\n');
		if (!cin)
		{
			cout << "\nInvalid input! Program terminating." << endl;
			return (-1);
		}

		if (vehicleLength <= 19 && senior == 'y' || senior == 'Y')
			vehicleFare = vehicleFare + VEHICLE_UNDER20_PLUSSENIOR_FARE + VEHICLE_TALL_SURCHARGE;
		else if (vehicleLength <= 19 && senior == 'n' || senior == 'N')
			vehicleFare = vehicleFare + VEHICLE_UNDER20_PLUSDRIVER_FARE + VEHICLE_TALL_SURCHARGE;
		else if (vehicleLength <= 29)
			vehicleFare = vehicleFare + VEHICLE_20TO29_TALL_FARE;
		else
			vehicleFare = vehicleFare + VEHICLE_30TO39_FARE;
		break;
		
	case 'n':
	case 'N':
		cout << "How long is your vehicle in feet? ";
		cin >> vehicleLength;
		cin.ignore (100, '\n');
		if (!cin)
		{
			cout << "\nInvalid input! Program terminating." << endl;
			return (-1);
		}

		if (vehicleLength <= 19 && senior == 'y' || senior == 'Y')
			vehicleFare = vehicleFare + VEHICLE_UNDER20_PLUSSENIOR_FARE;
		else if (vehicleLength <= 19 && senior == 'n' || senior == 'N')
			vehicleFare = vehicleFare + VEHICLE_UNDER20_PLUSDRIVER_FARE;
		else if (vehicleLength <= 29 && vehicleLength >= 20)
			vehicleFare = vehicleFare + VEHICLE_20TO29_SHORT_FARE;
		else if (vehicleLength <= 39 && vehicleLength >= 30) 
			vehicleFare = vehicleFare + VEHICLE_30TO39_FARE;
		else
		{
			cout << "40' vehicles are Prohibited." << endl;
			return (-1);
		}
		break;

	default:
		{
			cout << "\nInvalid input! Program terminating." << endl;
			return (-1);
		}
	}

		totalFare = vehicleFare + passengerFare;

	cout << "\nYour total fare is: $" << totalFare << endl;
	cout << "\nThank you for using Jeremy's Fare Calculator!" << endl;

	return 0;
}