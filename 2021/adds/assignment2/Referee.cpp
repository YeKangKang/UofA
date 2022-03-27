#include "Referee.h"
#include <iostream>
using namespace std;

Referee::Referee() {

}

Referee::~Referee() {

}

char Referee::refGame(HumanPlayer player1, ComputerPlayer player2) {
    player1.makeMove();
    if (player1.getMove() == 'R') {
        return 'T';
    } else if (player1.getMove() == 'P'){
        return 'W';
    } else {
        return 'L';
    }
}