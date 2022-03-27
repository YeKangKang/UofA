#include <iostream>

extern int *readNumbers(int);
extern bool twinArray(int *, int);

int main(){
	int length = 6;
	int *ptr = readNumbers(length);
	twinArray(ptr,length);
	delete [] ptr;

	return 0;
}