#include "Deck.h"

Deck::Deck() : h(nullptr), t(nullptr), s(0) {}

Deck::~Deck() {
    while (h != nullptr) {
        Node* temp = h;
        h = h->n;
        delete temp;
    }
}

void Deck::addCard(int c) {
    Node* nN = new Node(c); // new node
    if (t != nullptr) {
        t->n = nN;
    }
    t = nN;
    if (h == nullptr) {
        h = nN;
    }
    s++;
}

int Deck::drawCard() {
    if (h == nullptr) {
        throw std::out_of_range("Deck is empty");
    }
    Node* temp = h;
    int c = h->c;
    h = h->n;
    if (h == nullptr) {
        t = nullptr;
    }
    delete temp;
    s--;
    return c;
}

int Deck::peekCard() const {
    if (h == nullptr) {
        throw std::out_of_range("Deck is empty");
    }
    return h->c;
}

int Deck::countCards() const {
    return s;
}