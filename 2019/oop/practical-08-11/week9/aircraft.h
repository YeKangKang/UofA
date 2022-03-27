#ifndef AIRCRAFT_H
#define AIRCRAFT_H
#include <iostream>
#include "vehicle.h"
using namespace std;

class Aircraft : public Vehicle{
protected:
	static int count;
	// aircraft's driver experience
	string experience;
	string driver;
public:
	Aircraft();
	// the interface to let main function easy to write
	void set_driverinfo(string driver_name, string years);
	void set_driver(string driver_name);
	void set_experience(string years);
	string get_driver();
	string get_experience();
	~Aircraft();
};
#endif