#ifndef FILTERGENERIC_H
#define FILTERGENERIC_H
#include <vector>

class FilterGeneric {
private:
    virtual bool g(int input) = 0;
public:
    FilterGeneric();
    ~FilterGeneric();
    std::vector<int> filter(std::vector<int> arr);
};

#endif