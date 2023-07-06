#include <string>
#include <vector>
#include <iostream>

using namespace std;

#include "card.h"
#include "player.h"


// Player Class

Player::Player() {

}

int Player::SelectCard() {
    int i = 1;
    int input = 0;

    cout << "Current Hand: " << endl;
    cout << "0. Draw Card" << endl;
    for (card card:hand) {
        cout << to_string(i) << ". " << card.colour << " " << card.value << endl;
        i++;
    }
    
    cout << endl << "Please enter the value of the option you would like to select: ";
    cin >> input;

    cout << endl;
    return input;
}


void Player::AddToHand(card card) {
    hand.push_back(card);
}


void Player::RemoveFromHand(int index) {
    hand.erase(hand.begin() + index);
}


void Player::DisplayHand() {
    cout << "Current Hand: " << endl;
    for (card card:hand) {cout << card.colour << " " << card.value << endl;}
    cout << endl;
}

// PlayerAI Class


PlayerAI::PlayerAI() {

}


int PlayerAI::SelectCard(card top_card) {
    for (int i = 0; i < hand.size(); i++) {
        if (hand[i].value == top_card.value || hand[i].colour == top_card.colour) {return i + 1;}
    } 
    return 0;
}


void PlayerAI::AddToHand(card card) {
    hand.push_back(card);
}


void PlayerAI::RemoveFromHand(int index) {
    hand.erase(hand.begin() + index);
}


void PlayerAI::DisplayHand() {
    cout << "Current AI Hand: " << endl;
    for (card card:hand) {cout << card.colour << " " << card.value << endl;}
    cout << endl;
}