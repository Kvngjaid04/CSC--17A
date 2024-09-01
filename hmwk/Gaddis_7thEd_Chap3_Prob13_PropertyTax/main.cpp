/*
 * Author: Ireoluwa
 * Created on August 29, 2024, 1:20 PM
 * Purpose: Property Tax Calculator
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Function Prototypes

//Execution Begins here
int main(int argc, char** argv) {
    //Declaring Variables
    float actVal,   // Input -> Actual value of the property
          assVal,   // Output -> Assessment value (60% of actual value)
          taxDue;   // Output -> Property tax
    
    //Initialize Variables
    cout << "Enter the actual value of the property: $";
    cin >> actVal;
    
    //Processing/Mapping Inputs to Outputs
    assVal = actVal * 0.60f;      // Calculate assessment value (60% of actual value)
    taxDue = (assVal / 100) * 0.64f; // Calculate property tax ($0.64 per $100 of assessment value)
            
    //Displaying Input/Output Information
    cout << fixed << setprecision(2);  // Format the output to 2 decimal places
    cout << "Assessment value: $" << setw(10) << assVal << endl;
    cout << "Property tax:     $" << setw(10) << taxDue << endl;
    
    //Exiting stage left
    return 0;
}
