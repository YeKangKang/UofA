#include <iostream>
#include <stdlib.h>

extern int count(int*,int,int);

int main(){

	int n = 7;
	int array[7] = {1,5,5,4,5,6,8};
	int number = 5;

	std::cout << count(array,n,number) << std::endl;

	return 0;
}