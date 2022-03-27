#include "Horse.h"
#include "Transport.h"
#include <iostream>
using namespace std;

int main() {

    Transport* H = new Horse();

    cout << "Horse Object Here" << endl;
    cout << "the dist is now: " << H->get_dist_travelled() << endl;
    
    cout << "########################" << endl;
    cout << "call go(), now dist=100" << endl;
    H->go();
    cout << "the dist is now: " << H->get_dist_travelled() << endl;
    
    cout << "########################" << endl;
    cout << "call go(), now dist=200" << endl;
    H->go();
    cout << "the dist is now: " << H->get_dist_travelled() << endl;
    
}