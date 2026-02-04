/*
Name: Angelo Bisquera
Date: 06/01/25
Purpose: Card Class Specification
*/

#ifndef CARD_H
#define CARD_H

#include <string>
using namespace std;

enum Face {Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};

class Card{

    private:
        string suit; //Suit of the card
	    Face face;   //Face of the card
	    int value;   //Value of the card

    public:
        void setSuit(string suit){this->suit = suit;}
        void setFace(Face face){this->face = face;}
        void setVal(int value){this->value = value;}
        string getSuit(){return suit;}
        Face getFace(){return face;}
        int getVal(){return value;}

};

#endif