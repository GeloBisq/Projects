/*
Name: Angelo Bisquera
Date: 06/01/25
Purpose: Player Class Implementation
*/

#include "Player.h"
using namespace std;

Player::Player(const Dealer *p){

    name = p->getName();
    hand = p->getHand();
    total = p->getTotl();
	nCards = p->getNCrd();
	nWins = p->getNWin();

}

void Player::setWage(float wager){

    try{

        if(wager < this->wager || wager < 0) throw wager;
        else this->wager = wager;

    }
    catch(float badWage){

        cout << "Invalid Wager" << endl;

    }

}