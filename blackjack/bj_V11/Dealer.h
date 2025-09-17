/*
Name: Angelo Bisquera
Date: 06/15/25
Purpose: Dealer Class Specification
*/

#ifndef DEALER_H
#define DEALER_H

#include "game.cpp"

class Dealer{

    protected:
        static int nPlayrs;
        string name;
        Card *hand = new Card[10];
        int total = 0;
	    int nCards = 0;
	    int nWins = 0;

    public:
        Dealer()
            {name = "Dealer"; nPlayrs++;}

        ~Dealer()
            {delete hand;}

        static void getPlyr()
            {cout << "Number of Players: " << nPlayrs << endl;}

        void shoHand();
        void shoData();
        void newGame();
        void frstHnd();
        void blckJck();
        bool hasBJ();

        string getName() const
            {return name;}

        Card *getHand() const
            {return hand;} 

        int getTotl() const
            {return total;}

        int getNCrd() const
            {return nCards;}

        int getNWin() const
            {return nWins;}
            
        template <class T>
        void operator+(Game<T> &);

};

int Dealer::nPlayrs = 0;

#endif