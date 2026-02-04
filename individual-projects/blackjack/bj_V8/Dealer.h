/*
Name: Angelo Bisquera
Date: 06/01/25
Purpose: Dealer Class Specification
*/

#ifndef DEALER_H
#define DEALER_H

#include "Card.h"

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
        void getHand();
        void getData();
};

int Dealer::nPlayrs = 0;

#endif