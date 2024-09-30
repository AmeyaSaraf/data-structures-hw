#include <iostream>
#pragma once

class Wheel {
    public:
        int bottomRange = 1; //Bottom range of values to spin from
        int topRange = 10; //Top range of values to spin from
        void setBottomRange(int n); //Setter for bottom range
        void setTopRange(int n); //Setter for top range
        void spin(); //Picks a random value in between the bottom and top range and assigns it to ball
        void setBall(int n); //Setter for the value of the ball - we may not need this function 
        int getBall(); //Getter for the value of the ball - we may not need this function
    private:
        int ball = 0; //Ball, intially defined to 0 but changes with spins
};
