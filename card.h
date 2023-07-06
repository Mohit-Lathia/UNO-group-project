#ifndef __CARDS_H
#define __CARDS_H

struct card {
    int value;
    string colour;
};

class Deck {
    public:
        int values[10] = {0,1,2,3,4,5,6,7,8,9};
        string colours[4] = {"Red","Green","Blue","Yellow"};

        vector<card> deck = {};

        Deck();

        void ShuffleDeck();
        void DisplayDeck();
};


#endif


