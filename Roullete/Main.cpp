#include "Player.h"
using namespace std;

// Betting Function
int getBetAmount(Player& player) {
    int bet;
    do {
        std::cout << "Enter your bet amount (minimum 6, maximum 20): ";
        std::cin >> bet;
        if (bet < 6 || bet > 20) {
            std::cout << "Invalid bet amount! Please enter a value between 6 and 20.\n";
        }
        if (bet > player.getM()) {
            std::cout << "You don't have enough money to bet that much! Try again. \n";
        }
    } while (bet < 6 || bet > 20 || bet > player.getM());
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
    int bet = getBetAmount(player);

    // Player spins the wheel
    int player_wheel = player.sW(0, 'a',0, -1);

    cout << "Your wheel landed on: " << player_wheel << endl;

    char choice = getPlayerChoice();
    int outcome = 0;

    if (choice == 'D') {  // Double the bet
        bet *= 2;

        // House get two spins, must win one to win
        int tempWheel = house.sW(player_wheel, choice, 0, -1);
        int house_wheel = house.sW(player_wheel, choice, tempWheel, -1);
        int house_wheel_2 = house.sW(player_wheel, choice, house_wheel, tempWheel); //recreates house_wheel with the same number as tempWheel

        cout << "First spin results:\n";
        cout << "House: " << house_wheel << endl;
        cout << "Second spin results:\n";
        cout << "House: " << house_wheel_2 << endl;

        // Player must win both spins, house wins if it wins either spin
        if ((player_wheel > house_wheel && player_wheel > house_wheel_2)) {
            cout << "You win double!" << endl;
            outcome = player.getM() + bet;
        }
        else {
            cout << "House wins!" << endl;
            outcome = player.getM() - bet;
        }
    }
    else if (choice == 'H') {  // Halve the bet
        bet /= 2;

        // House get two spins, must win one to win
        int tempWheel = house.sW(player_wheel, choice, 0, -1);
        int house_wheel = house.sW(player_wheel, choice, tempWheel, -1);
        int house_wheel_2 = house.sW(player_wheel, choice, house_wheel, tempWheel); //recreates house_wheel with the same number as tempWheel

        cout << "First spin results:\n";
        cout << "House: " << house_wheel << endl;
        cout << "Second spin results:\n";
        cout << "House: " << house_wheel_2 << endl;

        // House must win both spins to win
        if (house_wheel > player_wheel && house_wheel_2 > player_wheel) {
            cout << "House wins!" << endl;
            outcome = player.getM() - bet;
        }
        else {
            cout << "You win half your wager!" << endl;
            outcome = player.getM() + bet;
        }
    }
    else if (choice == 'K') {  // Keep the bet the same
        //house has one chance to win

        int house_wheel = house.sW(player_wheel, choice, 0, -1);
        cout << "The house wheel landed on: " << house_wheel << endl;
        if (player_wheel > house_wheel) {
            cout << "You win!" << endl;
            outcome = player.getM() + bet;
        }
        else {
            cout << "House wins!" << endl;
            outcome = player.getM() - bet;
        }
    }

    player.setM(outcome);  // Update the player's money
}

int main() {
    int initialMoney;
    cout << "Welcome to Roulette Wheel Game! How much money do you want to start with? ";
    cin >> initialMoney;

    char hardModeChoice;
    do {
        cout << "Would you like to play in hard mode ? (y / n): ";
        cin >> hardModeChoice;
    } while (hardModeChoice != 'y' && hardModeChoice != 'Y' && hardModeChoice != 'n' && hardModeChoice != 'N');  


    bool hardMode = (hardModeChoice == 'y' || hardModeChoice == 'Y');

    Player player(initialMoney, false);
    Player house(10000, hardMode); // House starts with a large amount of money

    while (player.getM() > 0) {
        playRound(player, house);

        if (player.getM() < 0) {
            cout << "You're all out of money!" << endl;
        }
        else {
            cout << "You have " << player.getM() << " left." << endl;
        }

        char continueGame;
        cout << "Do you want to continue playing? (y/n): ";
        cin >> continueGame;
        if (continueGame != 'Y' && continueGame != 'y') break;
    }

    cout << "Game over! You ended with " << player.getM() << "." << endl;
    return 0;
}