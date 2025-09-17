/*
Name: Angelo Bisquera
Date: 06/01/25
Purpose: Player Class Specification
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "Dealer.cpp"

class Player : public Dealer{

    private:
        float wager = 0.0,
              points = 1000.0;


    public:
        Player(string name)
            {this->name = name;}
        void setName(string name)
            {this->name = name;}
        void setWage(float);
        float getWage()
            {return wager;}
        float getPts()
            {return points;}


};

#endif