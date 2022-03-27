#include <iostream>
using namespace std;

int *readNumbers(int n){
	int *numbers = new int[n];
	for(int i=0; i<n; i++){
		cin >> *(numbers+i);
	}

	return numbers;
}

void months(int *monthNumbers, int length){
	for(int i = 0; i<length; i++){
		switch(*(monthNumbers+i)){
			case 1:
			cout << i << " " << *(monthNumbers+i) << " January" << endl;
			break;
			case 2:
			cout << i << " " << *(monthNumbers+i) << " February" << endl;
			break;
			case 3:
			cout << i << " " << *(monthNumbers+i) << " March" << endl;
			break;
			case 4:
			cout << i << " " << *(monthNumbers+i) << " April" << endl;
			break;
			case 5:
			cout << i << " " << *(monthNumbers+i) << " May" << endl;
			break;
			case 6:
			cout << i << " " << *(monthNumbers+i) << " June" << endl;
			break;
			case 7:
			cout << i << " " << *(monthNumbers+i) << " July" << endl;
			break;
			case 8:
			cout << i << " " << *(monthNumbers+i) << " August" << endl;
			break;
			case 9:
			cout << i << " " << *(monthNumbers+i) << " September" << endl;
			break;
			case 10:
			cout << i << " " << *(monthNumbers+i) << " October" << endl;
			break;
			case 11:
			cout << i << " " << *(monthNumbers+i) << " November" << endl;
			break;
			case 12:
			cout << i << " " << *(monthNumbers+i) << " December" << endl;
			break;
		}
	}
	return;
}