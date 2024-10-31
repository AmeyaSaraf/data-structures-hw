#ifndef DECK_H
#define DECK_H

#include <iostream>

class Deck {
private:
    struct Node {
        int c; // card
        Node* n; // next
        Node(int card) : c(card), n(nullptr) {}
    };

    Node* h; // head
    Node* t; // tail
    int s;   // size

public:
    Deck();
    ~Deck();
    void addCard(int c); // Adds a card to the tail of the deck
    int drawCard(); // Draws a card from the head of the deck
    int countCards() const; // Returns the number of cards remaining in the deck
};

#endif

