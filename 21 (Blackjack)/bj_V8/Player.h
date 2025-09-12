/*
Name: Angelo Bisquera
Date: 06/01/25
Purpose: Player Class Specification
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "Dealer.cpp"

class Player : public Dealer{

    public:
        Player(string name)
            {this->name = name;}


};

#endif