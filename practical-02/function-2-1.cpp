#include <stdlib.h>
#include <iostream>

void print_as_binary(std::string decimal_number){
	
	int num = stoi(decimal_number);
	int result = 0;
	int count = 1;

	while(num!=0){

		result = result + count * (num%2);
		num = num / 2;
		count = count * 10;

	}

	std::cout << result << std::endl;

}