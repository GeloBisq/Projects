/*
Name: Angelo Bisquera
Date: 06/01/25
Purpose: Dealer Class Implementation
*/

#include <iostream>
#include "Dealer.h"
using namespace std;

void Dealer::shoHand(){

    cout << "Total: " << total << endl;
	cout << "Cards: " << endl;
	for(int i = 0; i < nCards; i++){

		switch(hand[i].getFace()){

			case 12 : cout << "King"; break;
			case 11 : cout << "Queen"; break;
			case 10 : cout << "Jack"; break;
			case 9  : cout << "Ten"; break;
			case 8  : cout << "Nine"; break;
			case 7  : cout << "Eight"; break;
			case 6  : cout << "Seven"; break;
			case 5  : cout << "Six"; break;
			case 4  : cout << "Five"; break;
			case 3  : cout << "Four"; break;
			case 2  : cout << "Three"; break;
			case 1  : cout << "Two"; break;
			case 0  : cout << "Ace"; break;

		}
		cout << " " << hand[i].getSuit() << " " << hand[i].getVal() << endl;

	}

}

void Dealer::shoData(){

    cout << "Name: " << name << endl;
	cout << "Number of Wins: " << nWins << endl;

}