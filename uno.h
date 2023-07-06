#ifndef __UNO_H
#define __UNO_H



class Uno {
    public:
        Player player;
        PlayerAI ai1, ai2, ai3;

        Deck deck;
        vector<card> play_pile = {};

        int turn = 0;
        bool game_over = false;
        
        Uno();

        void DealCard(Player *pplayer);
        void DealCard(PlayerAI *pai);

        bool CheckPlayable(card card);
        void GameTurn();
        void SetupHands();
        void StartGame();

        void EndGame(string winner);
};


#endif