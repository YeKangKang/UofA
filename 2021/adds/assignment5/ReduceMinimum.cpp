#include "ReduceMinimum.h"
using namespace std;

ReduceMinimum::ReduceMinimum() {}

ReduceMinimum::~ReduceMinimum() {}

int ReduceMinimum::binaryOperator(int a, int b) {
    if (a<b){
        return a;
    }else {
        return b;
    }
}