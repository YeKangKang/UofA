#ifndef HUMAN_H
#define HUMAN_H
#include <iostream>
#include "Computer.h"

class HumanPlayer : public ComputerPlayer {
protected:
    char move;
public:
    HumanPlayer();
    ~HumanPlayer();
    char makeMove();
    char getMove();
};

#endif