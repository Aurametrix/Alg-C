#ifndef POLICEOFFICER_H
#define POLICEOFFICER_H

#include <string>
#include <vector>

using namespace std;

class PoliceOfficer
{
	private:
	string clockIn;
	string officerName;
	string badgeNum;
	string meterTime;
	static int policeCount;

	public:
	PoliceOfficer ();
	~PoliceOfficer ();

	// Mutator Functions
	void setTime (string);
	void setName (string);
	void setBadgeNum (string);
	void countPolice ();
	// Accessor functions
	string getClockIn () const;
	string getName () const;
	string getBadgeNum () const;

	void checkTime (vector<ParkedCar> &, vector<ParkedCar> &);
};
#endif 
