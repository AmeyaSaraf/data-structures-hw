#pragma once

#include "Wheel.h"

class HardWheel : public Wheel {
public:
    HardWheel(int min = 1, int max = 10); // Constructor declaration
    int spin(int pr); // Method to spin the wheel with player's result

private:
    int consecWins; // Counter for consecutive wins

    void increaseRange(); // Method to increase range
    void decreaseRange(); // Method to decrease range
};
