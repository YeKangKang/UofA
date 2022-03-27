#ifndef MEERKAT_H
#define MEERKAT_H
#include <iostream>

using namespace std;

class meerkat
{
public:
	meerkat();
	meerkat(string a, int b);
	string name;
	int age;
	void setName(string meerName);
	string getName();
	void setAge(int meerAge);
	int getAge();
	~meerkat();
};
#endif