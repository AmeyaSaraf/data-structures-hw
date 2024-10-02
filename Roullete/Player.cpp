#include "Player.h"

// Constructor to initialize player's money
Player::Player(int m) : money(m), w() {}

// Setter for player's money
void Player::setM(int a) {
    money = a;
}

// Getter for player's money
int Player::getM() const {
    return money;
}

// Method to spin the wheel and get a value
int Player::sW() {
    w.spin();
    return w.getBall();
}

// Method to update player's money
void Player::uM(int a) {
    money += a;
}
