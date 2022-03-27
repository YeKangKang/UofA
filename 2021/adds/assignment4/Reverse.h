#ifndef REVERSE_H
#define REVERSE_H
#include <string>

class Reverse {
public:
    Reverse();
    ~Reverse();
    int reverseDigit(int value);
    std::string reverseString(std::string letters);
};

#endif