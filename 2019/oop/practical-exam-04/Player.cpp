#include "Person.h"
#include "Player.h"
#include <iostream>
using namespace std;

int Player::nextID = 1000;

Player::Player(string n, int sl, int *list, int m){
	personID = nextID;
	name = n;
	occupation = "player";
	serviceLength = sl;
	salary = 0;
	playerlist = list;
	listnumber = m;
	nextID++;
}

int Player::get_salary(){
	if (serviceLength<20){
		return salary;
	}else{
		return 3*salary;
	}
}

int Player::searchGame(int x){
	int index = 0;
	for (int i=0; i<listnumber; i++){
		if (playerlist[i] == x){
			return index;
		}
		index++;
	}
	return -1;
}

Player::~Player(){

}