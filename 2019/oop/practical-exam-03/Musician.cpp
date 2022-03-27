#include "Musician.h"
#include <iostream>
using namespace std;

Musician::Musician(){
	A = "null";
	years = 0;
}

Musician::Musician(string instrument, int experience){
	A = instrument;
	years = experience;
}

string Musician::get_instrument(){
	return A;
}

int Musician::get_experience(){
	return years;
}

Musician::~Musician(){
	
}