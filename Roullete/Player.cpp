#include "Player.h"

// Constructor to initialize player's money
P::P(int m) : $m(m), w() {}

// Setter for player's money
void P::setM(int a) {
    $m = a;
}

// Getter for player's money
int P::getM() const {
    return $m;
}

// Method to spin the wheel and get a value
int P::sW() {
    w.spin();
    return w.getBall();
}

// Method to update player's money
void P::uM(int a) {
    $m += a;
}
