// main to 3-1

#include <iostream>
#include <stdlib.h>

extern bool fanarray(int*,int);

int main(){

	int n = 4;
	int array[4] = {1,2,2,1};

	std::cout << fanarray(array,n) << std::endl;
	return 0;

}