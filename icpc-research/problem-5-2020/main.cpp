//system libraries
#include <iostream>  //input/output library
#include <fstream>
#include <vector>
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
    
    //declare variables
    ifstream infile;
    infile.open("inputs.txt");

    float tf, tr;
    vector<float> speeds;

    //initialize variables
    infile >> tf >> tr;
    speeds.push_back(0);
    do
    {
        float s;
        infile >> s;
        

        int min = floor(s); // i
        int max = min + 1;  // j
        int output = 0;

        if(min < s && s < min + tf)
            output = min;
        else if(min + tr < s && s < max)
            output = max;
        else if(min + tf < s && s < min + tr)
        {
            float target;
            for (int i=0; i<speeds.size(); i++)
            {
                if (speeds[i] < min+tf || speeds[i] > min+tr)
                {
                    target = speeds[i];
                    break;
                }
            }
            if (target < min+tr)
                output = min;
            else
                output = max;
        }
        else if(0 < s && s < 1)
            output = 1;

        //if the car is moving, min speed is 1
        if (speeds.size() > 1 && output < 1)
            output = 1;
    
        cout << output << endl;
        speeds.push_back(s);
    } while (!infile.eof());
    

    //map/process the inputs -> outputs

    //display input/outputs

    //clean up memory, close files

    //exit the program
    return 0;
}