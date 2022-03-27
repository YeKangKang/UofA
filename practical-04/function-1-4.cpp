#include <iostream>
using namespace std;

void cpyda(double *old_array, double *new_array, int length){
	double* ptr_old = old_array;
	double* ptr_new = new_array;

	for(int i=0; i<length; i++){
		*(ptr_new+i) = *(ptr_old+i);
	}

	return;
}