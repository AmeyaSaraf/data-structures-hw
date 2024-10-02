#ifndef HARDMODEWHEEL_H
#define HARDMODEWHEEL_H

#include "Wheel.h"

class H : public Wheel {
public:
    H(int min = 1, int max = 10); // Constructor declaration
    int s(int pr); // Method to spin the wheel with player's result

private:
    int cw; // Counter for consecutive wins

    void iR(); // Method to increase range
    void dR(); // Method to decrease range
};

#endif
