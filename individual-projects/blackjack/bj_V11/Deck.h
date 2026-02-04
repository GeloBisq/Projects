/*
Name: Angelo Bisquera
Date: 06/15/25
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
        ~Deck();
        void shoDeck();
        void wrtDeck();
        void rdDeck();
        void operator%=(int);

        int getSize()
            {return size;}

        Card getCard(int index)
            {return cards[index];}
            
        int getIndx(int index)
            {return this->index[index];}

};

#endif