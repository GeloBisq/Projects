/*
Name: Angelo Bisquera
Date: 05/11/25
Purpose: Blackjack - Version 5
*/

//System Libraries
#include <iostream> //I/O Library
#include <iomanip>  //Format Library
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

	char suit; //Suit of the card
	Face face; //Face of the card
	int value; //Value of the card

};

struct Deck{

	Card *cards; //Array of cards
	int *index;	 //Array of indices, used for shuffling
	int size,	 //Size of the cards array, dependent on the number of decks
		nDecks;  //Number of decks used

};

struct Player{

	char *name;
	Card *hand;				   //Player's hand
	float points = 1000.00;    //Player starts with $1000.00
	int total = 0;			   //Total of their hand, will be reset each game
	int nCards = 0;			   //Number of cards in their hand, will be reset each game

};

struct Game{

	int nGames = 0;				  //Number of games
	char *winner = new char[100]; //Stores the winner of each game
	int *pTotal  = new int[100];  //Stores the player's score from each game
	int *dTotal  = new int[100];  //Stores the dealer's score from each game

};

//Function Prototypes
void setWagr(Player *, float &);  //Set the player's wager
Player *genPlay();				  //Generate the player, prompts for a name
Player *genDeal();				  //Generate the dealer, has no prompts
void deal(Player *, Deck *);      //Deals a card to the player structure
void pDeal(Player *, Deck *);	  //Deals to the player, prompts for a hit and stand
void dDeal(Player *, Deck *);     //Deals to the dealer, stops on 17
void handDat(Player *);			  //Outputs the hand stored in the player structure
void blckJck(Player *);			  //Outputs the player's hand if they have a blackjack
void frstHnd(Player *);			  //Specifically for the dealer on the first turn, only reveals one of the dealer's cards
bool hasBJ(Player *);			  //Checks to see if the hands forms a blackjack
void delPlay(Player *);			  //Deletes the player structure
Deck *genDeck();				  //Generates a deck structure, prompting for the number of decks  
void deckDat(Deck *);			  //Outputs the data stored in the deck structure
void wrtDeck(Deck *, fstream &);  //Writes the cards in the deck out to a binary file
void shuffle(Deck *);			  //Shuffles the deck
void delDeck(Deck *);			  //Deletes the deck structure
void wrtInfo(Game *, fstream &);  //Writes the info from all games out to a binary file
void rdInfo(fstream &);			  //Reads the info on all the games from a binary file
void delGame(Game *);			  //Deletes the game structure


int main(int argv,char **argc){
	//Random Seeds are set for the random number generators
	srand(static_cast<unsigned int>(time(0)));

	//Start Menu
	//Generate player and dealer
	char choice;
	fstream f;
	fstream g;
	Game *game = new Game;
	Player *p = genPlay();
	Player *d = genDeal();
	cout << endl << setw(10) << "" << "Blackjack" << endl << endl;
	do{
		
		//Display the menu
		cout << setw(5) << "" << "Type 1 to Play Blackjack" << endl;
		cout << setw(5) << "" << "Type 2 to View Your Points" << endl;
		cout << setw(5) << "" << "Type 3 to View the Results of Previous Games" << endl;
		cout << setw(5) << "";
		cin >> choice;

		// Player cannot play again if point balance is zero
		while(p->points == 0.0 && choice == '1'){
			
			cout << endl << setw(5) << "" << "You have no points left to wager" << endl;
			cout << setw(5) << "" << "Pick another option" << endl;
			cout << setw(5) << "";
			cin >> choice;
		
		}

		switch(choice){
			
			case '1' : {
				
				// Set or reset to default values
				cout << endl;
				Deck *deck = genDeck();
				p->hand = new Card[10]; //Can hold a maximum of 10 cards
				d->hand = new Card[10];
				shuffle(deck);
				wrtDeck(deck, f);

				//Choose amount to wager
				float wager;
				setWagr(p, wager);

				//Deal and display initial hand
				deal(p, deck);
				deal(p, deck);
				deal(d, deck);
				deal(d, deck);

				//Check for blackjack
				if(hasBJ(p)){
					
					//If the dealer has a blackjack, the result is a push
					//Otherwise, the player wins
					if(hasBJ(d)){

						cout << endl << "PUSH!" << endl;
						game->pTotal[game->nGames] = p->total;
						game->dTotal[game->nGames] = d->total;
						game->winner[game->nGames] = 'T';
						cout << endl;
						blckJck(p);
						cout << endl;
						blckJck(d);
						cout << endl;

					} else {

						cout << endl << "BLACKJACK!" << endl;
						game->pTotal[game->nGames] = p->total;
						game->dTotal[game->nGames] = d->total;
						game->winner[game->nGames] = 'P';
						p->points += wager * 1.5f;
						cout << endl;
						blckJck(p);
						cout << endl;
						handDat(d);
						cout << endl;

					}

				} else {
					
					//If the player does not have a blackjack, they draw
					//If they bust they lose, otherwise the dealer draws
					cout << endl;
					handDat(p);
					cout << endl;
					frstHnd(d);
					cout << endl;
					pDeal(p, deck);
					if(p->total > 21){

						cout << "BUSTED!" << endl;
						game->pTotal[game->nGames] = p->total;
						game->dTotal[game->nGames] = d->total;
						game->winner[game->nGames] = 'D';
						p->points -= wager;
						cout << endl;
						handDat(p);
						cout << endl;
						handDat(d);
						cout << endl;

					} else {

						dDeal(d, deck);
						if(p->total == d->total){

							cout << "PUSH!" << endl;
							game->pTotal[game->nGames] = p->total;
							game->dTotal[game->nGames] = d->total;
							game->winner[game->nGames] = 'T';
							cout << endl;
							handDat(p);
							cout << endl;
							handDat(d);
							cout << endl;

						}
						else if(p->total > d->total || d->total > 21){

							cout << "YOU WIN!" << endl;
							p->points += wager;
							game->pTotal[game->nGames] = p->total;
							game->dTotal[game->nGames] = d->total;
							game->winner[game->nGames] = 'P';
							cout << endl;
							handDat(p);
							cout << endl;
							handDat(d);
							cout << endl;

						} else {

							cout << "YOU LOSE!" << endl;
							p->points -= wager;
							game->pTotal[game->nGames] = p->total;
							game->dTotal[game->nGames] = d->total;
							game->winner[game->nGames] = 'D';
							cout << endl;
							handDat(p);
							cout << endl;
							handDat(d);
							cout << endl;

						}

					}

				}

				//Reset values before next game
				delete p->hand;
				p->total = 0;
				p->nCards = 0;
				delete d->hand;
				d->total = 0;
				d->nCards = 0;
				game->nGames++;

				//Write out game info
				cout << endl;
				wrtInfo(game, f);

				//Delete deck
				delDeck(deck);
			
			break;}
			
			case '2' : {
				
				cout << endl << "Point Balance: " << fixed << showpoint << setprecision(2) << p->points << endl << endl;
				
			break;}	
			
			case '3' : {
				
				cout << endl;
				if(game->nGames == 0) cout << "No previous game results" << endl << endl;
				else rdInfo(g);
			
			break;}

			default : cout << endl << "Exiting Game" << endl; break;
			
		}

	}while(choice >= '1' && choice <= '3');

	//Deallocate Memory
	delPlay(d);
	delPlay(p);
	delGame(game);

	//Exit the program
	return 0;
	
}

void setWagr(Player *p, float &wager){

	cout << "How many points would you like to wager?" << endl;
	cin >> wager;
	while(wager > p->points || wager <= 0){

		cout << endl << endl << setw(5) << "" << "Invalid Amount of Points" << endl;
		cout << setw(5) << "" << "Pick a new amount" << endl;
		cout << setw(5) << "";
		cin >> wager;

	}

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

void pDeal(Player *p, Deck *d){

	unsigned char hOrS;
	cout << "Would you like to hit or stand? (H/S)" << endl;
	cin >> hOrS;
	cout << endl;
	while((hOrS == 'H' || hOrS == 'h') && p->total <= 21){

		deal(p, d);
		if(p->total < 21){

			handDat(p);
			cout << endl << "Would you like to hit or stand? (H/S)" << endl;
			cin >> hOrS;
			cout << endl;

		}

	}

}

void dDeal(Player *d, Deck *deck){

	while(d->total < 17){

		deal(d, deck);

	}

}

void handDat(Player *p){

	cout << p->name << "'s Hand" << endl;
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

void blckJck(Player *p){

	cout << p->name << "'s Hand" << endl;
	cout << "Total: 21" << endl;
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
		cout << " " << p->hand[i].suit << " ";
		if(p->hand[i].value == 1) cout << 11 << endl;
		else cout << p->hand[i].value << endl;

	}

}

void frstHnd(Player *p){

	cout << p->name << "'s Hand" << endl;
	cout << "Total: ??" << endl;
	cout << "Cards: " << endl;
	switch(p->hand[0].face){

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
	cout << " " << p->hand[0].suit << " " << p->hand[0].value << endl;
	cout << "??" << endl;

}

bool hasBJ(Player *p){

	bool bj = false;
	if((p->hand[0].value == 1 && p->hand[1].value == 10) || (p->hand[1].value == 1 && p->hand[0].value == 10)){

		bj = true;

	}

	return bj;

}

void delPlay(Player *p){

	delete p->name;
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

void wrtDeck(Deck *d, fstream &file){

	file.open("deck.txt", ios::in|ios::out);
	file.seekp(0);
	for(int i = 0; i < d->size; i++){

		file << setw(5) << "" << d->index[i] << " ";
		switch(d->cards[i].face){

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
		file << " " << d->cards[i].suit << " " << d->cards[i].value << endl; 

	}
	file.close();

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

void wrtInfo(Game *g, fstream &f){

	f.open("gameInfo.bin", ios::in|ios::out|ios::binary);
	f.seekp(0);
	f.write(reinterpret_cast<char *>(&g->nGames), sizeof(int));
	f.write(reinterpret_cast<char *>(g->winner), g->nGames * sizeof(char));
	f.write(reinterpret_cast<char *>(g->pTotal), g->nGames * sizeof(int));
	f.write(reinterpret_cast<char *>(g->dTotal), g->nGames * sizeof(int));
	f.close();

}

void rdInfo(fstream &f){

	f.open("gameInfo.bin", ios::in|ios::out|ios::binary);
	f.seekg(0);
	
	int *nGames = new int;
	f.read(reinterpret_cast<char *>(&nGames), sizeof(int));

	char *winner = new char[*nGames];
	int *pTotal  = new int[*nGames];
	int *dTotal  = new int[*nGames];

	f.read(reinterpret_cast<char *>(winner), *nGames * sizeof(char));
	f.read(reinterpret_cast<char *>(pTotal), *nGames * sizeof(int));
	f.read(reinterpret_cast<char *>(dTotal), *nGames * sizeof(int));

	f.close();

	cout << "Winner  | Player Total  | Dealer Total" << endl;
	for(int i = 0; i < *nGames; i++){

		cout << winner[i];
		cout << setw(9) << "" << pTotal[i];
		if(pTotal[i] > 9) cout << setw(14) << "" << dTotal[i] << endl;
		else cout << setw(15) << "" << dTotal[i] << endl;
	}
	cout << endl;

}

void delGame(Game *g){

	delete g->winner;
	delete g->pTotal;
	delete g->dTotal;
	delete g;

}