#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include "Person.h"
using namespace std;

class Player : public Person{
private:
	static int nextID;
public:
	int* playerlist;
	int listnumber;
	Player(string n, int sl, int *list, int m);
/* creates a person with name n, whose occupation is
   “player” and service length is sl;
   list records the time that a player spent in the
   field in each game, the integers are distinct and 
   sorted in ascending order; m is the number of games
*/

	int searchGame(int x);             
/* searches for a particular time x in the array of times;
   returns either the index of x in the array if x exists or -1 otherwise;
   you may use your favourite sorting algorithm*/

   int get_salary();
   
   ~Player();
};
#endif