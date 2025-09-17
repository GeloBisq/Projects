/*
Name: Dan, Cole, Gelo
Date: 06/27/2025
Purpose: P11 Intuitive Elements
*/

//System Libraries
#include <iostream> 
#include <string> 
using namespace std;

//User Libraries

//Global Constants
//Only use Scientific Values like Pi, Speed of Light, etc...
//Conversion between units

//Function Prototypes
bool check();

int main(int argv, char **argc) {
    //Random Seeds are set for the random number generator

    //Declare Variables
    int cases;

    //Initialize Variables
    cin >> cases;
    for(int i = 0; i < cases; i++){
        if(check()) cout << "YES" << endl;
        else        cout << "NO" << endl; 
    }
    
    //Exit the program
    return 0;
}

bool check(){

    string a, b;
    cin >> a >> b; 
    bool found[b.length()]; 

    //Map the Inputs to Outputs - Process1
    for (int i = 0; i < b.length(); i++) {
        //check if letters in b are found in a
        found[i] = false;
        for(int j = 0; j < a.length(); j++){
            if(a[j] == b[i]) found[i] = true;
        }
        if(!found[i]) return false;
    }
    return true;

}