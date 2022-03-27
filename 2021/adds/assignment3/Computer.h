#ifndef COMPUTER_H
#define COMPUTER_H
#include "Player.h"

class ComputerPlayer : public Player {
public:
    ComputerPlayer();
    ~ComputerPlayer();
    virtual char makeMove();
};

#endif