// main to 2-1
#include <iostream>
#include <stdlib.h>

extern int minimum(int*, int);

int main(){
	int n = 6;
	int array[6] = {5,4,2,6,6,4};

	std::cout << minimum(array,n) << std::endl;

	return 0;
}