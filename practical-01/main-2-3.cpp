// main to 2-3

#include <iostream>
#include <stdlib.h>

extern void twofivenine(int*,int);

int main(){

	int n = 20;
	int array[20] = {1,2,5,2,2,2,4,5,5,9,9,6,8,9,9,4,5,2,4,6};

	twofivenine(array,n);

	return 0;
}