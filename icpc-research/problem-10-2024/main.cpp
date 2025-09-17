/* 
* Team Members: Angelo, Daniel, Cole
 * Date: 
 * Purpose: ICPC 2024 Probem 10
 */

//System Libraries Here
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Constants like PI, e, Gravity, Conversions, 2D array size only!

//Function Prototypes Here
void readIn(int, int[][8]);
void check(int, int[][8]);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number Seed Here
    
    //Declare all Variables Here
    int numTest;

    //Input or initialize values Here
	cin >> numTest;
    int candles[numTest][8];
    readIn(numTest, candles);

    //Process/Calculations Here
    check(numTest, candles);

    //Output Located Here	
	
    //Exit
    return 0;
}

void readIn(int numTest, int candles[][8]){

    for(int i = 0; i < numTest; i++){

        for(int j = 0; j < 8; j++){

            cin >> candles[i][j];

        }

    }

}

void check(int numTest, int candles[][8]){

    for(int i = 0; i < numTest; i++){

        bool canCut = true;

        for(int j = 0; j < 8; j++){

            for(int k = j + 2; k < 8; k+=2){

                if(candles[i][j] == candles[i][k]) canCut = false;

            }

        }

        if(canCut) cout << "Yes" << endl;
        else cout << "No" << endl;

    }

}