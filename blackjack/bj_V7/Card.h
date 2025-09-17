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
        char suit; //Suit of the card
	    Face face;   //Face of the card
	    int value;   //Value of the card

    public:
        Card(){}
        Card(char suit, Face face, int value){

            this->suit = suit;
            this->face = face;
            this->value = value;

        }
        void setSuit(char suit){this->suit = suit;}
        void setFace(Face face){this->face = face;}
        void setVal(int value){this->value = value;}
        char getSuit(){return suit;}
        Face getFace(){return face;}
        int getVal(){return value;}

};

#endif