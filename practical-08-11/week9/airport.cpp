#include <iostream>
#include <vector>
#include "airport.h"
#include "aircraft.h"
#include "truck.h"
using namespace std;

Airport::Airport (){
	airportName = "default name";
	maxsize = 20;
}

Airport::Airport (string name){
	airportName = name;
	maxsize = 20;
}

void Airport::buy_aircraft(string name, string year){
	Aircraft A;
	A.set_driver(name);
	A.set_experience(year);
	air.push_back(A);
}

void Airport::buy_truck(string name, string year){
	Truck A;
	A.set_driver(name);
	A.set_experience(year);
	truck_outside.push_back(A);
}

void Airport::add_aircraft_in(Aircraft A){
	if(aircraft.size() < maxsize){
		aircraft.push_back(A);
	}else{
		cout << "Error of interface 'add_aircraft_in'!!!!!!!!!!!!!!!!!!!!" << endl;
	}
}
void Airport::add_truck_in(Truck A){
	if(truck.size() < maxsize){
		truck.push_back(A);
	}else{
		cout << "Error of interface 'add_aircraft_in'!!!!!!!!!!!!!!!!!!!!" << endl;
	}
}
void Airport::add_aircraft_out(Aircraft A){
		air.push_back(A);
}
void Airport::add_truck_out(Truck A){
		truck_outside.push_back(A);
}

/*	0=sizeError
	1=working
	2=notfund*/

int Airport::add_aircraft (string uid){
	if (aircraft.size() == maxsize){
		return 0;
	}else{
		int count = 0;
		int check = 0;
		for (int i=0; i<air.size(); i++){
			if (air[i].get_id() == uid){
				aircraft.push_back(air[i]);
				air.erase(air.begin()+count);
				check = 1;
			}
			count++;
		}
		if (check == 0){
			return 2;
		}
		return 1;
	}
}

int Airport::add_truck (string uid){
	if (truck.size() == maxsize){
		return 0;
	}else{
		int count = 0;
		int check = 0;
		for (int i=0; i<truck_outside.size(); i++){
			if (truck_outside[i].get_id() == uid){
				truck.push_back(truck_outside[i]);
				truck_outside.erase(truck_outside.begin()+count);
				check = 1;
			}
			count++;
		}
		if (check == 0){
			return 2;
		}
	}
	return 1;
}

int Airport::rm_aircraft (string uid){
	int count = 0;
	int check = 0;
	for (int i=0; i<aircraft.size (); i++){
		if (aircraft[i].get_id () == uid){
			air.push_back (aircraft[i]);
			aircraft.erase (aircraft.begin ()+count);
			check = 1;
		}
		count++;
	}
	if (check == 0){
		return 2;
	}
	return 1;
}

int Airport::rm_truck (string uid){
	int count = 0;
	int check = 0;
	for (int i=0; i<truck.size(); i++){
		if (truck[i].get_id () == uid){
			truck_outside.push_back (truck[i]);
			truck.erase (truck.begin ()+count);
			check = 1;
		}
		count++;
	}
	if (check == 0){
		return 2;
	}
	return 1;
}

void Airport::set_name (string name){
	airportName = name;
	return;
}

string Airport::get_name (){
	return airportName;
}

Aircraft* Airport::get_aircraft (){
	return &aircraft[0];
}

Truck* Airport::get_truck (){
	return &truck[0];
}

Aircraft* Airport::get_outsideaircraft (){
	return &air[0];
}

Truck* Airport::get_outsidetruck (){
	return &truck_outside[0];
}

int Airport::aircraft_size(){
	return aircraft.size();
}

int Airport::truck_size(){
	return truck.size();
}

int Airport::air_size(){
	return air.size();
}

int Airport::truck_outside_size(){
	return truck_outside.size();
}

string Airport::get_aircraftdr(string uid){
	for (int i=0; i<aircraft.size(); i++){
		if (aircraft[i].get_id() == uid){
			return aircraft[i].get_driver();
		}
	}
	return "CuoLaWoCao";
}

string Airport::get_aircraftex(string uid){
	for (int i=0; i<aircraft.size(); i++){
		if (aircraft[i].get_id() == uid){
			return aircraft[i].get_experience();
		}
	}
	return "CuoLaWoCao";
}

string Airport::get_truckdr(string uid){
	for (int i=0; i<truck.size(); i++){
		if (truck[i].get_id() == uid){
			return truck[i].get_driver();
		}
	}
	return "CuoLaWoCao";
}

string Airport::get_truckex(string uid){
	for (int i=0; i<truck.size(); i++){
		if (truck[i].get_id() == uid){
			return truck[i].get_experience();
		}
	}
	return "CuoLaWoCao";
}

string Airport::get_airdr(string uid){
	for (int i=0; i<air.size(); i++){
		if (air[i].get_id() == uid){
			return air[i].get_driver();
		}
	}
	return "CuoLaWoCao";
}

string Airport::get_airex(string uid){
	for (int i=0; i<air.size(); i++){
		if (air[i].get_id() == uid){
			return air[i].get_experience();
		}
	}
	return "CuoLaWoCao";
}

string Airport::get_outdr(string uid){
	for (int i=0; i<truck_outside.size(); i++){
		if (truck_outside[i].get_id() == uid){
			return truck_outside[i].get_driver();
		}
	}
	return "CuoLaWoCao";
}

string Airport::get_outex(string uid){
	for (int i=0; i<truck_outside.size(); i++){
		if (truck_outside[i].get_id() == uid){
			return truck_outside[i].get_experience();
		}
	}
	return "CuoLaWoCao";
}

void Airport::update_aircraft(string uid, string name, string years){
	for (int i=0; i<aircraft.size(); i++){
		if (aircraft[i].get_id() == uid){
			aircraft[i].set_driver(name);
			aircraft[i].set_experience(years);
		}
	}
}

void Airport::update_truck(string uid, string name, string years){
	for (int i=0; i<truck.size(); i++){
		if (truck[i].get_id() == uid){
			truck[i].set_driver(name);
			truck[i].set_experience(years);
		}
	}
}

void Airport::update_air(string uid, string name, string years){
	for (int i=0; i<air.size(); i++){
		if (air[i].get_id() == uid){
			air[i].set_driver(name);
			air[i].set_experience(years);
		}
	}
}

void Airport::update_out(string uid, string name, string years){
	for (int i=0; i<truck_outside.size(); i++){
		if (truck_outside[i].get_id() == uid){
			truck_outside[i].set_driver(name);
			truck_outside[i].set_experience(years);
		}
	}
}

int Airport::check_aircraft(string uid){
	for (int i=0; i<aircraft.size(); i++){
		if (aircraft[i].get_id() == uid){
			return 0;
		}
	}
	return 1;
}

int Airport::check_truck(string uid){
	for (int i=0; i<truck.size(); i++){
		if (truck[i].get_id() == uid){
			return 0;
		}
	}
	return 1;
}

int Airport::check_air(string uid){
	for (int i=0; i<air.size(); i++){
		if (air[i].get_id() == uid){
			return 0;
		}
	}
	return 1;
}

int Airport::check_out(string uid){
	for (int i=0; i<truck_outside.size(); i++){
		if (truck_outside[i].get_id() == uid){
			return 0;
		}
	}
	return 1;
}



Airport::~Airport (){

}