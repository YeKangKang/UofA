#include <iostream>
#include <stdlib.h>
#include "RandomComputer.h"

RandomComputer::RandomComputer() {
	move = 'E';
}

RandomComputer::~RandomComputer() {

}

char RandomComputer::makeMove() {
	int ans;
	ans = (rand() % (3 - 1 + 1)) + 1;
	if (ans == 1) {
		return 'R';
	} else if (ans == 2) {
		return 'S';
	} else if (ans == 3) {
		return 'P';
	}

	return 'E';
}