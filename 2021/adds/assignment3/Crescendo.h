#ifndef CRESCENDO_H
#define CRESCENDO_H
#include "Computer.h"
#include <array>

class Crescendo : public ComputerPlayer {
protected:
    std::array<int,3> arr;
    int index;
    int five_count;
public:
    Crescendo();
    ~Crescendo();
    char makeMove();
};

#endif