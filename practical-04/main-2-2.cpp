#include <iostream>
using namespace std;

extern int maximum_sum(int*, int);

int main(){

	int length = 10;
	int number_array[10] = { 31, -41, 59, 26, -53, 58, 97, -93, -23, 84 };

	cout << maximum_sum(number_array,length) << endl;

	return 0;
}