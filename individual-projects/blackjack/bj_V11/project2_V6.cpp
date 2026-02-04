/*
Name: Angelo Bisquera
Date: 06/15/25
Purpose: Project 2 - Blackjack - Version 6
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
	char choice;
	string name;
	Dealer dealer;
	Game<int> game;

	//Initialize Values
	cout << endl;
	cout << setw(5) << "";
	cout << "Enter the player's name";
	cout << endl;
	cout << setw(5) << "";
	cin.ignore();
	getline(cin, name);
	Player player(name);

	//Start the Game
    do{
		
		//Display the menu
		cout << endl;
		cout << setw(5) << "";
		cout << "Type 1 to Play Blackjack";
		cout << endl;
		cout << setw(5) << "";
		cout << "Type 2 to View Your Points";
		cout << endl;
		cout << setw(5) << "";
		cout << "Type 3 to View the Results of Previous Games";
		cout << endl;
		cout << setw(5) << "";
		cin >> choice;

		// Player cannot play again if point balance is zero
		while(player.getPts() == 0.0 && choice == '1'){
			
			cout << endl << setw(5) << "";
			cout << "You have no points left to wager";
			cout << endl;
			cout << setw(5) << "";
			cout << "Pick another option";
			cout << endl;
			cout << setw(5) << "";
			cin >> choice;
		
		}

		switch(choice){
			
			case '1' : {
				
				//New Game
				game.newGame();

				//Shuffle the deck
				int nShufle;
				cout << endl;
				cout << setw(5) << "";
				cout << "How many times would you like to shuffle the deck?";
				cout << endl;
				cout << setw(5) << "";
				cin >> nShufle;
				for(int i = 0; i < nShufle; i++) !game;

				//Choose amount to wager
				float temp;
				cout << endl;
				cout << setw(5) << "";
				cout << "Enter an amount to wager";
				cout << endl;
				cout << setw(5) << "";
				cin >> temp;
				player.setWage(temp);

				//Deal intial hands
				player + game;
				dealer + game;
				player + game;
				dealer + game;

				//Check for blackjack
				if(player.hasBJ()){
					
					//If the dealer has a blackjack, the result is a push
					//Otherwise, the player wins
					if(dealer.hasBJ()){

						//Output the Game's Results
						cout << endl << "PUSH!" << endl;
						game.savRslt('T', player.getTotl(), dealer.getTotl());
						cout << endl;
						player.blckJck();
						cout << endl;
						dealer.blckJck();
						cout << endl;

						//Write the Game Results Out to a File
						game.wrtInfo();

					} else {

						//Output the Game's Results
						cout << endl << "BLACKJACK!" << endl;
						game.savRslt('P', player.getTotl(), dealer.getTotl());
						player.setPts("Player", player.hasBJ());
						cout << endl;
						player.blckJck();
						cout << endl;
						dealer.shoHand();
						cout << endl;

						//Write the Game Results Out to a File
						game.wrtInfo();

					}

				} else {
					
					//If the player does not have a blackjack, they draw
					//If they bust they lose, otherwise the dealer draws
					cout << endl;
					player.shoHand();
					cout << endl;
					dealer.frstHnd();
					cout << endl;
					unsigned char hOrS;
					cout << setw(5) << "";
					cout << "Would you like to hit or stand? (H/S)";
					cout << endl;
					cout << setw(5) << "";
					cin >> hOrS;
					cout << endl;
					while((hOrS == 'H' || hOrS == 'h') && player.getTotl() <= 21){

						//Deal a Card to the Player
						player + game;
						//If the Player's Total is less than or equal to 21
						//Then the user is prompted to hit or stand
						if(player.getTotl() < 21){

							player.shoHand();
							cout << endl;
							cout << setw(5) << "";
							cout << "Would you like to hit or stand? (H/S)";
							cout << endl;
							cout << setw(5) << "";
							cin >> hOrS;
							cout << endl;

						}

					}
					if(player.getTotl() > 21){

						//Output the Game's Results
						cout << "BUSTED!" << endl;
						game.savRslt('D', player.getTotl(), dealer.getTotl());
						player.setPts("Dealer", dealer.hasBJ());
						cout << endl;
						player.shoHand();
						cout << endl;
						dealer.shoHand();
						cout << endl;

						//Write the Game Results Out to a File
						game.wrtInfo();

					} else {

						//Deal Cards to the Dealer and stands on 17
						while(dealer.getTotl() <= 17) dealer + game;
						if(player.getTotl() == dealer.getTotl()){

							//Output the Game's Results
							cout << "PUSH!" << endl;
							game.savRslt('T', player.getTotl(), dealer.getTotl());
							cout << endl;
							player.shoHand();
							cout << endl;
							dealer.shoHand();
							cout << endl;

							//Write the Game Results Out to a File
							game.wrtInfo();

						} else if(player.getTotl() > dealer.getTotl() || dealer.getTotl() > 21){

							//Output the Game's Results
							cout << "YOU WIN!" << endl;
							player.setPts("Player", player.hasBJ());
							game.savRslt('P', player.getTotl(), dealer.getTotl());
							cout << endl;
							player.shoHand();
							cout << endl;
							dealer.shoHand();
							cout << endl;

							//Write the Game Results Out to a File
							game.wrtInfo();

						} else {

							//Output the Game's Results
							cout << "YOU LOSE!" << endl;
							player.setPts("Dealer", dealer.hasBJ());
							game.savRslt('D', player.getTotl(), dealer.getTotl());
							cout << endl;
							player.shoHand();
							cout << endl;
							dealer.shoHand();
							cout << endl;

							//Write the Game Results Out to a File
							game.wrtInfo();

						}

					}

				}

				//Reset values before next game
				player.newGame();
				dealer.newGame();
			
			break;}
			
			case '2' : {
				
				cout << endl;
				cout << "Point Balance: ";
				cout << fixed << showpoint << setprecision(2);
				cout << player.getPts();
				cout << endl;
				
			break;}	
			
			case '3' : {
				
				cout << endl;
				if(game.getGame() == 0) cout << "No previous game results" << endl;
				else game.shoRslt();
			
			break;}

			default : cout << endl << "Exiting Game" << endl; break;
			
		}

	}while(choice >= '1' && choice <= '3');

	//Exit the program
	return 0;
	
}