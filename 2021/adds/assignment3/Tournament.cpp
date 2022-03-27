#include "Tournament.h"
#include <iostream>
using namespace std;

Tournament::Tournament() {
    p1 = 0;
    p2 = 0;
}

Tournament::~Tournament() {

}

Player * Tournament::run(std::array<Player *, 8> competitors) {
    // 小组赛 4 Team 5 times
    int index = 0;                      // 用来给Top4定位
    for (int i=0; i<4; i++){
        for(int o=0; o<5; o++){
            char result = 'E';
            result = R.refGame(competitors[i*2], competitors[i*2+1]);
            if (result == 'W') {
                p1++;
            } else if (result == 'L'){
                p2++;
            }
        }
        if (p1 > p2 || p1 == p2) {
            Top4[index] = competitors[i*2];
            index++;
        } else {
            Top4[index] = competitors[i*2+1];
            index++;
        }
    }

    // Top4
    p1 = 0;
    p2 = 0;
    index = 0;
    for (int i=0; i<2; i++){
        for(int o=0; o<5; o++){
            char result = 'E';
            result = R.refGame(Top4[i*2], Top4[i*2+1]);
            if (result == 'W') {
                p1++;
            } else if (result == 'L'){
                p2++;
            }
        }
        if (p1 > p2 || p1 == p2) {
            Top2[index] = Top4[i*2];
            index++;
        } else {
            Top2[index] = Top4[i*2+1];
            index++;
        }
    }

    // Top2
    p1 = 0;
    p2 = 0;
    for (int i=0; i<5; i++){
        char result = 'E';
        result = R.refGame(Top2[0], Top2[1]);
        if (result == 'W') {
            p1++;
        } else if (result == 'L'){
            p2++;
        }
    }
    if (p1 > p2 || p1 == p2) {
        return Top2[0];
    }else {
        return Top2[1];
    }
}