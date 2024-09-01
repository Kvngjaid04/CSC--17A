/*
 * Author: Ireoluwa
 * Created on August 30, 2024, 3:15 PM
 * Purpose: Calculate total cost with quantity discounts
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
    int   units;         // Input -> Number of units sold
    float cost = 99.0f, // Cost per unit
          totCost,      // Output -> Total cost after discount
          disc = 0.0f; // Discount rate
    
    // Ask for the number of units sold
     // Input Validation
    do {
        cout << "Enter the number of units sold: ";
        cin >> units;
        
        if (units <= 0) {
            cout << "Error: Number of units must be greater than 0." << endl;
        }
    } while (units <= 0);
    
    
    // Determine the discount rate based on the number of units
    if (units >= 100) {
        disc = 0.50f;
    } else if (units >= 50) {
        disc = 0.40f;
    } else if (units >= 20) {
        disc = 0.30f;
    } else if (units >= 10) {
        disc = 0.20f;
    }
    
    // Calculate the total cost after applying the discount
    totCost = units * cost * (1 - disc);
    
    // Display the total cost
    cout << fixed << setprecision(2); // Format output to 2 decimal places
    cout << "Total cost: $" << setw(8) << totCost << endl;
    
    // Exit program
    return 0;
}
