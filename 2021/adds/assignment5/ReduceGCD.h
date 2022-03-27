#ifndef REDUCEGCD_H
#define REDUCEGCD_H
#include "ReduceGeneric.h"

class ReduceGCD : public ReduceGeneric {
private:
    int binaryOperator(int a, int b);
public:
    ReduceGCD();
    ~ReduceGCD();
};
#endif