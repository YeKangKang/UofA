#include "Crescendo.h"
#include "FistfullODollars.h"
#include "Computer.h"
#include "RandomComputer.h"
#include "PaperDoll.h"
#include "Avalanche.h"
#include "Bureaucrat.h"
#include "Toolbox.h"
#include <iostream>
using namespace std;

int main() {
    FistfullODollars* F = new FistfullODollars();
    Crescendo C;
    RandomComputer R;
    PaperDoll P;
    Avalanche A;
    Bureaucrat B;
    Toolbox T;

    for (int a=0; a<20; a++) {
        cout << C.makeMove();
    }
    cout << endl;

    for (int a=0; a<18; a++) {
        cout << P.makeMove();
    }
    cout << endl;
    
    for (int a=0; a<19; a++) {
        cout << F->makeMove();
    }
    cout << endl;

    for (int a=0; a<13; a++) {
        cout << R.makeMove();
    }
    cout << endl;

    for (int a=0; a<13; a++) {
        cout << A.makeMove();
    }
    cout << endl;

    for (int a=0; a<13; a++) {
        cout << B.makeMove();
    }
    cout << endl;

    for (int a=0; a<13; a++) {
        cout << T.makeMove();
    }
    cout << endl;
}