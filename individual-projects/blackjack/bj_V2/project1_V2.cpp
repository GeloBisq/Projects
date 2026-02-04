/*
Name: Angelo Bisquera
Date: 05/11/25
Purpose: Blackjack - Version 2
*/

//System Libraries
#include <iostream> //I/O Library
#include <fstream>  //File Library
using namespace std;

//User Libraries

//Global Constants
//Only use Scientific Values like PI, Speed of Light, etc.
//Conversion between units

//Enumerated Data Types
enum Face {Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};

//Structures
struct Card{

	char suit;
	Face face;
	int value;

};

//Function Prototypes
void genDeck(Card *);
void shoDeck(Card *);
void wrtDeck(Card *, fstream &);
Card *rdDeck(fstream &);

int main(int argv,char **argc){
	//Random Seeds are set for the random number generators
	
	//Declare Variables
	fstream file;
	Card *deck = new Card[52];

	//Initialize Values
	genDeck(deck);

	//Map the Inputs to Outputs - Process

	//Display and output the results
	wrtDeck(deck, file);
	Card *temp = rdDeck(file);
	shoDeck(temp);
	
	//Close Files
	file.close();

	//Deallocate Memory
	delete temp;
	delete deck;

	//Exit the program
	return 0;
	
}

void genDeck(Card *deck){

	char suits[]={'S', 'D', 'C', 'H'};

	for(int i = 0; i < 52; i++){

		deck[i].face = static_cast <Face> (i % 13);
		deck[i].suit = suits[i / 13];
		deck[i].value = deck[i].face >= Ten ? 10 : static_cast <int> (deck[i].face) + 1;

	}

}

void shoDeck(Card *deck){

	for(int i = 0; i < 52; i++){

		switch(deck[i].face){

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
		cout << " " << deck[i].suit << " " << deck[i].value << endl;

	}

}

void wrtDeck(Card *deck, fstream &file){

	file.open("deck.bin", ios::in|ios::out|ios::binary|ios::app);
	file.seekp(0);

	for(int i = 0; i < 52; i++){

		file.write(reinterpret_cast<char *>(&deck[i].face), sizeof(Face));
		file.write(reinterpret_cast<char *>(&deck[i].suit), sizeof(char));
		file.write(reinterpret_cast<char *>(&deck[i].value), sizeof(int));

	}

	file.close();

}

Card *rdDeck(fstream &file){

	Card *temp = new Card[52];
	file.open("deck.bin", ios::in|ios::out|ios::binary|ios::app);
	file.seekg(0);

	for(int i = 0; i < 52; i++){

		file.read(reinterpret_cast<char *>(&temp[i].face), sizeof(Face));
		file.read(reinterpret_cast<char *>(&temp[i].suit), sizeof(char));
		file.read(reinterpret_cast<char *>(&temp[i].value), sizeof(int));

	}

	file.close();

	return temp;

}