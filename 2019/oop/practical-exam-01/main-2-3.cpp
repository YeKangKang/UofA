#include <iostream>

extern int sum_if_a_palindrome(int*, int);

int main(){
	int length = 5;
	int integers[5] = {1,2,3,2,1};

	std::cout << sum_if_a_palindrome(integers,length) << std::endl;
}