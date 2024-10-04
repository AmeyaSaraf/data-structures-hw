#include "Player.h"

// Constructor to initialize player's money
Player::Player(int m, bool f) : money(m), hardMode(f), w(), hw() {}

// Setter for player's money
void Player::setM(int a) {
    money = a;
}

// Getter for player's money
int Player::getM() const {
    return money;
}

// Method to spin the wheel and get a value
int Player::sW(int playerResult, char mode, int otherWheel, int spunYet) {
    if (hardMode) {
        return hw.spin(playerResult, mode, otherWheel, spunYet);
    }
    else {
        w.spin();
        return w.getBall();
    }
}

// Method to update player's money
void Player::uM(int a) {
    money += a;
}