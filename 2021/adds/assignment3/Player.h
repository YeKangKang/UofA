#ifndef PLAYER_H
#define PLAYER_H

class Player {
protected:
	char move;
public:
	Player();
	~Player();
	virtual char makeMove();
};

#endif