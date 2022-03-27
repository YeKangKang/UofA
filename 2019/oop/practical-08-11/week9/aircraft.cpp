#include "vehicle.h"
#include "aircraft.h"
#include <iostream>
using namespace std;

// set the static number as 1
int Aircraft::count = 1;

Aircraft::Aircraft():Vehicle(){
	experience = "0";
	driver = "default";
	id = to_string(count);
	count++;
}

void Aircraft::set_driverinfo(string driver_name, string years){
	driver = driver_name;
	experience = years;
}

void Aircraft::set_driver(string driver_name){
	driver = driver_name;
}

void Aircraft::set_experience(string years){
	experience = years;
}

string Aircraft::get_driver(){
	return driver;
}

string Aircraft::get_experience(){
	return experience;
}

Aircraft::~Aircraft(){

}