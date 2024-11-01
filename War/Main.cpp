#include <iostream>
#include "Deck.h"
#include "SidePile.h"

void setupDecks(Deck& playerDeck, Deck& computerDeck) {
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

    int roundCounter = 0;
    bool isGameOver = false;

    while (!isGameOver) {
        if (playerDeck.countCards() == 0 && playerSidePile.countCards() == 0) {
            std::cout << "Player has no cards left. Computer wins!\n";
            break;
        }
        if (computerDeck.countCards() == 0 && computerSidePile.countCards() == 0) {
            std::cout << "Computer has no cards left. Player wins!\n";
            break;
        }

        int playerCard = playerDeck.drawCard();
        int computerCard = computerDeck.drawCard();

        std::cout << "Player drew: " << playerCard << ", Computer drew: " << computerCard << "\n";
        if (playerCard > computerCard) {
            std::cout << "Player wins this round!\n";
            playerDeck.addCard(playerCard);
            playerDeck.addCard(computerCard);
        } else {
            std::cout << "Computer wins this round (or ties go to the computer)!\n";
            computerDeck.addCard(playerCard);
            computerDeck.addCard(computerCard);
        }

        roundCounter++;
        if (playStyle == 2 && roundCounter >= 10) {
            std::cout << "Fixed number of rounds reached.\n";
            isGameOver = true;
        }
    }

    std::cout << "Game over! Player's deck size: " << playerDeck.countCards()
              << ", Computer's deck size: " << computerDeck.countCards() << "\n";
    
    return 0;
}
