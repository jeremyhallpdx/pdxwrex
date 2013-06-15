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

const double ADULT_FARE = 13.15;
const double SENIOR_FARE = 6.55;
const double YOUTH_FARE = 10.55;
const double BICYCLE_SURCHARGE = 4.00;
const double VEHICLE_UNDER20_PLUSDRIVER_FARE = 51.20;
const double VEHICLE_UNDER20_PLUSSENIOR_FARE = 44.60;
const double VEHICLE_TALL_SURCHARGE = 51.20;
const double VEHICLE_20TO29_SHORT_FARE = 76.80;
const double VEHICLE_20TO29_TALL_FARE = 153.60;
const double VEHICLE_30TO39_FARE = 204.80;


int main()
{
	int vehicleLength = 0;
	int passenger = 0;
	char reply;
	char senior;
	char vehicleHeight;
	double groupFare = 0.0;
	double passengerFare = 0.0;
	double vehicleFare = 0.0;
	double totalFare = 0.0;

	cout << fixed << showpoint << setprecision (2);
	cout << "Welcome to Jeremy's Fare Calculator!" << endl;								
	cout << "\nAre you driving a vehicle on to the ferry? (y/n): ";					
	cin >> reply;		
	cin.ignore (100, '\n');
	
	switch (reply)
	{
	case 'n':
	case 'N':
	{
		cout << "\nHow many Adults (age 19 - 64) in your group? ";
		cin >> passenger;
		cin.ignore (100, '\n');
		if (!cin)
		{
			cout << "\nInvalid input! Program terminating." << endl;
			
			return (-1);
		}

		groupFare = groupFare + passenger * ADULT_FARE;

		cout << "\nHow many Senior Citizens (age 65 or older), or disabled persons in your group? ";
		cin >> passenger;
		cin.ignore (100, '\n');
		if (!cin)
		{
			cout << "\nInvalid input! Program terminating." << endl;
			
			return (-1);
		}
		
		groupFare = groupFare + passenger * SENIOR_FARE;

		cout << "\nHow many Youth (age 5 - 18) in your group? ";
		cin >> passenger;
		cin.ignore (100, '\n');
		if (!cin)
		{
			cout << "\nInvalid input! Program terminating." << endl;
			
			return (-1);
		}

		groupFare = groupFare + passenger * YOUTH_FARE;

		cout << "\nHow many people in your group are traveling with a bicycle? ";
		cin >> passenger;
		cin.ignore (100, '\n');
		if (!cin)
		{
			cout << "\nInvalid input! Program terminating." << endl;
			
			return (-1);
		}

		groupFare = groupFare + passenger * BICYCLE_SURCHARGE;
		
		cout << "\nYour total fare is: $" << groupFare << endl;

		return 0;
	}
	case 'y':
	case 'Y':
	{	
		cout << "\nIs the driver a senior cititzen (65 or older) or disabled? (y/n): ";
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
		cin >> passenger;
		cin.ignore (100, '\n');
		if (!cin)
		{
			cout << "\nInvalid input! Program terminating." << endl;
			
			return (-1);
		}
		
		passengerFare = passengerFare + passenger * ADULT_FARE;

		cout << "Number of Senior Citizens(age 65 or older) : ";
		cin >> passenger;
		cin.ignore (100, '\n');
		if (!cin)
		{
			cout << "\nInvalid input! Program terminating." << endl;
			
			return (-1);
		}
		
		passengerFare = passengerFare + passenger * SENIOR_FARE;

		cout << "Number of Children(age 5-18): ";
		cin >> passenger;
		cin.ignore (100, '\n');
		if (!cin)
		{
			cout << "\nInvalid input! Program terminating." << endl;
			
			return (-1);
		}
		
		passengerFare = passengerFare + passenger * YOUTH_FARE;

		cout << "\nIs your vehicle over 7 feet, 6 inches in height? (y/n): ";
		cin >> vehicleHeight;
		cin.ignore (100, '\n');

		switch (vehicleHeight)
		{	
		case 'y':
		case 'Y':
			cout << "\nHow long is your vehicle in feet? ";
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
			cout << "\nHow long is your vehicle in feet? ";
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
				cout << "\n40' vehicles are Prohibited." << endl;
				
				return (-1);
			}
			break;

		default:
			{
				cout << "\nInvalid input! Program terminating." << endl;
				
				return (-1);
			}
		}
		break;
	
	default:
	{	
		cout << "\nInvalid input!  Programming terminating." << endl;
		
		return (-1);
	}	
	}
	}
	
	totalFare = vehicleFare + passengerFare;

	cout << "\nYour total fare is: $" << totalFare << endl;
	cout << "\nThank you for using Jeremy's Fare Calculator!" << endl;

	return 0;
}