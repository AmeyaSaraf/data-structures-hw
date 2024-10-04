#include "HardMode.h"

// Constructor definition
HardWheel::HardWheel(int min, int max) : Wheel(), consecWins(0), consecLosses(0) {}

// Method to spin the wheel with player's result
int HardWheel::spin(int playerResult, char mode, int otherWheel, int spunYet) {

    int result = 0;

    if (consecWins == 4) { //Set to 4 because there are two wheels per round
        decreaseRange();
        consecWins = 0;
    }

    if (consecLosses == 3) {
        increaseRange();
        consecLosses = 0;
    }

    if (spunYet != -1) {
        result = spunYet;
    }
    else {
        Wheel::spin();
        result = Wheel::getBall();
    }
;
            
    if (mode == 'D') {
        if (result > playerResult && otherWheel > playerResult) {
            consecLosses = 0;
            consecWins++;
            return result;
        }
        else if (result > playerResult || otherWheel > playerResult) {
            consecLosses = 0;
            consecWins++;
            return result;
        }
        else if (result < playerResult && otherWheel < playerResult) {
            consecWins = 0;
            consecLosses++;
            return result;
        }
    }


    else if (mode == 'H') {
        if (result > playerResult && otherWheel > playerResult) {
            consecLosses = 0;
            consecWins++;
            return result;
        }
        else if (result < playerResult || otherWheel < playerResult) {
            consecWins = 0;
            consecLosses++;
            return result;
        }
    }

    else if (mode == 'K') {
        if (result > playerResult) {
            consecLosses = 0;
            consecWins++;
            consecWins++;
            return result;
        }
        else if (result < playerResult) {
            consecWins = 0;
            consecLosses++;
            return result;
        }
    }


    return result;
}

// Method to increase range
void HardWheel::increaseRange() {
    setRange(1, getMaxValue() * 2);
    std::cout << "Player wins! Range INCREASED to " << getMaxValue() << std::endl;
}

// Method to decrease range
void HardWheel::decreaseRange() {
    if (getMaxValue() < 10) {
        std::cout << "Minimum range already reached!" << std::endl;
    }
    else {
        setRange(1, getMaxValue() / 2);
        std::cout << "2 consecutive house wins! Range DECREASED to " << getMaxValue() << std::endl;
    }
}