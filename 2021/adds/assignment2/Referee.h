#ifndef REFEREE_H
#define REFEREE_H
#include "Human.h"
#include "Computer.h"

class Referee {
public:
    Referee( );
    ~Referee();
    char refGame(HumanPlayer player1, ComputerPlayer player2);
};

#endif