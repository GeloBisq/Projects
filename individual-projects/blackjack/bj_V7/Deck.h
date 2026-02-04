/*
Name: Angelo Bisquera
Date: 05/25/25
Purpose: Class Specification
*/

#ifndef CLASS_H
#define CLASS_H

#include "Card.h"

class Deck{

    private:
        Card *cards;
        int *index;
	    int size,
		    nDecks;

    public:
        Deck();
        ~Deck(){delete cards; delete index;}
        void shoDeck();
        void shuffle();

};

#endif