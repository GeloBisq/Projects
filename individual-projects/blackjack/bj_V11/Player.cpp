/*
Name: Angelo Bisquera
Date: 06/15/25
Purpose: Player Class Implementation
*/

#include "Player.h"
using namespace std;

void Player::setWage(float wager){

    //Throws an Exception if the Wager is
    //Greater than the Points owned or less than zero
    try{

        if(wager > points || wager < 0) throw wager;
        else this->wager = wager;

    }
    catch(float badWage){

        cout << setw(5) << "";
        cout << "Invalid Wager";
        cout << endl;

    }

}

void Player::setPts(string winner, bool BJ){

    if(winner == "Player" && BJ) points += wager * 1.5f;
    else if(winner == "Player")  points += wager;
    else if (winner == "Dealer") points -= wager;

}

template <class T>
void Player::operator+(Game<T> &g){

    //If the Card trying to be accessed is less than
	//the Deck's size, then you Deal a Card
	//to the Player / Dealer
	if(g.cardNum < g.deck.getSize()){

		hand[nCards] = g.deck.getCard(g.deck.getIndx(g.cardNum));
        //The Player can choose to play a one or an eleven
        //If they are dealt an Ace
        if(hand[nCards].getFace() == 'A'){

            int temp;
            cout << setw(5) << "";
            cout << "How would you like to play the Ace? (1/11)";
            cout << endl;
            cin >> temp;
            while(temp != 1 || temp != 11){

                cout << setw(5) << "";
                cout << "Invalid Value";
                cout << endl;
                cout << setw(5) << "";
                cout << "Choose Another Value";
                cout << endl;
                cin >> temp;

            }

            total += temp;

        } //Otherwise the Card's Value is added to the
        //Total as it normally does 
        else total += hand[nCards].getVal();
		nCards++;
		g.cardNum++;

	} //Otherwise, the Deck is shuffled and the
	//Card being read is reset to zero before Dealing	 
    else {

		!g;
		g.cardNum = 0;
		hand[nCards] = g.deck.getCard(g.deck.getIndx(g.cardNum));
		total += hand[nCards].getVal();
		nCards++;
		g.cardNum++;

	}

}