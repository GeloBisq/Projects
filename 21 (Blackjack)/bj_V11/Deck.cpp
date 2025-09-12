/*
Name: Angelo Bisquera
Date: 06/15/25
Purpose: Deck Class Implementation
*/

#include <iostream> //I/O Library
#include <iomanip>  //Format Library
#include <cstdlib>  //Random Function Library
#include <ctime>    //Time Library
#include <fstream> //Filestream Library
#include "Deck.h"
using namespace std;

Deck::Deck(){

    //Choose how many decks to use and size of Card array
	cout << setw(5) << "";
	cout << "How many decks of cards would you like to use? (1-8)";
	cout << endl;
	cout << setw(5) << "";
	cin >> nDecks;
	try{

		if(nDecks > 8 || nDecks < 1) throw nDecks;

	}
	catch(int badDeck){

		cout << "Invalid Number of Decks" << endl;

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

Deck::~Deck(){

	delete cards;
	delete index;

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
		cout << " " << cards[index[i]].getSuit();
		cout << " " << cards[index[i]].getVal();
		cout << endl;

	}

}

void Deck::wrtDeck(){

	fstream file;
	file.open("deck.txt", ios::in|ios::out);
	file.seekp(0);
	for(int i = 0; i < size; i++){

		file << setw(5) << "" << index[i] << " ";
		switch(cards[i].getFace()){

			case 12 : file << "King"; break;
			case 11 : file << "Queen"; break;
			case 10 : file << "Jack"; break;
			case 9  : file << "Ten"; break;
			case 8  : file << "Nine"; break;
			case 7  : file << "Eight"; break;
			case 6  : file << "Seven"; break;
			case 5  : file << "Six"; break;
			case 4  : file << "Five"; break;
			case 3  : file << "Four"; break;
			case 2  : file << "Three"; break;
			case 1  : file << "Two"; break;
			case 0  : file << "Ace"; break;

		}
		file << " " << cards[i].getSuit();
		file << " " << cards[i].getVal();
		cout << endl; 

	}

	file.close();

}

void Deck::rdDeck(){

	fstream file;
	file.seekg(0);
	Deck *temp = new Deck;
	file.read(reinterpret_cast<char *>(&temp->size), sizeof(int));
	temp->nDecks = (temp->size) / 52;

	//Index and Cards are pointer arrays inside of the structure
	temp->index = new int[temp->size];
	temp->cards = new Card[temp->size];

	file.read(reinterpret_cast<char *>(temp->index), temp->size * sizeof(int));
	file.read(reinterpret_cast<char *>(temp->cards), temp->size * sizeof(Card));

	delete temp;

}

void Deck::operator%=(int num){

	for(int i = 0; i < num; i++){

		for(int j = 0; j < size; j++){

			int random = rand() % size;
			int temp = index[j];
			index[j] = index[random];
			index[random] = temp;

		}

	}

}