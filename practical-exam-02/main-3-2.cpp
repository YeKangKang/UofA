#include <iostream>

extern int *readNumbers(int);
extern int *mergeArrays(int*, int*, int);
extern void printNumbers(int *, int);

int main(){
	int length = 4;
	int *ptr1;
	int *ptr2;
	int *final_ptr;

	ptr1 = readNumbers(length);
	ptr2 = readNumbers(length);

	final_ptr = mergeArrays(ptr1,ptr2,length);
	printNumbers(final_ptr,length);

	delete [] ptr1;
	delete [] ptr2;
	delete [] final_ptr;

	return 0;
}