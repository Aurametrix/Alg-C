#ifndef PARKEDCAR_H
#define PARKEDCAR_H

#include <string>
#include <vector>
#include "PoliceOfficer.h"

using namespace std;

class ParkedCar
{
	private:
	string make;
	string model;
	string color;
	string license;
	string pTime;
	static int carCount;


	public:
	ParkedCar ();
	~ParkedCar ();

	// Mutator functions
	void setMake (string);
	void setModel (string);
	void setColor (string);
	void setLicense (string);
	void setPTime (string);
	void addCars ();
	// Accessor functions
	string getLicenseNumber () const;
	string getModel () const;
	string getColor () const;
	string getMake () const;
	string getPTime () const;
	int getCars () const;

	friend void PoliceOfficer::checkTime (vector<ParkedCar> &, vector<ParkedCar> &);
};
#endif 
