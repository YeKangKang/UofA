#ifndef MUSICIAN_H
#define MUSICIAN_H
#include <iostream>
using namespace std;

class Musician{
public:
	int years;
	string A;
	Musician();
	Musician(string instrument, int experience);
	string get_instrument();
	int get_experience();
	~Musician();
};
#endif