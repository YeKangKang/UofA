#include <iostream>
using namespace std;

extern void print_sevens(int*, int);

int main(){
	int nums[6] = {1,2,7,21,5,63};
	int length = 6;

	print_sevens(nums,length);

	return 0;
}