#include "Human.h"
#include "Computer.h"
#include "Referee.h"
#include <iostream>
using namespace std;

int main() {
    HumanPlayer H;
    ComputerPlayer C;
    Referee R;

    R.refGame(H,C);
    return 0;
}