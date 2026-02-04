/*
Name: Angelo Bisquera
Date: 06/01/25
Purpose: Project 2 - Blackjack - Version 5
*/

//System Libraries

//User Libraries
#include "Player.cpp"

//Global Constants
//Only use Scientific Values like PI, Speed of Light, etc.
//Conversion between units

//Function Prototypes

int main(int argv,char **argc){
	//Random Seeds are set for the random number generators
	srand(static_cast<unsigned int>(time(0)));

	//Declare Variables
	string name;
	Dealer dealer;
	Game g;

	//Initialize Values
	cout << "Enter the player's name" << endl;
	cin.ignore();
	getline(cin, name);
	Player player(name);

	//Map the Inputs to Outputs - Process
	//Shuffle the deck
	!g;
	//Output the deck
	&g;

	//Draw cards
	player + g;
	dealer + g;
	player + g;
	dealer + g;

	//Display and output the results
	cout << endl;
	player.getPlyr();

	cout << endl;
	player.shoData();
	player.shoHand();

	cout << endl;
	dealer.shoData();
	dealer.shoHand();

	//Deallocate Memory

	//Exit the program
	return 0;
	
}
