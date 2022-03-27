#include <stdlib.h>
#include <iostream>

int binary_to_number(int binary_digits[], int number_of_digits){

	int num = 0;

	for(int i=0; i<number_of_digits; i++){
		num = num*2 + binary_digits[i];
	}

	return num;
}