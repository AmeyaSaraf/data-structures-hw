#include <iostream>
#pragma once

class Wheel {
    public:
        int bottomRange = 1;
        int topRange = 10;
        void setBottomRange(int n);
        void setTopRange(int n);
        void spin();
        void setBall(int n);
        int getBall();
    private:
        int ball = 0;
};
