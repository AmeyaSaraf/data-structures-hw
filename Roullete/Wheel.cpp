#include "Wheel.h"
#include <random>

void Wheel::setBottomRange(int n) {
    bottomRange = n;
}

void Wheel::setTopRange(int n) {
    topRange = n;
}

void Wheel::setBall(int n) {
    ball = n;
}

int Wheel::getBall() {
    return ball;
}

void Wheel::spin() {
    // Create a random number generator
    std::random_device rd;  // Seed for the random number engine
    std::mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()

    // Define the distribution range between bottomRange and topRange
    std::uniform_int_distribution<> distr(bottomRange, topRange);

    // Generate and assign a random number to ball
    ball = distr(gen);
}