#include <iostream>
#include <stdlib.h>

extern int sum_array(int*,int);

int main(){
	int n = 5;
	int array[5]={1,2,3,4,5};

	std::cout << sum_array(array,n) << std::endl;
	
	return 0;
}