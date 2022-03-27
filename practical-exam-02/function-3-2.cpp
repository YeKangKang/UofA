#include <iostream>
using namespace std;

int *readNumbers(int n){
	int *numbers = new int[n];
	for(int i=0; i<n; i++){
		cin >> *(numbers+i);
	}

	return numbers;
}

int* mergeArrays(int* A, int* B, int length){
	int *ptr = new int[length*2];
	int count = 0;
	for(int i=0; i<length; i++){
		*(ptr+i) = *(A+i);
	}
	for(int i=length; i<2*length; i++){
		*(ptr+i) = *(B+count);
		count++;
	}
	return ptr;
}

void printNumbers(int *numbers, int length){
	for(int i=0; i<2*length; i++){
		cout << i << " " << *(numbers+i) << endl;
	}
	return;
}