#include <stdlib.h>
#include <iostream>

void count_numbers(int array[4][4]){

	int test[10] = {0,0,0,0,0,0,0,0,0,0};

	for(int a=0; a<4; a++){
		for(int b=0; b<4; b++){
			if(array[a][b]<=9 && array[a][b]>=0){
				test[array[a][b]]++;
			}
		}
	}

	for(int c=0; c<10; c++){
		std::cout << c << ":" << test[c] << ";";
	}

	std::cout << std::endl;

	return;
}