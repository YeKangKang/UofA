#ifndef ORCHESTRA_H
#define ORCHESTRA_H
#include "Musician.h"
#include <iostream>

using namespace std;

class Orchestra : public Musician{
public:
	Musician total[50];
	int check;
	int number;

	Orchestra();
	Orchestra(int size);

	bool has_instrument(string instrument);
	bool add_musician(Musician new_musician);

	int get_current_number_of_members();
	Musician *get_members();

	~Orchestra();
};
#endif