#include <iostream>

void printer(int array[10][10]){
	for(int i=0; i<10; i++){
		for(int n=0; n<10; n++){
			if(n == 9){
				std::cout << array[i][n];
			}else{
				std::cout << array[i][n] << " ";
			}
		}
		std::cout << std::endl;
	}
}