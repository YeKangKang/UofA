#ifndef PERSON_H
#define PERSON_H
#include <iostream>
using namespace std;

class Person{
protected:
	string name;		// the name of a person
 	string occupation;	// the occupation of a person
 	int salary;			// the salary of a person; takes only non-negative values
 	int serviceLength;	// the service length of a person
 	int personID;		// the unique ID of a person
 public:
 	Person(string n, string o, int sl);
 	Person();
 	// for name
 	void set_name(string input);
 	string get_name();
 	// for occupation
 	void set_occupation(string input);
 	string get_occupation();
 	// for salary
 	void set_salary(int input);
 	virtual int get_salary()=0;
 	// for serviceLength
 	int get_serviceLength();
 	// for personID
 	int get_personID();
 	~Person();
};
#endif