#ifndef REDUCEMINIMUM_H
#define REDUCEMINIMUM_H
#include "ReduceGeneric.h"

class ReduceMinimum : public ReduceGeneric {
private:
    int binaryOperator(int a, int b);
public:
    ReduceMinimum();
    ~ReduceMinimum();
};
#endif