#ifndef CART_H
#define CART_H
#include <iostream>
#include "meerkat.h"

using namespace std;

class cart : public meerkat
{
public:
	cart();
	int count;
	meerkat basket[4];
	bool addMeerkat(meerkat cat);
	void emptyCart();
	void printMeerkats();
	~cart();
};

#endif