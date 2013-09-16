#include <iostream>
#include "money.h"

using namespace std;

int main()
{
	// Common convention is that constants are all capital
	const int PENNY = 1;
	const int NICKEL = 5;
	const int DIME = 10;
	const int QUARTER = 25;
	
	int money;
	int coin;
	
	cout << "Please enter in a dollar amount to convert it to change ";
	cin >> money;
	
	cout << "Do you want to convert it to: \n"
	<< "1) Pennies\n"
	<< "2) Nickels\n"
	<< "3) Dimes\n"
	<< "4) Quarters" << endl;
	
	char choice;
	cin >> choice;
	
	switch(choice)
	{
		case '1':
			// Do Pennies Here
			coin = PENNY;
			break;
		case '2':
			// Do Nickels Here
			coin = NICKEL;
			break;
		case '3':
			// Do Dimes Here
			coin = DIME;
			break;
		case '4':
			// Do Quarters Here
			coin = QUARTER;
			break;
		default:
			// If the user entered an invalid choice handle it here.
			return -1;
	}
	cout << "The result is: " << ((money * 100) / coin) << " in " << money << " dollars." << endl;
	return 0;
}