#ifndef COACH_H
#define COACH_H
#include <iostream>
#include "Person.h"
using namespace std;

class Coach : public Person{
private:
	static int nextID;
public:
	Coach(string n, int sl);		// creates a person with name n, whose occupation 
									// is “coach” and service length is sl
	int get_salary();
	~Coach();
};
#endif