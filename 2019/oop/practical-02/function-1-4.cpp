#include <stdlib.h>
#include <iostream>

void print_scaled_matrix(int array[3][3],int scale){

	for(int a=0; a<3; a++){
		for(int b=0; b<3; b++){
			array[a][b] *= scale;
		}
	}

	for(int c=0; c<3; c++){
		for(int d=0; d<3; d++){
			std::cout << array[c][d] << " ";
		}
		std::cout << std::endl;
	}

	return;
}