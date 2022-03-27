#ifndef SORTPERSON_H
#define SORTPERSON_H
#include <iostream>
#include "Person.h"
#include "Coach.h"
#include "Player.h"
using namespace std;

class SortPerson{
public:
	Person** array;
	static void sort(Person **people, int n);
		/* sorts the array of n persons in ascending 
			order base on their personID*/
};
#endif