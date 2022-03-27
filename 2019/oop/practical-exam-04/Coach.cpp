#include "Person.h"
#include "Coach.h"
#include <iostream>
using namespace std;

int Coach::nextID = 0;

Coach::Coach(string n, int sl):Person(){
	personID = nextID;
	occupation = "coach";
	serviceLength = sl;
	salary = 0;
	name = n;
	nextID++;
}

int Coach::get_salary(){
	if (serviceLength<15){
		return salary;
	}else{
		return 3*salary;
	}
}

Coach::~Coach(){
	
}