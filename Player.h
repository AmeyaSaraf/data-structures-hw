#pragma once
#include "HardMode.h"
#include "Wheel.h"

class Player {
public:
    Player(int m, bool hardMode); // Constructor to initialize player's money
    void setM(int a); // Setter for player's money
    int getM() const; // Getter for player's money
    int sW(int playerResult); // Method to spin the wheel and get a value
    void uM(int a); // Method to update player's money

private:
    int money; // Player's money 
    bool hardMode; // Hard mode bonus
    Wheel w; // Instance of the Wheel class
    HardWheel hw;
};
