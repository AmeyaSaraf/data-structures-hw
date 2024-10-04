#include "HardMode.h"

// Constructor definition
HardWheel::HardWheel(int min, int max) : Wheel(), consecWins(0) {}

// Method to spin the wheel with player's result
int HardWheel::spin(int playerResult, char mode) {
    Wheel::spin();
    int result = Wheel::getBall();
    //Need to update this logic so that the houes only decreases when it wins two doubles
    if (mode == 'D') {
        if (result > playerResult) {
            consecWins++;
            if (consecWins == 4) {
                decreaseRange();
                consecWins = 0;
            }
        }
    }

    else if (mode == 'H') {
        if (result > playerResult) {
            consecWins++;
            if (consecWins == 4) {
                decreaseRange();
                consecWins = 0;
            }
        }

    }

    else if (mode == 'K') {
        if (result > playerResult) {
            consecWins++;
            if (consecWins == 2) {
                decreaseRange();
                consecWins = 0;
            }
        }


    }

    else {
        consecWins = 0;
        increaseRange();
    }
    return result;
}

// Method to increase range
void HardWheel::increaseRange() {
    setRange(1, getMaxValue() * 2);
}

// Method to decrease range
// Need to change this so that it can't go below players max value
void HardWheel::decreaseRange() {
    setRange(1, getMaxValue() / 2);
}