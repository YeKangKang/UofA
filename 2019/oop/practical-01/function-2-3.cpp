// function to 2-3

#include <iostream>
#include <stdlib.h>

void twofivenine(int array[],int n){

	int num_twos = 0;
	int num_fives = 0;
	int mun_nunes = 0;

	for(int i=0; i<n; i++){
		switch(array[i]){
			case 2:
			num_twos += 1;
			break;
			case 5:
			num_fives += 1;
			break;
			case 9:
			mun_nunes += 1;
			break;
		}
	}

	std::cout << "2:" << num_twos << ";5:" << num_fives << ";9:" << mun_nunes <<";" << std::endl;
}