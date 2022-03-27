#include <iostream>

extern int *readNumbers(int);
extern void printSubArrays(int *,int);

int main(){
	int length = 3;
	int *ptr = readNumbers(length);
	printSubArrays(ptr,length);

	delete [] ptr;

	return 0;
}