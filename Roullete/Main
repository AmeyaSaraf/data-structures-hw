#include "Player.h"
#include <iostream>
using namespace std;

// Betting Function
int askForBet(int currentMoney) {
    int bet;
    do {
        cout << "Enter your bet amount (6 to 20): ";
        cin >> bet;
    } while (bet < 6 || bet > 20 || bet > currentMoney);

    return bet;
}

// Function for double, halve, or keep
char getPlayerChoice() {
    char choice;
    do {
        cout << "Would you like to Double (Enter D), Halve (Enter H), or Keep your wager (Enter K)? ";
        cin >> choice;
        choice = tolower(choice);
    } while (choice != 'd' && choice != 'h' && choice != 'k');

    return choice;
}

void playRound(Player &player, Player &house) {
    int bet = askForBet(player.getMoney());

    // Player and house spin the wheel
    player.spinWheel();
    house.spinWheel();

    cout << "Your wheel landed on: " << player.getWheelValue() << endl;
    cout << "The house wheel landed on: " << house.getWheelValue() << endl;

    char choice = getPlayerChoice();
    int outcome = 0;

    if (choice == 'd') {
        bet *= 2; /
        house.spinWheel(); 
        if (player.getWheelValue() > house.getWheelValue()) {
            cout << "You win double!" << endl;
            outcome = bet;
        } else {
            cout << "House wins!" << endl;
            outcome = -bet;
        }
    } else if (choice == 'h') {
        bet /= 2; 
        house.spinWheel(); 
        if (player.getWheelValue() > house.getWheelValue()) {
            cout << "You win half!" << endl;
            outcome = bet;
        } else {
            cout << "House wins!" << endl;
            outcome = -bet;
        }
    } else {
        if (player.getWheelValue() > house.getWheelValue()) {
            cout << "You win!" << endl;
            outcome = bet;
        } else {
            cout << "House wins!" << endl;
            outcome = -bet;
        }
    }

    player.changeMoney(outcome);
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator

    int initialMoney;
    cout << "Welcome to Roulette Wheel Game! How much money do you want to start with? ";
    cin >> initialMoney;

    Player player(initialMoney);
    Player house(10000); // House starts with a large amount of money

    while (player.getMoney() > 0) {
        playRound(player, house);
        cout << "You have " << player.getMoney() << " left." << endl;

        char continueGame;
        cout << "Do you want to continue playing? (y/n): ";
        cin >> continueGame;
        if (tolower(continueGame) != 'y') break;
    }

    cout << "Game over! You ended with " << player.getMoney() << "." << endl;
    return 0;
}
