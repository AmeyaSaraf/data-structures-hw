#include "Player.h"
using namespace std;

// Betting Function
int askForBet(int currentMoney) {
    int bet;
    do {
        std::cout << "Enter your bet amount (6 to 20): ";
        std::cin >> bet;
    } while (bet < 6 || bet > 20 || bet > currentMoney);

    return bet;
}

// Function for double, halve, or keep
char getPlayerChoice() {
    char choice;
    do {
        std::cout << "Would you like to Double (Enter D), Halve (Enter H), or Keep your wager (Enter K)? ";
        std::cin >> choice;
        choice = tolower(choice);
    } while (choice != 'd' && choice != 'h' && choice != 'k');

    return choice;
}

void playRound(Player& player, Player& house) {
    int bet = askForBet(player.getM());

    // Player and house spin the wheel
    int house_wheel = house.sW();
    int player_wheel = player.sW();

    cout << "Your wheel landed on: " << player_wheel << endl;

    char choice = getPlayerChoice();
    int outcome = 0;

    if (choice == 'D') {
        bet *= 2; 
        if (player_wheel > house_wheel) {
            cout << "The house wheel landed on: " << house_wheel << endl;
            cout << "You win double!" << endl;
            outcome = bet;
        }
        else {
            cout << "The house wheel landed on: " << house_wheel << endl;
            cout << "House wins!" << endl;
            outcome = -bet;
        }
    }
    else if (choice == 'H') {
        cout << "The house wheel landed on: " << house_wheel << endl;
        bet /= 2;
        if (player_wheel > house_wheel) {
            cout << "You win half!" << endl;
            outcome = bet;
        }
        else {
            cout << "House wins!" << endl;
            outcome = -bet;
        }
    }
    else if (choice == 'K') {
        cout << "The house wheel landed on: " << house_wheel << endl;
        if (player_wheel > house_wheel) {
            cout << "You win!" << endl;
            outcome = bet;
        }
        else {
            cout << "House wins!" << endl;
            outcome = -bet;
        }
    }

    player.setM(outcome);
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator

    int initialMoney;
    cout << "Welcome to Roulette Wheel Game! How much money do you want to start with? ";
    cin >> initialMoney;

    Player player(initialMoney);
    Player house(10000); // House starts with a large amount of money

    while (player.getM() > 0) {
        playRound(player, house);
        cout << "You have " << player.getM() << " left." << endl;

        char continueGame;
        cout << "Do you want to continue playing? (y/n): ";
        cin >> continueGame;
        if (tolower(continueGame) != 'y') break;
    }

    cout << "Game over! You ended with " << player.getM() << "." << endl;
    return 0;
}
