#include <iostream>
#include "Deck.h"
#include "SidePile.h"

void setupDecks(Deck& playerDeck, Deck& computerDeck) {
    // Initialize the decks with a set of cards for demonstration purposes.
    for (int i = 1; i <= 10; ++i) {
        playerDeck.addCard(i);
        computerDeck.addCard(11 - i);
    }
}

int main() {
    Deck playerDeck;
    Deck computerDeck;
    SidePile playerSidePile;
    SidePile computerSidePile;

    setupDecks(playerDeck, computerDeck);

    std::cout << "Choose play style (1 for playing until out of cards, 2 for fixed number of rounds): ";
    int playStyle;
    std::cin >> playStyle;

    // Validate input
    while (std::cin.fail() || (playStyle != 1 && playStyle != 2)) {
        std::cin.clear(); // Clear the error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
        std::cout << "Invalid input. Please enter 1 or 2: ";
        std::cin >> playStyle;
    }

    int roundCounter = 0;
    bool isGameOver = false;

    // Main loop for playing until one participant runs out of cards or for a fixed number of rounds
    while (!isGameOver) {
        std::cout << "Starting round " << roundCounter + 1 << "\n";
        std::cout << "Player deck size: " << playerDeck.countCards() << "\n";
        std::cout << "Computer deck size: " << computerDeck.countCards() << "\n";

        // Check if any player has run out of cards
        if (playerDeck.countCards() == 0 && playerSidePile.countCards() == 0) {
            std::cout << "Player has run out of cards. Computer wins!\n";
            isGameOver = true;
            break;
        }
        else if (computerDeck.countCards() == 0 && computerSidePile.countCards() == 0) {
            std::cout << "Computer has run out of cards. Player wins!\n";
            isGameOver = true;
            break;
        }

        try {
            // Draw cards from each deck
            int playerCard = playerDeck.drawCard();
            int computerCard = computerDeck.drawCard();

            // Show what cards were drawn
            std::cout << "Player drew: " << playerCard << ", Computer drew: " << computerCard << "\n";

            // Determine the winner of the round
            if (playerCard > computerCard) {
                std::cout << "Player wins this round!\n";
                playerDeck.addCard(playerCard);
                playerDeck.addCard(computerCard);
            }
            else {
                std::cout << "Computer wins this round (or ties go to the computer)!\n";
                computerDeck.addCard(playerCard);
                computerDeck.addCard(computerCard);
            }
        }
        catch (const std::out_of_range& e) {
            std::cout << "Error: " << e.what() << "\n";
            isGameOver = true;
        }

        // Increment the round counter for tracking
        roundCounter++;

        // Exit the loop if the play style is fixed number of rounds and limit is reached
        if (playStyle == 2 && roundCounter >= 10) {
            std::cout << "Fixed number of rounds reached.\n";
            isGameOver = true;
        }

        // Safety check to avoid infinite loops
        if (roundCounter > 20) {
            std::cout << "Game stopped to prevent an infinite loop.\n";
            isGameOver = true;
        }
    }

    // Final game state output
    std::cout << "Game over! Final deck sizes:\n";
    std::cout << "Player's deck size: " << playerDeck.countCards() << "\n";
    std::cout << "Computer's deck size: " << computerDeck.countCards() << "\n";

    return 0;
}
