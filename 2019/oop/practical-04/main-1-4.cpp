#include <iostream>
using namespace std;

extern void cpyda(double*, double*, int);

int main(){
	int length = 5;
	double old_array[5] = {1.1,2.2,3.3,4.4,5.5};
	double new_array[5];

	cpyda(old_array,new_array,length);


	return 0;
}