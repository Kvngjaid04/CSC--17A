/*
 * Author: Ireoluwa
 * Created on August 25, 2024 6:00 AM
 * Purpose: Convert USD to Japanese Yen and Euros
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

// Define conversion factors
const float YenPDlr = 83.14f;   // Conversion rate from USD to Yen
const float EurPDlr = 0.7337f; // Conversion rate from USD to Euros

//Function Prototypes

//Execution Begins here
int main(int argc, char** argv) {
    //Declaring Variables
    float usd,         // Input -> Amount in US Dollars
          yenAmt,      // Output -> Amount in Japanese Yen
          euroAmt;     // Output -> Amount in Euros
    
    //Initialize Variables
    cout << "Enter amount in US Dollars: $";
    cin >> usd;
    
    //Processing/Mapping Inputs to Outputs
    yenAmt = usd * YenPDlr;   // Convert USD to Yen
    euroAmt = usd * EurPDlr; // Convert USD to Euros
    
    //Displaying Input/Output Information
    cout << fixed << setprecision(2);  // Format the output to 2 decimal places
    cout << "Amount in Japanese Yen: ¥" << setw(10) << yenAmt << endl;
    cout << "Amount in Euros: €" << setw(10) << euroAmt << endl;
    
    //Exiting stage left
    return 0;
}
