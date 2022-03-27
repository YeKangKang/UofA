#include "FilterForTwoDigitPositive.h"

using namespace std;

FilterForTwoDigitPositive::FilterForTwoDigitPositive() {}

FilterForTwoDigitPositive::~FilterForTwoDigitPositive() {}

bool FilterForTwoDigitPositive::g(int input) {
    if (input>0 && input>=10 && input<100) {
        return true;
    }
    return false;
}