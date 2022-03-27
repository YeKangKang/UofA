#include "ReduceGCD.h"
using namespace std;

ReduceGCD::ReduceGCD() {}
ReduceGCD::~ReduceGCD() {}

int ReduceGCD::binaryOperator(int a, int b) {
    if (b == 0) {
        return a;
    }
    return binaryOperator(b, a%b);
}