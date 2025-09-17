/*
Name: Angelo Bisquera
Date: 06/01/25
Purpose: Dealer Class Specification
*/

#ifndef DEALER_H
#define DEALER_H

#include "Game.h"

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
        void operator+(Game &);

};

int Dealer::nPlayrs = 0;

#endif