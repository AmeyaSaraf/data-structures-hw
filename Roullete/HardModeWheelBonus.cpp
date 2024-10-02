#include "HardModeWheel.h"

// Constructor definition
H::H(int min, int max) : Wheel(min, max), cw(0) {}

// Method to spin the wheel with player's result
int H::s(int pr) {
    int r = Wheel::spin();
    if (r > pr) {
        cw++;
        if (cw == 2) {
            dR();
            cw = 0;
        }
    }
    else {
        cw = 0;
        iR();
    }
    return r;
}

// Method to increase range
void H::iR() {
    setRange(1, getMaxValue() * 2);
}

// Method to decrease range
void H::dR() {
    setRange(1, getMaxValue() / 2);
}

