#ifndef REDUCEGENERIC_H
#define REDUCEGENERIC_H
#include <vector>

class ReduceGeneric {
private:
    virtual int binaryOperator(int a, int b) = 0;
public:
    ReduceGeneric();
    ~ReduceGeneric();
    int reduce(std::vector<int> arr);
};
#endif