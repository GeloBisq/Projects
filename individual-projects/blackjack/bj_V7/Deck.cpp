/*
Name: Angelo Bisquera
Date: 06/01/25
Purpose: Deck Class Implementation
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Deck.h"
using namespace std;

Deck::Deck(){

    //Choose how many decks to use and size of Card array
	cout << "How many decks of cards would you like to use? (1-8)" << endl;
	cin >> nDecks;
	while(nDecks > 8 || nDecks < 1){

		cout << "Invalid Number of Decks. Try Another Number" << endl;
		cin >> nDecks;

	}
	size = nDecks * 52;

	//Fill the index array
    index = new int[size];
	for(int i = 0; i < size; i++){

		index[i] = i;

	}
	cards = new Card[size];

	char suits[]={'S', 'D', 'C', 'H'};
	for(int i = 0; i < size; i++){

		cards[i].setFace(static_cast <Face> (i % 13));
		cards[i].setSuit(suits[(i % 52) / 13]);
		cards[i].setVal(cards[i].getFace() >= Ten ? 10 : static_cast <int> (cards[i].getFace()) + 1);

	}

}

void Deck::shoDeck(){

    cout << "Number of Decks in Play: " << nDecks << endl;
	cout << "Total Number of Cards in Play: " << size << endl;
	cout << "Index | Face | Suit | Value" << endl;

	for(int i = 0; i < size; i++){

		cout << index[i] << " ";

		switch(cards[index[i]].getFace()){

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
		cout << " " << cards[index[i]].getSuit() << " " << cards[index[i]].getVal() << endl;

	}

}

void Deck::shuffle(){

    int nShufle;
	cout << "How many times would you like to shuffle the deck?" << endl;
	cin >> nShufle;

	for(int i = 0; i < nShufle; i++){

		for(int j = 0; j < size; j++){

			int random = rand() % size;
			int temp = index[j];
			index[j] = index[random];
			index[random] = temp;

		}

	}

}