/* 
 * File:   
 * Author: Ireoluwa
 * Created on October 7th, 2024
 * Purpose: Process monthly weather data (rainfall and temperatures)
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions
const int MONTHS = 6; // Number of months to process

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    float tRain = 0;
    int hiTemp = -100; // Initialize to a very low value
    int loTemp = 140;  // Initialize to a very high value
    float tTemp = 0;

    //Initialize Variables

    //Process or map Inputs to Outputs
    for (int i = 0; i < MONTHS; i++) {
        float rain;
        int high, low;

        cout << "Enter the total rainfall for the month:" << endl;
        cin >> rain;
        tRain += rain;

        cout << "Enter the high temp:" << endl;
        cin >> high;
        if (high > hiTemp) {
            hiTemp = high;
        }

        cout << "Enter the low temp:" << endl;
        cin >> low;
        if (low < loTemp) {
            loTemp = low;
        }

        tTemp += high + low;
    }

    float aRain = tRain / MONTHS;
    float aTemp = tTemp / (MONTHS * 2); // Divide by 2 because we have two temps per month

    //Display Outputs
    cout << fixed << setprecision(2);
    cout << "Average monthly rainfall:" << aRain << endl;
    cout << "High Temp:" << hiTemp << endl;
    cout << "Low Temp:" << loTemp << endl;
    cout << "Average Temp:" << setprecision(1) << (aTemp);

    //Exit stage right!
    return 0;
}
