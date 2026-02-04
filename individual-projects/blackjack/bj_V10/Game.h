/*
Name: Angelo Bisquera
Date: 06/01/25
Purpose: Game Class Specification
*/

#ifndef GAME_H
#define GAME_H

#include "Deck.cpp"

class Game{

    private:
        static int nGames;			      //Number of games
        static int cardNum;			      //Card index from the deck
        Deck deck;                        //Deck of Cards
        string *winner = new string[100]; //Stores the winner of each game
	    int *pTotal  = new int[100];      //Stores the player's score from each game
	    int *dTotal  = new int[100];      //Stores the dealer's score from each game

    public:
        friend class Dealer;
        Game()
            {nGames++;}
        ~Game()
            {delete winner; delete pTotal; delete dTotal;}
        static int getGame()
            {return nGames;}
        void operator!()
            {deck %= 1;}
        void operator&()
            {deck.shoDeck();}

        
        

};

int Game::nGames = 0;
int Game::cardNum = 0;

#endif