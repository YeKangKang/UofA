#ifndef TRANSPORT_H
#define TRANSPORT_H
#include <iostream>

class Transport {
protected:
    int dist;
public:
    Transport();
    ~Transport();
    int get_dist_travelled();
    virtual void go() = 0;
};

#endif