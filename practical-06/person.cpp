#include <iostream>
#include "person.h"

using namespace std;

person::person(string myName, int Salary)
{
	name = myName;
	money = Salary;
}

person::~person()
{

}

void person::setName(string myName)
{
	name = myName;
}

void person::setSalary(int mySalary)
{
	money = mySalary;
}

string person::getName()
{
	return name;
}

int person::getSalary()
{
	return money;
}