#include "Player.h"
using namespace std;

// Betting Function
int getBetAmount() {
    int bet;
    do {
        std::cout << "Enter your bet amount (minimum 6, maximum 20): ";
        std::cin >> bet;
        if (bet < 6 || bet > 20) {
            std::cout << "Invalid bet amount! Please enter a value between 6 and 20.\n";
        }
    } while (bet < 6 || bet > 20);
    return bet;
}

// Function for double, halve, or keep
char getPlayerChoice() {
    char choice;
    do {
        std::cout << "Would you like to Double (Enter D), Halve (Enter H), or Keep your wager (Enter K)? ";
        std::cin >> choice;
    } while (choice != 'D' && choice != 'H' && choice != 'K');  // Accept uppercase only

    return choice;
}

void playRound(Player& player, Player& house) {
    int bet = getBetAmount();

    // Player and house spin the wheel
    int house_wheel = house.sW();
    int player_wheel = player.sW();

    cout << "Your wheel landed on: " << player_wheel << endl;

    char choice = getPlayerChoice();
    int outcome = 0;

    if (choice == 'D') {  // Double the bet
        bet *= 2;

        // Player and house get two spins
        int player_wheel_2 = player.sW();
        int house_wheel_2 = house.sW();

        cout << "First spin results:\n";
        cout << "Player: " << player_wheel << ", House: " << house_wheel << endl;
        cout << "Second spin results:\n";
        cout << "Player: " << player_wheel_2 << ", House: " << house_wheel_2 << endl;

        // Player must win both spins, house wins if it wins either spin
        if ((player_wheel > house_wheel && player_wheel_2 > house_wheel_2)) {
            cout << "You win double!" << endl;
            outcome = bet;
        }
        else {
            cout << "House wins!" << endl;
            outcome = -bet;
        }
    }
    else if (choice == 'H') {  // Halve the bet
        bet /= 2;

        // House gets two spins
        int house_wheel_2 = house.sW();

        cout << "First spin results: House: " << house_wheel << endl;
        cout << "Second spin results: House: " << house_wheel_2 << endl;

        // House must win both spins to win
        if (house_wheel > player_wheel && house_wheel_2 > player_wheel) {
            cout << "House wins!" << endl;
            outcome = -bet;
        }
        else {
            cout << "You win half your wager!" << endl;
            outcome = bet;
        }
    }
    else if (choice == 'K') {  // Keep the bet the same
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

    player.setM(outcome);  // Update the player's money
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
        if (continueGame != 'Y' && continueGame != 'y') break;
    }

    cout << "Game over! You ended with " << player.getM() << "." << endl;
    return 0;
}
