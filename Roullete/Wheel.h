#pragma once
#include <iostream>

class Wheel {
public:
    int bottomRange = 1; // Bottom range of values to spin from
    int topRange = 10;   // Top range of values to spin from
    void setBottomRange(int n);  // Setter for bottom range
    void setTopRange(int n);     // Setter for top range
    void setRange(int min, int max);  // Setter for both bottom and top range

    int getMaxValue() const;     // Getter for the top range value
    void spin();                 // Picks a random value between the bottom and top range and assigns it to ball
    void setBall(int n);         // Setter for the value of the ball (may not be necessary)
    int getBall();               // Getter for the value of the ball (may not be necessary)

private:
    int ball = 0; // Ball, initially defined as 0, but changes with spins
};
