#include <iostream>
using namespace std;

int maximum_sum(int *nums,int length){

	int maximum = 0, row = 0;

	for (int i=0; i<length; i++){
		int sum = 0;
		for (int b=row; b<length; b++){
			sum += *(nums+b);

			if (sum >= maximum){
				maximum = sum;
			}
		}
		row++;
	}

	return maximum;

}