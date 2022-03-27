#include <iostream>
#include "person.h"

using namespace std;

int main()
{
	person* persons[4];

	for(int i=0; i<4; i++)
	{
		persons[i] = new person("noname",0);
	}

	persons[0] -> setName("Jack");
	persons[1] -> setName("Kai");
	persons[2] -> setName("Henry");
	persons[3] -> setName("Mike");

	persons[0] -> setSalary(1000);
	persons[1] -> setSalary(2000);
	persons[2] -> setSalary(3000);
	persons[3] -> setSalary(4000000);

	for(int i=0; i<4; i++)
	{
		cout << persons[i] -> getName() << endl;
	}

	for(int i=0; i<4; i++)
	{
		cout << persons[i] -> getSalary() << endl;
	}

	for(int i=0; i<4; i++)
	{
		delete persons[i];
	}
}