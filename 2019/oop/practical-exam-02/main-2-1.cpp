#include <iostream>

extern int *readNumbers(int);
extern void months(int *, int);

int main(){
	int length = 4;
	int *ptr = readNumbers(length);
	months(ptr,length);
	delete [] ptr;

	return 0;
}