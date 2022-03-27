#include <iostream>
#include <stdlib.h>

extern bool ascending(int*,int);

int main(){

	int n = 5;
	int array[5] = {1,2,3,4,5};

	std::cout << ascending(array,n) << std::endl;

	return 0;
}