/*
 * Author: Ireoluwa
 * Created on August 31, 2024, 2:30 PM
 * Purpose: Predict population growth over time
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    // Declare Variables
    int   startPop,    // Input -> Starting number of organisms
          days;        // Input -> Number of days they will multiply
    float avgInc,    // Input -> Average daily population increase (percentage)
          currPop;   // Current population size

    // Input Validation for Starting Population
    do {
        cout << "Enter the starting number of organisms : ";
        cin >> startPop;
        
        if (startPop < 2) {
            cout << "Error: Starting population must be at least 2." << endl;
        }
    } while (startPop < 2);

    // Input Validation for Average Daily Increase
    do {
        cout << "Enter the average daily population increase : ";
        cin >> avgInc;
        
        if (avgInc < 0) {
            cout << "Error: Average daily increase cannot be negative." << endl;
        }
    } while (avgInc < 0);

    // Input Validation for Number of Days
    do {
        cout << "Enter the number of days they will multiply : ";
        cin >> days;
        
        if (days < 1) {
            cout << "Error: Number of days must be at least 1." << endl;
        }
    } while (days < 1);

    // Initialize the current population to the starting population
    currPop = startPop;

    // Display the population size for each day
    cout << fixed << setprecision(2);  // Format output to 2 decimal places
    for (int day = 1; day <= days; day++) {
        cout << "Day " << setw(2) << day <<
                ": Population = " << setw(8) << currPop << endl;
        currPop += currPop * (avgInc / 100);  
    }
    
    // Exit program
    return 0;
}
