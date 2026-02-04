/*
Name: Angelo Bisquera
Date: 05/11/25
Purpose: Blackjack - Version 1
*/

//System Libraries
#include <iostream> //I/O Library
using namespace std;

//User Libraries

//Global Constants
//Only use Scientific Values like PI, Speed of Light, etc.
//Conversion between units

//Enumerated Data Types
enum Face {Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};

//Structures
struct Card{

	string suit;
	Face face;
	int value;

};

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