#ifndef PERSON_H
#define PERSON_H
#include <iostream>
using namespace std;

class person
{
public:
	string name;
	int money;
	person(string myName, int Salary);
	void setName(string myName);
	string getName();
	void setSalary(int mySalary);
	int getSalary();
	~person();
};
#endif