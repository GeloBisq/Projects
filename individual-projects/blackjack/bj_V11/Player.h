/*
Name: Angelo Bisquera
Date: 06/15/25
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
        void setPts(string, bool);

        float getWage()
            {return wager;}

        float getPts()
            {return points;}
            
        void choseBJ();
        template <class T>
        void operator+(Game<T> &);


};

#endif