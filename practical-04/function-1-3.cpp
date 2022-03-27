#include <iostream>
using namespace std;

void cpyia(int old_array[], int new_array[], int length){
	int* ptr = old_array;

	for (int i=0; i<length; i++){
		new_array[i] = *(ptr+i);
	}

	return;
}