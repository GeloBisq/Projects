/*
Name: Angelo Bisquera
Date: 06/15/25
Purpose: Dealer Class Implementation
*/

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
		cout << " " << hand[i].getSuit();
		cout << " " << hand[i].getVal();
		cout << endl;

	}

}

void Dealer::newGame(){

	//Reset all Game Values
	total = 0;
	nCards = 0;
	delete hand;
	hand = new Card[10];

}

void Dealer::frstHnd(){

	cout << name << "'s Hand" << endl;
	cout << "Total: ??" << endl;
	cout << "Cards: " << endl;
	switch(hand[0].face){

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
	cout << " " << hand[0].suit << " " << hand[0].value << endl;
	cout << "??" << endl;

}

void Dealer::blckJck(){

	cout << name << "'s Hand" << endl;
	cout << "Total: 21" << endl;
	for(int i = 0; i < nCards; i++){

		switch(hand[i].face){

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
		cout << " " << hand[i].suit << " ";
		if(hand[i].value == 1) cout << 11 << endl;
		else cout << hand[i].value << endl;

	}

}

bool Dealer::hasBJ(){

	//If the Player / Dealer has the Cards that
	//Give them a Blackjack, bj is true
	bool bj = false;
	if((hand[0].value == 1 && hand[1].value == 10) || (hand[1].value == 1 && hand[0].value == 10)){

		bj = true;

	}

	return bj;

}

void Dealer::shoData(){

	//Output the Player / Dealer Info
    cout << "Name: " << name << endl;
	cout << "Number of Wins: " << nWins << endl;

}

template <class T>
void Dealer::operator+(Game<T> &g){

	//If the Card trying to be accessed is less than
	//the Deck's size, then you Deal a Card
	//to the Player / Dealer
	if(g.cardNum < g.deck.getSize()){

		hand[nCards] = g.deck.getCard(g.deck.getIndx(g.cardNum));
		total += hand[nCards].getVal();
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