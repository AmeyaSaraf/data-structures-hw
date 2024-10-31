#include "Deck.h"

Deck::Deck() : head(nullptr), tail(nullptr), size(0) {}

Deck::~Deck() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void Deck::addCard(int card) {
    Node* newNode = new Node(card);
    if (tail != nullptr) {
        tail->next = newNode;
    }
    tail = newNode;
    if (head == nullptr) {
        head = newNode;
    }
    size++;
}

int Deck::drawCard() {
    if (head == nullptr) {
        throw std::out_of_range("Deck is empty");
    }
    Node* temp = head;
    int card = head->card;
    head = head->next;
    if (head == nullptr) {
        tail = nullptr;
    }
    delete temp;
    size--;
    return card;
}

int Deck::countCards() const {
    return size;
}

