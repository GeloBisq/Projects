/*
Name: Angelo Bisquera
Date: 05/11/25
Purpose: Blackjack - Version 4
*/

//System Libraries
#include <iostream> //I/O Library
#include <fstream>  //File Library
#include <cstdlib>  //Random Function Library
#include <ctime>    //Time Library
#include <cstring>  //C-String Library
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

struct Player{

	char *name;
	Card *hand = new Card[10]; //Can hold a maximum of 10 cards
	int total = 0;
	int nCards = 0;
	int nWins = 0;

};

//Function Prototypes
Player *genPlay();
Player *genDeal();
void playDat(Player *);
void deal(Player *, Deck *);
void handDat(Player *);
void delPlay(Player *);
Deck *genDeck();
void deckDat(Deck *);
void wrtDeck(Deck *, fstream &);
Deck *rdDeck(fstream &);
void shuffle(Deck *);
void delDeck(Deck *);


int main(int argv,char **argc){
	//Random Seeds are set for the random number generators
	srand(static_cast<unsigned int>(time(0)));

	//Declare Variables and Initialize Values
	Player *p = genPlay();
	Player *d = genDeal();
	Deck *deck = genDeck();

	shuffle(deck);
	deckDat(deck);
	deal(p, deck);
	deal(p, deck);
	deal(d, deck);
	deal(d, deck);

	handDat(p);
	handDat(d);

	//Close Files

	//Deallocate Memory
	delDeck(deck);
	delPlay(d);
	delPlay(p);

	//Exit the program
	return 0;
	
}

Player *genPlay(){

	Player *play = new Player;

	//Enter a name for the player
	string checkNm;
	cout << "Enter the player's name (1-20 characters)" << endl;
	getline(cin,checkNm);
	while(checkNm.length() > 20 || checkNm.length() < 1){

		cout << "Invalid Number of Characters. Enter another name" << endl;
		getline(cin,checkNm);

	}
	
	//Set the name of the player
	play->name = new char[checkNm.length()];
	strcpy(play->name, checkNm.c_str());

	return play;

}

Player *genDeal(){

	//Set up dealer
	Player *deal = new Player;
	string name = "Dealer";
	deal->name = new char[name.length()];
	strcpy(deal->name, name.c_str());

	return deal;

}

void playDat(Player *p){

	cout << "Name: " << p->name << endl;
	cout << "Number of Wins: " << p->nWins << endl;

}

void deal(Player *p, Deck *d){

	static int cardNum = 0; //Card index from the deck
	if(cardNum < d->size){

		p->hand[p->nCards] = d->cards[d->index[cardNum]];
		p->total += p->hand[p->nCards].value;
		p->nCards++;
		cardNum++;

	} else {

		shuffle(d);
		cardNum = 0;
		p->hand[p->nCards] = d->cards[d->index[cardNum]];
		p->total += p->hand[p->nCards].value;
		p->nCards++;
		cardNum++;

	}

}

void handDat(Player *p){

	cout << "Total: " << p->total << endl;
	cout << "Cards: " << endl;
	for(int i = 0; i < p->nCards; i++){

		switch(p->hand[i].face){

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
		cout << " " << p->hand[i].suit << " " << p->hand[i].value << endl;

	}

}

void delPlay(Player *p){

	delete p->name;
	delete p->hand;
	delete p;

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

void deckDat(Deck *d){

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

	//Index and Cards are pointer arrays inside of the structure
	temp->index = new int[temp->size];
	temp->cards = new Card[temp->size];

	file.read(reinterpret_cast<char *>(temp->index), temp->size * sizeof(int));
	file.read(reinterpret_cast<char *>(temp->cards), temp->size * sizeof(Card));
	
	return temp;

}

void shuffle(Deck *d){

	//Input number of times to shuffle the deck
	int nShufle;
	cout << "How many times would you like to shuffle the deck?" << endl;
	cin >> nShufle;

	//Shuffle the deck
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