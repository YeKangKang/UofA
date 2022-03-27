// main to 1-4
#include <iostream>
#include <stdlib.h>

extern int sumtwo(int*,int*,int);

int main(){

	int n = 5;
	int array[5] = {1,2,3,4,5};
	int secondarray[5] = {5,6,7,8,9};

	std::cout << sumtwo(array,secondarray,n) << std::endl;

	return 0;
}