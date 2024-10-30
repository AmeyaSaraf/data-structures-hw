#include "SidePile.h"

SidePile::SidePile() {
    top = -1;
}

void SidePile::add(int c) {
    if (top >= maxCards - 1) {
        throw fullDeck();
    }
    else {
        top = top + 1;
        Cards[top] = c;
    }
}

int SidePile::remove() {
    if (top < 0) {
        throw emptyDeck();
    }
    else {
        int removedCard = Cards[top];
        top = top - 1;
        return removedCard;
    }
}

int SidePile::countCards() {
    int num = top + 1;
    return num;
}


