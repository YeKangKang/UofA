#include <iostream>
using namespace std;

int *readNumbers(int n){
	int *numbers = new int[n];
	for(int i=0; i<n; i++){
		cin >> *(numbers+i);
	}

	return numbers;
}

bool twinArray(int* numbers, int length){
	if(length<1){
		return false;
	}else{
		int part = length/2;
		int count = 0;
		int location = 0;
		while(count != part){
			if(numbers[location]!=numbers[location+1]){
				return false;
			}
			location = location + 2;
			count++;
		}
		return true;
	}
}