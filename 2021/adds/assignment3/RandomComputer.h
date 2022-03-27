#ifndef RANDOMCOMPUTER_H
#define RANDOMCOMPUTER_H
#include "Computer.h"
#include <array>

class RandomComputer : public ComputerPlayer {
public:
    RandomComputer();
    ~RandomComputer();
    char makeMove();
};

#endif