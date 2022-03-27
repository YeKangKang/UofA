// main to 2-2
#include <iostream>
#include <stdlib.h>

extern int maximum(int*, int);

int main(){
	int n = 6;
	int array[6] = {1,5,3,6,9,1};

	std::cout << maximum(array,n) << std::endl;

	return 0;
}