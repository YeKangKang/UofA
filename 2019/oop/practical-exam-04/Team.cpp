#include <iostream>
#include "Person.h"
#include "Coach.h"
#include "Player.h"
#include "Team.h"
using namespace std;

Team::Team(){
	*list = 5;
	team[0] = new Coach("No", 3);
	team[4] = new Coach("No", 3);
	for (int i=1; i<4; i++){
		team[i] = new Player("player", 0, list, 1);
	}
}

Person ** Team::get_team(){
	return team;
}

Team::~Team(){
	for (int i=0; i<5; i++){
		delete team[i];
	}
}