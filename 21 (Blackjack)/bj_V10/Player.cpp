/*
Name: Angelo Bisquera
Date: 06/01/25
Purpose: Player Class Implementation
*/

#include "Player.h"
using namespace std;

void Player::setWage(float wager){

    try{

        if(wager < this->wager || wager < 0) throw wager;
        else this->wager = wager;

    }
    catch(float badWage){

        cout << "Invalid Wager" << endl;

    }

}