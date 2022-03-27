#include <iostream>
#include "meerkat.h"

using namespace std;

int main()
{
	meerkat* meerkats[4];

	for(int i=0; i<4; i++)
	{
		meerkats[i] = new meerkat();
	}

	meerkats[0] -> setName("cat1");
	meerkats[1] -> setName("cat2");
	meerkats[2] -> setName("cat3");
	meerkats[3] -> setName("cat4");

	meerkats[0] -> setAge(10);
	meerkats[1] -> setAge(20);
	meerkats[2] -> setAge(30);
	meerkats[3] -> setAge(40);

	for(int i=0; i<4; i++)
	{
		cout << meerkats[i] -> getName() << endl;
	}

	for(int i=0; i<4; i++)
	{
		cout << meerkats[i] -> getAge() << endl;
	}

	for(int i=0; i<4; i++)
	{
		delete meerkats[i];
	}
}