#include <iostream>
#include "Person.h"
#include "Coach.h"
#include "Player.h"
using namespace std;

void SortPerson::sort(Person **people, int n){
	array = people;
	int i, key,
	for (int i=1; i<number; i++){
		if (min >= array[i]->get_personID()){
			min = array[i]->get_personID();
		}
	}
}