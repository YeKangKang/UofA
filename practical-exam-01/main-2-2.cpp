#include <iostream>


extern int binary_to_number(int*, int);

int main(){

	int number_of_digits = 5;
	int binary_digits[5] = {1,1,1,1,0};
	
	std::cout << binary_to_number(binary_digits,number_of_digits) << std::endl;

	return 0;
}