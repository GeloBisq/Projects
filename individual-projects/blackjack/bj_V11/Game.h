/*
Name: Angelo Bisquera
Date: 06/15/25
Purpose: Game Class Specification
*/

#ifndef GAME_H
#define GAME_H

#include "Deck.cpp"

template <class T>
class Game{

    private:
        static int nGames;			  //Number of games
        static int cardNum;			  //Card index from the deck
        Deck deck;                    //Deck of Cards
        char *winner = new char[100]; //Stores the winner of each game
	    T *pTotal  = new T[100];      //Stores the player's score from each game
	    T *dTotal  = new T[100];      //Stores the dealer's score from each game

    public:
        friend class Dealer;
        friend class Player;
        ~Game();

        static int getGame()
            {return nGames;}

        static void newGame()
            {nGames++;}

        void operator!()
            {deck %= 1;}

        void operator&()
            {deck.shoDeck();}
            
        void savRslt(char, T, T);
        void shoRslt();
        void wrtInfo();
        void rdInfo();
        
};

template <class T>
int Game<T>::nGames = 0;
template <class T>
int Game<T>::cardNum = 0;

#endif