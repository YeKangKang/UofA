#include <iostream>
using namespace std;

void copy_2d_strings(string first[][2], string second[][2], int n){
	for (int i=0; i<n; i++){
		for(int o=0; o<2; o++){
			second[i][o] = first[i][o];
		}
	}

	/* Because it's 2D array, so the arrayname is alreade be a pointer, 
		it can direactly de-refference the location which pointer point to */
	
	return;
}