#ifndef AIRPORT_H
#define AIRPORT_H
#include <iostream>
#include <vector>
#include "aircraft.h"
#include "truck.h"
using namespace std;

class Airport{

protected:
	string airportName;					// obj name
	int maxsize;						// maxsize for in
	vector<Aircraft> aircraft;			// obj vec
	vector<Truck> truck;				// obj vec
	vector<Aircraft> air;				// obj vec
	vector<Truck> truck_outside;		// obj vec


public:
// constructor

	Airport();
	Airport(string name);


// Vehicle buying

	void buy_aircraft(string name, string year);		// create a object and set their name, add them to air
	void buy_truck(string name, string year);			// create a object and set their name, add them to out


// Vehicle adding part / Mainfunction interface
	
	int add_aircraft(string uid);			// add an aircraft into airport
	int add_truck(string uid);				// add a truck into airport


// interface for me
	
	void add_aircraft_in(Aircraft A);		// for inside airport
	void add_truck_in(Truck A);				// for inside airport
	void add_aircraft_out(Aircraft A);		// for outside airport
	void add_truck_out(Truck A);			// for outside airport


// Vehicle remove part

	int rm_aircraft(string uid);			// remove the aircraft with the aircraft ID
	int rm_truck(string uid);				// remove the truck with the truck ID


// Airport infomation part
	
	void set_name(string name);				// change the airport name
	string get_name();						// return airport name.
	Aircraft* get_aircraft();				// return a pointer of vector array
	Truck* get_truck();						// return a pointer of vector array
	Aircraft* get_outsideaircraft();		// return pointer from vector too
	Truck* get_outsidetruck();				// return pointer from vector too


// return element of vector array

	int aircraft_size();				// return aircraft size
	int truck_size();					// return truck size
	int air_size();						// return air size
	int truck_outside_size();			// return out size


// return/update detile	

	string get_aircraftdr(string uid);			// detile in aircraft/check
	string get_aircraftex(string uid);			// detile in aircraft
	string get_truckdr(string uid);				// detile in truck
	string get_truckex(string uid);				// detile in truck
	string get_airdr(string uid);				// detile in air
	string get_airex(string uid);				// detile in air
	string get_outdr(string uid);				// detile in truck
	string get_outex(string uid);				// detile in truck

// update detile

	void update_aircraft(string uid, string name, string years);		// update in aircraft
	void update_truck(string uid, string name, string years);			// update in truck
	void update_air(string uid, string name, string years);			// update in air
	void update_out(string uid, string name, string years);			// update in outside

// check uid exist

	int check_aircraft(string uid);				// check did uid exist
	int check_truck(string uid);					// check did uid exist
	int check_air(string uid);						// check did uid exist
	int check_out(string uid);						// check did uid exist


// destructor

	~Airport();
};
#endif