//system libraries
#include <iostream>  //input/output library
#include <fstream>
#include <set>
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
    
    //get inputs from file or from line
    ifstream infile;
    infile.open("inputs.txt");

    //this test case should output "45 17"
    // int c = 10;
    // for (int i=0; i<c; i++)
    //     inputs.insert(i);

    int c = 0;

    //read number of inputs c
    infile >> c;
    set<int> inputs;
    set<int> sums;

    for (int i=0; i<c; i++)
    {
        int dum;
        infile >> dum;
        inputs.insert(dum);
    }
    
    int num = 1;
    int t = c;

    for (int i=0; i<2; i++)
    {
        num *= t--;
    }

    int nPairs = num / 2;
    cout << nPairs << " ";

    //get sums
    for (auto it = inputs.begin(); it != inputs.end(); it++)
    {
        int a = *it;
        for (auto it2 = inputs.begin(); it2 != inputs.end(); it2++)//inner iterator
        {
            int b = *it2;
            if (a != b)
                sums.insert(a + b);
        }
    }

    cout << sums.size();
    
    //clean up memory, close files
    infile.close();

    //exit the program
    return 0;
}