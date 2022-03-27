#ifndef FISTFULLODOLLARS_H
#define FISTFULLODOLLARS_H
#include "Computer.h"
#include <array>

class FistfullODollars : public ComputerPlayer {
protected:
    std::array<int,3> arr;
    int index;
    int five_count;
public:
    FistfullODollars();
    ~FistfullODollars();
    char makeMove();
};

#endif