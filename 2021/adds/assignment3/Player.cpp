#include "Player.h"
#include <iostream>

Player::Player() {
	move = 'R';
}

Player::~Player() {

}

char Player::makeMove() {
	return move;
}