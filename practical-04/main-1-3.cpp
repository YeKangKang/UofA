#include <iostream>
using namespace std;

extern void cpyia(int*, int*, int);

int main(){
	int length = 5;
	int old_array[5] = {1,2,3,4,5};
	int new_array[5];

	cpyia(old_array, new_array, length);

	return 0;
}