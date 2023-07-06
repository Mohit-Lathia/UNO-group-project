#include <string>
#include <vector>
#include <random>
#include <iostream>

using namespace std;

#include "card.h"

// Constuctor for the deck
Deck::Deck() {
    card temp_card;
    for (int i = 0; i < 3; i++) {
        for (string colour:colours) {
            temp_card.colour = colour;
            for (int value:values) {
                temp_card.value = value;
                deck.push_back(temp_card);
            }
        }
    }
}


// Shuffles the cards in the deck
void Deck::ShuffleDeck() {
    random_device rand;
    mt19937 gen(rand());
    uniform_int_distribution<int> distr(0, deck.size() - 1);
    for (int i = 0; i < (10 * deck.size()); i++){
        int random_start = distr(gen);
        int random_end = distr(gen);
        swap(deck[random_start], deck[random_end]);
    }
}

// Displays the cards in the deck, for checking functions work
void Deck::DisplayDeck() {
    cout << "Current Deck Order:" << endl;
    for (card card:deck) {
        cout << card.colour << " " << card.value << endl;
    }
}