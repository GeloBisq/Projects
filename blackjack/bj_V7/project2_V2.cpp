/*
Name: Angelo Bisquera
Date: 06/01/25
Purpose: Project 2 - Blackjack - Version 2
*/

//System Libraries

//User Libraries
#include "Deck.cpp"

//Global Constants
//Only use Scientific Values like PI, Speed of Light, etc.
//Conversion between units

//Function Prototypes

int main(int argv,char **argc){
	//Random Seeds are set for the random number generators
	srand(static_cast<unsigned int>(time(0)));

	//Declare Variables
	Deck *deck = new Deck;

	//Initialize Values

	//Map the Inputs to Outputs - Process
	deck->shoDeck();
	cout << endl;
	deck->shuffle();

	//Display and output the results
	cout << endl;
	deck->shoDeck();

	//Deallocate Memory
	delete deck;

	//Exit the program
	return 0;
	
}
