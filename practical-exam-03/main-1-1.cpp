#include <iostream>
#include "Musician.h"
using namespace std;

int main(){
	Musician A;
	cout << A.get_instrument() << endl;
	cout << A.get_experience() << endl;

	Musician* B = new Musician("test",5);
	cout << B->get_instrument() << endl;
	cout << B->get_experience() << endl;

	delete B;
	return 0;
}