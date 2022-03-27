#ifndef TOURNAMENT_H
#define TOURNAMENT_H
#include "Referee.h"
#include <array>

class Tournament {
public:
    Tournament();
    ~Tournament();
    Player * run(std::array<Player *, 8> competitors);
protected:
    Referee R;
    std::array<Player*, 4> Top4;
    std::array<Player*, 2> Top2;
    int p1;
    int p2;
};
#endif