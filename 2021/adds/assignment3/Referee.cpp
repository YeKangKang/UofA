#include "Referee.h"
#include <iostream>
using namespace std;

Referee::Referee() {

}

Referee::~Referee() {

}

char Referee::refGame(Player* player1, Player* player2) {
    char P1 = player1->makeMove();
	char P2 = player2->makeMove();
	if (P1 == 'R' && P2 == 'R') {
		return 'T';
	}
	else if (P1 == 'R' && P2 == 'P') {
		return 'L';
	}
	else if (P1 == 'R' && P2 == 'S') {
		return 'W';
	}
	else if (P1 == 'P' && P2 == 'R') {
		return 'W';
	}
	else if (P1 == 'P' && P2 == 'P') {
		return 'T';
	}
	else if (P1 == 'P' && P2 == 'S') {
		return 'L';
	}
	else if (P1 == 'S' && P2 == 'R') {
		return 'L';
	}
	else if (P1 == 'S' && P2 == 'P') {
		return 'W';
	}
	else if (P1 == 'S' && P2 == 'S') {
		return 'T';
	}
	return 'E';
}