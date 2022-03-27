#include <iostream>
#include "cart.h"

using namespace std;

int main()
{
	cart* object = new cart();
	meerkat* kat[5];

	for(int i=0; i<5; i++){
		kat[i] = new meerkat();
		//kat[i] -> setName("Jack");
		//kat[i] -> setAge(10);
	}

	for(int i=0; i<5; i++){
		object -> addMeerkat(*kat[i]);
	}

	/*for(int i=0; i<5; i++){
		kat[i] -> ~meerkat();
	}

	object -> ~cart();*/

	return 0;
}