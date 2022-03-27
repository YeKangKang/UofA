#include "FilterNonPositive.h"

using namespace std;

FilterNonPositive::FilterNonPositive() {}

FilterNonPositive::~FilterNonPositive() {}

bool FilterNonPositive::g(int input) {
    if (input <= 0) {
        return true;
    }
    return false;
}