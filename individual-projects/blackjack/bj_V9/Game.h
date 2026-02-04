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
        static int nGames;			  //Number of games
        Deck *deck = new Deck;        //Deck of Cards
        char *winner = new char[100]; //Stores the winner of each game
	    int *pTotal  = new int[100];  //Stores the player's score from each game
	    int *dTotal  = new int[100];  //Stores the dealer's score from each game

    public:
        Game()
            {nGames++;}
        ~Game()
            {delete deck; delete winner; delete pTotal; delete dTotal;}
        static int getGame()
            {return nGames;}

        
        

};

int Game::nGames = 0;

#endif