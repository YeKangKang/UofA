#ifndef HUMAN_H
#define HUMAN_H
#include <iostream>

class HumanPlayer {
private:
    char move;
public:
    HumanPlayer();
    ~HumanPlayer();
    char makeMove();
    char getMove();
};

#endif