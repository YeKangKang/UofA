#include "Human.h"
#include <iostream>

HumanPlayer::HumanPlayer() {
    move = 'E';
}

HumanPlayer::~HumanPlayer() {

}

char HumanPlayer::makeMove() {
    std::cout << "Enter move: ";
    std::cin >> move;
    return move;
}

char HumanPlayer::getMove() {
    return move;
}