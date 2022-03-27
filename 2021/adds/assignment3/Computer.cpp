#include "Computer.h"

ComputerPlayer::ComputerPlayer() {
    move = 'R';
}

ComputerPlayer::~ComputerPlayer(){

}

char ComputerPlayer::makeMove(){
    return move;
}