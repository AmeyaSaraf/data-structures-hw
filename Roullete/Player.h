#pragma once
#ifndef PLAYER_H
#define PLAYER_H

#include "Wheel.h"

class P {
public:
    P(int m); // Constructor to initialize player's money
    void setM(int a); // Setter for player's money
    int getM() const; // Getter for player's money
    int sW(); // Method to spin the wheel and get a value
    void uM(int a); // Method to update player's money

private:
    int $m; // Player's money
    Wheel w; // Instance of the Wheel class
};

#endif
