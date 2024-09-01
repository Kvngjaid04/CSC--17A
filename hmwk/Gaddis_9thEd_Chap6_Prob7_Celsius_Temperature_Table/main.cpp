/*
 * Author: Ireoluwa
 * Created on August 25, 2024, 12:19 PM
 * Purpose: Convert Fahrenheit to Celsius and display a table
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - Mathematical, Scientific, Conversions

//Higher Dimensions go here. No Variables

//Function Prototypes
float celsius(float fahr); // Function to convert Fahrenheit to Celsius

//Execution Begins here
float celsius(float fahr) {
    return (fahr - 32) * 5.0f / 9.0f; // Convert Fahrenheit to Celsius
}

int main() {
    //Setting the random number seed
    
    //Declaring Variables
    float cels;   // Celsius temperature
    int fahr;     // Fahrenheit temperature
    
    //Initialize Variables
    cout << fixed << setprecision(2);  // Format the output to 2 decimal places
    
    //Displaying Input/Output Information
    cout << setw(15) << "Fahrenheit" << setw(15) << "Celsius" << endl;
    cout << "--------------------------" << endl;
    
    //Processing/Mapping Inputs to Outputs
    for (fahr = 0; fahr <= 20; ++fahr) {
        cels = celsius(fahr); // Call the celsius function
        cout << setw(15) << fahr << setw(15) << cels << endl;
    }
    
    //Exiting stage left/right
    return 0;
}
