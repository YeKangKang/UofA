#ifndef PAPERDOOL_H
#define PAPERDOOL_H
#include "Computer.h"
#include <array>

class PaperDoll : public ComputerPlayer {
protected:
    std::array<int,3> arr;
    int index;
    int five_count;
public:
    PaperDoll();
    ~PaperDoll();
    char makeMove();
};

#endif