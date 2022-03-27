#include "cart.h"
using namespace std;

cart::cart()
{
	count = 0;
}

bool cart::addMeerkat(meerkat cat)
{
	if(count>=4){
		//cout << "its FULL!!!" << endl;
		return false;
	}else{
		//cout << "add cussess!" << endl;
		basket[count] = cat;
		count++;
	}
	return true;
}

void cart::emptyCart()
{
	count = 0;
	for(int i=0; i<4; i++){
		basket[i] = meerkat();
	}
}

void cart::printMeerkats()
{
	for(int i=0; i<4; i++){
		cout << basket[i].getName() << " " << basket[i].getAge() << endl;
	}
}

cart::~cart()
{

}