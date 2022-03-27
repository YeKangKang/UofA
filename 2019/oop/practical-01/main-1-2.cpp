#include <iostream>
#include <stdlib.h>

// main-1-2

extern double average(int*, int);

int main(){
	int n = 5;
	int array[5] = {1,2,3,4,6};

	std::cout << average(array,n) << std::endl;

	return 0;
}