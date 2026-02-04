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
	Dealer *dealer = new Dealer;

	//Initialize Values
	cout << "Enter the player's name" << endl;
	getline(cin, name);
	Player *player = new Player(dealer);
	player->setName(name);

	//Map the Inputs to Outputs - Process
	
	//Display and output the results
	cout << endl;
	player->shoData();
	player->shoHand();

	cout << endl;
	dealer->shoData();
	dealer->shoHand();

	cout << endl;
	dealer->getPlyr();

	//Deallocate Memory
	delete dealer;
	delete player;

	//Exit the program
	return 0;
	
}
