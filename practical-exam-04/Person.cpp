#include "Person.h"
#include <iostream>
using namespace std;

Person::Person(){

}

Person::Person(string n, string o, int sl){
	name = n;
	occupation = o;
	serviceLength = sl;
	salary = 1;
}

void Person::set_name(string input){
	name = input;
}

string Person::get_name(){
	return name;
}

void Person::set_occupation(string input){
	occupation = input;
}

string Person::get_occupation(){
	return occupation;
}

void Person::set_salary(int input){
	if (input >= 0){
		salary = input;
	}
}

int Person::get_serviceLength(){
	return serviceLength;
}

int Person::get_personID(){
	return personID;
}

Person::~Person(){

}