#include <iostream>
using namespace std;

int *readNumbers(int n){
	int *numbers = new int[n];
	for(int i=0; i<n; i++){
		cin >> *(numbers+i);
	}

	return numbers;
}

void printNumbers(int *numbers, int length){
	for(int i=0; i<length; i++){
		cout << i << " " << *(numbers+i) << endl;
	}
	return;
}