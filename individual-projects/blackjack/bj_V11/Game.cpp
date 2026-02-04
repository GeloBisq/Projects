/*
Name: Angelo Bisquera
Date: 06/15/25
Purpose: Game Class Implementation
*/

#include "Game.h"
using namespace std;

template <class T>
Game<T>::~Game(){

	delete winner;
	delete pTotal;
	delete dTotal;

}

template <class T>
void Game<T>::savRslt(char winner, T pTotal, T dTotal){

    this->winner[nGames - 1] = winner;
    this->pTotal[nGames - 1] = pTotal;
    this->dTotal[nGames - 1] = dTotal;

}

template <class T>
void Game<T>::shoRslt(){

    cout << "Winner  | Player Total  | Dealer Total" << endl;
	for(int i = 0; i < nGames; i++){

		cout << winner[i];
		cout << setw(9) << "" << pTotal[i];
		if(pTotal[i] > 9) cout << setw(14) << "" << dTotal[i] << endl;
		else cout << setw(15) << "" << dTotal[i] << endl;
	}
	cout << endl;

}

template <class T>
void Game<T>::wrtInfo(){

	fstream f;
	f.open("gameInfo.bin", ios::in|ios::out|ios::binary);
	f.seekp(0);
	f.write(reinterpret_cast<char *>(&nGames), sizeof(int));
	f.write(reinterpret_cast<char *>(winner), nGames * sizeof(char));
	f.write(reinterpret_cast<char *>(pTotal), nGames * sizeof(int));
	f.write(reinterpret_cast<char *>(dTotal), nGames * sizeof(int));
	f.close();

}

template <class T>
void Game<T>::rdInfo(){

	fstream f;

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
		cout << setw(9) << "";
		cout << pTotal[i];
		if(pTotal[i] > 9) cout << setw(14) << "" << dTotal[i] << endl;
		else cout << setw(15) << "" << dTotal[i] << endl;
	}

	delete nGames;
	delete winner;
	delete pTotal;
	delete dTotal;

}