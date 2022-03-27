#ifndef REFEREE_H
#define REFEREE_H
#include <iostream>
#include "Player.h"
#include "Computer.h"
#include "Crescendo.h"
#include "FistfullODollars.h"
#include "RandomComputer.h"
#include "PaperDoll.h"
#include "Avalanche.h"
#include "Bureaucrat.h"
#include "Toolbox.h"

class Referee {
public:
    Referee( );
    ~Referee();
    char refGame(Player* player1, Player* player2);
};

#endif