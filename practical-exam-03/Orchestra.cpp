#include "Orchestra.h"
#include "Musician.h"
#include <iostream>
using namespace std;

Orchestra::Orchestra(){
	check = 0;
	number = 0;
}

Orchestra::Orchestra(int size){
	check = size;
	number = 0;
}

Orchestra::~Orchestra(){

}

// returns the number of musicians who have joined the orchestra
int Orchestra::get_current_number_of_members(){
	return number;
}

// returns true if any musician in the orchestra plays the specified instrument
// otherwise returns false
bool Orchestra::add_musician(Musician new_musician){
	if(number == check){
		return false;
	}else{
		total[number] = new_musician;
		number++;
		return true;
	}
}

Musician *Orchestra::get_members(){
	return total;
}

bool Orchestra::has_instrument(string instrument){
	for(int i=0; i<number; i++){
		if(instrument == total[i].get_instrument()){
			return true;
		}
	}
	return false;
}