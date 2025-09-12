/*
Name: Angelo Bisquera
Date: 06/01/25
Purpose: Project 2 - Blackjack - Version 2
*/

//System Libraries
#include <iostream> //I/O Library

//User Libraries
#include "Card.h"

//Global Constants
//Only use Scientific Values like PI, Speed of Light, etc.
//Conversion between units

//Function Prototypes
void genDeck(Card *);
void shoDeck(Card *);

int main(int argv,char **argc){
	//Random Seeds are set for the random number generators
	
	//Declare Variables
	Card *deck = new Card[52];

	//Initialize Values
	genDeck(deck);

	//Map the Inputs to Outputs - Process

	//Display and output the results
	shoDeck(deck);

	//Deallocate Memory
	delete deck;

	//Exit the program
	return 0;
	
}

void genDeck(Card *deck){

	string suits[]={"Spades", "Diamonds", "Clubs", "Hearts"};

	for(int i = 0; i < 52; i++){

		deck[i].setFace(static_cast <Face> (i % 13));
		deck[i].setSuit(suits[i / 13]);
		deck[i].setVal(deck[i].getFace() >= Ten ? 10 : static_cast <int> (deck[i].getFace()) + 1);

	}

}

void shoDeck(Card *deck){

	for(int i = 0; i < 52; i++){

		switch(deck[i].getFace()){

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
		cout << " " << deck[i].getSuit() << " " << deck[i].getVal() << endl;

	}

}