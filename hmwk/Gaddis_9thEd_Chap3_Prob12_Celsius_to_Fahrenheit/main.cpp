/*
 * Author: Ireoluwa
 * Created on August 25, 2024, 5:00 AM 
 * Purpose: Celsius to Fahrenheit Temperature Conversion
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//Function Prototypes

//Execution Begins here
int main(int argc, char** argv) {
    //Declaring Variables
    float cels,       // Input -> Temperature in Celsius
          fahr;       // Output -> Temperature in Fahrenheit
    
    //Initialize Variables
    cout << "Enter temperature in Celsius: ";
    cin >> cels;
    
    //Processing/Mapping Inputs to Outputs
    fahr = cels * 9.0f / 5.0f + 32.0f;  // Convert Celsius to Fahrenheit
    
    //Displaying Input/Output Information
    cout << fixed << setprecision(2);  // Format the output to 2 decimal places
    cout << "Temp in Celsius: " << setw(6) << cels << "°C" << endl;
    cout << "Temp in Fahrenheit: " << setw(6) << fahr << "°F" << endl;
    
    //Exiting stage left
    return 0;
}
