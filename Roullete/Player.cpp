#include "Player.h"

// Constructor to initialize player's money
Player::Player(int m) : $m(m), w() {}

// Setter for player's money
void Player::setM(int a) {
    $m = a;
}

// Getter for player's money
int Player::getM() const {
    return $m;
}

// Method to spin the wheel and get a value
int Player::sW() {
    w.spin();
    return w.getBall();
}

// Method to update player's money
void Player::uM(int a) {
    $m += a;
}
