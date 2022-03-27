#include <stdlib.h>
#include <iostream>

void print_summed_matrices(int array1[3][3],int array2[3][3]){


	for(int a=0; a<3; a++){
		for(int b=0; b<3; b++){
			array1[a][b] += array2[a][b];
		}
	}

	for(int c=0; c<3; c++){
		for(int d=0; d<3; d++){
			std::cout << array1[c][d] << " ";
		}
		std::cout << std::endl;
	}
}