#ifndef COMPUTER_H
#define COMPUTER_H

class ComputerPlayer {
private:
    char move;
public:
    ComputerPlayer();
    ~ComputerPlayer();
    char makeMove();
};

#endif