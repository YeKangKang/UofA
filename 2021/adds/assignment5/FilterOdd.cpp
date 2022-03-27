#include "FilterOdd.h"

using namespace std;

FilterOdd::FilterOdd() {}

FilterOdd::~FilterOdd() {}

bool FilterOdd::g(int input) {
    if (input%2!=0) {
        return true;
    }
    return false;
}