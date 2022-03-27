#include <iostream>
#include "meerkat.h"

using namespace std;

meerkat::meerkat()
{
	name = "?";
	age = 0;
}

meerkat::meerkat(string a, int b)
{
	name = a;
	age = b;
}

void meerkat::setName(string meerName)
{
	name = meerName;
}

void meerkat::setAge(int meerAge)
{
	age = meerAge;
}

string meerkat::getName()
{
	return name;
}

int meerkat::getAge()
{
	return age;
}

meerkat::~meerkat()
{

}