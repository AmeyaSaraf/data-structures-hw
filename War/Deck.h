#ifndef DECK_H
#define DECK_H

#include <iostream>

class Deck {
private:
    struct Node {
        int card;
        Node* next;
        Node(int c) : card(c), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    Deck();
    ~Deck();
    void addCard(int card); // Adds a card to the tail of the deck
    int drawCard(); // Draws a card from the head of the deck
    int countCards() const; // Returns the number of cards remaining in the deck
};

#endif
