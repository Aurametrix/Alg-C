#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>
#include <vector>
#include "ParkedCar.h"
#include "ParkingMeter.h"
#include "ParkingTicket.h"
#include "PoliceOfficer.h"

using namespace std;

int main ()
{
	fstream inFile ("parking.dat", ios::in);
	ParkedCar *pc;
	ParkingMeter *pm;
	PoliceOfficer *officer;
	vector<ParkedCar> cars (0);
	vector<ParkingMeter> meter (0);

	int spot;
	string holdData;
	string holdSpot;

	if (inFile.fail ())
	{
		cout << "Error, could not open parking.txt";
	}

	// started to try to work with the things you were showing me here
	while (inFile.good ())
	{
		inFile >> holdData;

		if (holdData == "enter")
		{
			pc = new ParkedCar ();
			pc->addCars ();

			pm = new ParkingMeter;
			pm->addMeters ();

			inFile >> holdSpot;
			spot = stoi (holdSpot);
			cout << " This is spot " << spot << endl;
			pc->setInSpot (holdSpot);

			inFile >> holdData;
			pc->setPTime (holdData);
			inFile >> holdData;
			pc->setMake (holdData);
			inFile >> holdData;
			pc->setModel (holdData);
			inFile >> holdData;
			pc->setColor (holdData);
			inFile >> holdData;
			pc->setLicense (holdData);
			inFile >> holdData;
			pm->setTimePaid (holdData);

			cars.insert (cars.begin (), spot, *pc);			// I am not worried about performance for this project, I am just worried about making it easier on myself
			// It is due in 4 days.
			meter.insert (meter.begin (), spot, *pm);

			cout << "This is the vector spot " << cars [spot - 1].getInSpot () << endl << endl;			// test code. I now know meter was stored correctly as well.

			// just to see what is going on.
			cout << pc->getPTime () << " " << pc->getMake () << " " << pc->getModel () << " " << pc->getColor () << " " << pc->getLicenseNumber () << " " << pm->getTimePaid () << endl;
		}
		else if (holdData == "in")
		{
			// let a new police officer come in
			officer = new PoliceOfficer;
			officer->countPolice ();

			// get his data needed.
			inFile >> holdData;
			officer->setName (holdData);
			inFile >> holdData;
			officer->setBadgeNum (holdData);
			inFile >> holdData;
			officer->setIn (holdData);
		}
		else if (holdData == "out")
		{
			//delete officer;			// whether this is commented out or not, VS 2013 Ultimate will not let me run this code do to a potentially uninitialized pointer.
			// If I show you the file, the way it is structured, there will be a pointer. VS does not know this
		}

		else if (holdData == "exit")
		{
			string eTime;	// get exit time

			inFile >> holdSpot;	// get parking spot
			spot = stoi (holdSpot);
			inFile >> eTime; // get exit time

			cout << " now calling officer->checkTime\n";
			officer->checkTime (pc, eTime); // police officer checks the time

			//delete pm;
		}
	}

	// this was just test code to see what was happening to my member functions and if memory was stored correctly.

	//for (int i = 0; i < 4; i++)
	//{

	//}

	cout << "\n\n";
	inFile.close ();

	system ("pause");
	return 0;
}
Edit & Run

