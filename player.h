#ifndef __PLAYER_H
#define __PLAYER_H

class Player {
    public:
        std::vector<card> hand = {};

        Player();
        int SelectCard();

        void AddToHand(card card);
        void RemoveFromHand(int index);
        void DisplayHand();
};


class PlayerAI{
    public:
        std::vector<card> hand = {};

        PlayerAI();
        int SelectCard(card top_card);

        void AddToHand(card card);
        void RemoveFromHand(int index);
        void DisplayHand();
};

#endif