#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H
#include <string>

class Individual {
public:
    std::string binaryString;
    Individual(int length);
    Individual(std::string str);
    ~Individual();
    std::string getString();
    int getBit(int pos);
    void flipBit(int pos);
    int getMaxOnes();
    int getLength();
};
#endif