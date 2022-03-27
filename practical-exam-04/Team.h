#ifndef TEAM_H
#define TEAM_H
#include <iostream>
#include "Person.h"
#include "Coach.h"
#include "Player.h"
using namespace std;

class Team{
protected:
	int* list;
	Person** team;
public:
	Team();                          
/* creates a team object containing 5 team members as an array; 
   the first and the last elements of the array are coaches, 
   the rest of the elements are players
*/

	Person **get_team();      // returns the array of the four team members
	~Team();
};
#endif