/*
Name: Angelo Bisquera
Date: 05/11/25
Purpose: Blackjack - Version 3
*/

//System Libraries
#include <iostream> //I/O Library
#include <fstream>  //File Library
#include <cstdlib>  //Random Function Library
#include <ctime>    //Time Library
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

struct Deck{

	Card *cards;
	int *index;
	int size,
		nDecks;

};

//Function Prototypes
Deck *genDeck();
void shoDeck(Deck *);
void wrtDeck(Deck *, fstream &);
Deck *rdDeck(fstream &);
void shuffle(Deck *);
void delDeck(Deck *);


int main(int argv,char **argc){
	//Random Seeds are set for the random number generators
	srand(static_cast<unsigned int>(time(0)));

	//Declare Variables
	Deck *d = genDeck();
	fstream file;

	//Initialize Values
	file.open("deck.bin", ios::in|ios::out|ios::binary|ios::app);

	//Map the Inputs to Outputs - Process
	wrtDeck(d, file);
	Deck *test = rdDeck(file);
	shoDeck(test);

	//Display and output the results
	
	//Close Files
	file.close();

	//Deallocate Memory
	delDeck(test);
	delDeck(d);

	//Exit the program
	return 0;
	
}

Deck *genDeck(){

	Deck *d = new Deck;
	
	//Choose how many decks to use and size of Card array
	cout << "How many decks of cards would you like to use? (1-8)" << endl;
	cin >> d->nDecks;
	while(d->nDecks > 8 || d->nDecks < 1){

		cout << "Invalid Number of Decks. Try Another Number" << endl;
		cin >> d->nDecks;

	}
	d->size = d->nDecks * 52;

	//Fill the index array
	d->index = new int[d->size];
	for(int i = 0; i < d->size; i++){

		d->index[i] = i;

	}
	d->cards = new Card[d->size];

	char suits[]={'S', 'D', 'C', 'H'};
	for(int i = 0; i < d->size; i++){

		d->cards[i].face = static_cast <Face> (i % 13);
		d->cards[i].suit = suits[(i % 52) / 13];
		d->cards[i].value = d->cards[i].face >= Ten ? 10 : static_cast <int> (d->cards[i].face) + 1;

	}
	
	return d;

}

void shoDeck(Deck *d){

	cout << "Number of Decks in Play: " << d->nDecks << endl;
	cout << "Total Number of Cards in Play: " << d->size << endl;
	cout << "Index | Face | Suit | Value" << endl;

	for(int i = 0; i < d->size; i++){

		cout << d->index[i] << " ";

		switch(d->cards[d->index[i]].face){

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
		cout << " " << d->cards[d->index[i]].suit << " " << d->cards[d->index[i]].value << endl;

	}

}

void wrtDeck(Deck *d, fstream &file){

	file.seekp(0);
	file.write(reinterpret_cast<char *>(&d->size), sizeof(int));
	file.write(reinterpret_cast<char *>(d->index), d->size * sizeof(int));
	file.write(reinterpret_cast<char *>(d->cards), d->size * sizeof(Card));

}

Deck *rdDeck(fstream &file){

	file.seekg(0);
	Deck *temp = new Deck;
	file.read(reinterpret_cast<char *>(&temp->size), sizeof(int));
	temp->nDecks = (temp->size) / 52;
	temp->index = new int[temp->size];
	temp->cards = new Card[temp->size];
	file.read(reinterpret_cast<char *>(temp->index), temp->size * sizeof(int));
	file.read(reinterpret_cast<char *>(temp->cards), temp->size * sizeof(Card));
	
	return temp;

}

void shuffle(Deck *d){

	int nShufle;
	cout << "How many times would you like to shuffle the deck?" << endl;
	cin >> nShufle;

	for(int i = 0; i < nShufle; i++){

		for(int j = 0; j < d->size; j++){

			int random = rand() % d->size;
			int temp = d->index[j];
			d->index[j] = d->index[random];
			d->index[random] = temp;

		}

	}

}

void delDeck(Deck *d){

	delete d->cards;
	delete d->index;
	delete d;

}