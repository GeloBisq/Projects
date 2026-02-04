//system libraries
#include <iostream>  //input/output library
#include <cmath>
using namespace std; //using namespace standard

//user libraries

//global constants not variable
//science, math, conversion, dimension

//function prototypes

//execution begins here at main
int main( int argc, char **argv ) 
{
    //set random number seed
    srand(static_cast<unsigned int>(time(0)));

    //hard coded inputs
    int inputInts[] = {1433, 1433, 2000, 600};
    float inputFlts[] = {0.09, 0.12, 0.09, 0.12};
    //if we weren't hard coding, we'd have to read while !eof
    
    int rows = 4;
    for (int i=0; i<rows; i++)
    {
        int r = inputInts[i];
        float s = inputFlts[i] + 0.16; //addend from formula
        float denom = 0.067;

        float v = sqrt((r * s) / denom);

        float half = 0.005;
        int out = round(v);

        cout << out << endl;
    }

    //exit the program
    return 0;
}