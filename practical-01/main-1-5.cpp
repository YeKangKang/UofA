// main to 1-5
#include <iostream>
#include <stdlib.h>

extern int count_even(int);

int main(){

	int number = 7;

	std::cout << count_even(number) << std::endl;

	return 0;
}