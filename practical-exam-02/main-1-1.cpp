#include <iostream>

extern int *readNumbers(int);
extern void printNumbers(int *, int);

int main(){
	int length = 3;
	int *ptr = readNumbers(length);
	printNumbers(ptr,length);
	delete [] ptr;

	return 0;
}