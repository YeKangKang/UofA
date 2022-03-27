#include <iostream>
using namespace std;

extern void copy_2d_strings(string(*)[2], string(*)[2], int);

int main(){
	int n = 3;

	string second[3][2];

	string first[3][2] = {
		{"Jack","Bob"},
		{"Henry","David"},
		{"Tony","John"}
	};
	
	copy_2d_strings(first, second, n);

	return 0;
}