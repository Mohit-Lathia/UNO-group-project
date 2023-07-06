#include <string>
#include <vector>
#include <random>
#include <iostream>

using namespace std;

#include "card.h"
#include "player.h"
#include "uno.h"

// Sets up the uno class by shuffling the cards in the deck
Uno::Uno() {
    deck.ShuffleDeck();
}


// Deals the top card to a Player class
void Uno::DealCard(Player *pplayer) {
    pplayer->AddToHand(deck.deck.back());
    deck.deck.pop_back();
}


// Deals the top card to a PlayerAI class
void Uno::DealCard(PlayerAI *pai) {
    pai->AddToHand(deck.deck.back());
    deck.deck.pop_back();
}


// Checks if a given card is playable on top of the current top_card
bool Uno::CheckPlayable(card check_card) {
    card top_card = play_pile.back();
    if (check_card.value == top_card.value || check_card.colour == top_card.colour) {return true;}
    return false;
}


// Execute one turn of the game
void Uno::GameTurn() {
    turn ++;

    bool checking = true;
    int index = 0;

    card played_card;
    
    played_card = play_pile.back();
    cout << "Turn: " << turn << endl;
    cout << "Top Card: " << played_card.colour << " " << played_card.value << endl << endl;

    while (checking) {
        index = player.SelectCard() - 1;
        if (index == -1) {
            DealCard(&player);
            played_card = player.hand.back();
            cout << "You draw a " << played_card.colour << " " << played_card.value << endl;
            cout << "You have " << player.hand.size() << " cards." << endl << endl;
            break;
        }

        played_card = player.hand[index];
        if (CheckPlayable(played_card)) {
            cout << "You play " << played_card.colour << " " << played_card.value << endl;
            cout << "You have " << player.hand.size() << " cards." << endl << endl;
            play_pile.push_back(played_card);
            player.RemoveFromHand(index);
            checking = false;
        } else {
            cout << "You cannot play " << played_card.colour << " " << played_card.value << " as neither colour nor value match the top card" << endl << endl;
        }

        if (player.hand.size() < 1) {EndGame("Player");}
    }


    index = ai1.SelectCard(play_pile.back()) - 1;
    if (index == -1) {
        DealCard(&ai1);
        cout << "AI1 draws a card." << endl;;
        cout << "AI1 has " << ai1.hand.size() << " cards." << endl << endl;

    } else {
        played_card = ai1.hand[index];
        play_pile.push_back(played_card);
        ai1.RemoveFromHand(index);
        cout << "AI1 plays " << played_card.colour << " " << played_card.value << endl;
        cout << "AI1 has " << ai1.hand.size() << " cards." << endl << endl;
    }

    if (ai1.hand.size() < 1) {EndGame("AI1");}


    index = ai2.SelectCard(play_pile.back()) - 1;
    if (index == -1) {
        DealCard(&ai2);
        cout << "AI2 draws a card." << endl;
        cout << "AI2 has " << ai2.hand.size() << " cards." << endl << endl;
    } else {
        played_card = ai2.hand[index];
        play_pile.push_back(played_card);
        ai2.RemoveFromHand(index);
        cout << "AI2 plays " << played_card.colour << " " << played_card.value << endl;
        cout << "AI2 has " << ai2.hand.size() << " cards." << endl << endl;
    }

    if (ai2.hand.size() < 1) {EndGame("AI2");}

    
    index = ai3.SelectCard(play_pile.back()) - 1;
    if (index == -1) {
        DealCard(&ai3);
        cout << "AI3 draws a card." << endl;
        cout << "AI3 has " << ai3.hand.size() << " cards." << endl << endl;
    } else {
        played_card = ai3.hand[index];
        play_pile.push_back(played_card);
        ai3.RemoveFromHand(index);
        cout << "AI3 plays " << played_card.colour << " " << played_card.value << endl;
        cout << "AI3 has " << ai3.hand.size() << " cards." << endl << endl;
    }

    if (ai3.hand.size() < 1) {EndGame("AI3");}   

    if (!game_over) {GameTurn();}
    
}


// Sets up the startign hands for each Player and PlayerAI
void Uno::SetupHands() {
    for (int i = 0; i < 7; i++) {
        DealCard(&player);
        DealCard(&ai1);
        DealCard(&ai2);
        DealCard(&ai3);
    }
}


// Run to start a game of Uno
void Uno::StartGame() {
    SetupHands();
    cout << "Game is Starting" << endl;
    play_pile.push_back(deck.deck.back());
    deck.deck.pop_back();
    cout << "Starting Card: " << play_pile[0].colour << " " << play_pile[0].value << endl << endl;

    GameTurn();
}


void Uno::EndGame(string winner) {
    game_over = true;
    cout << winner << " has run out of cards and has Won." << endl;
}
