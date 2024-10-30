#include "iostream"

class SidePile {
    public:
        SidePile();
        static const int maxCards = 5;
        int Cards[maxCards];
        void add(int);
        int remove();
        int countCards();

        class fullDeck {};
        class emptyDeck {};

    private:
        int top;
};