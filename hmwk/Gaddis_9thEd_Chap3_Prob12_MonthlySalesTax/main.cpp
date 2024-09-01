/*
 * Author: Ireoluwa
 * Created on August 22, 2024, 1:20 PM
 * Purpose: Monthly Sales Tax Report
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - Mathematical, Scientific, Conversions
const unsigned char PERCENT = 100; //Percent Conversion

//Function Prototypes

//Execution Begins here
int main(int argc, char** argv) {
    //Declaring Variables
    string month;        // Input -> Month of the report
    int year;            // Input -> Year of the report
    float ttlCltd,// Input -> Total amount collected at the cash register
          sales,         // Output -> Product sales
          stteTax,      // Output -> State sales tax
          cntyTax,     // Output -> County sales tax
          ttalTax,    // Output -> Total sales tax
          STAXRTE = 4.0f / PERCENT,  // 4% state sales tax
          CNTTAXR = 2.0f / PERCENT, // 2% county sales tax
          TTLTAXR = STAXRTE + CNTTAXR; // Total 6% sales tax
    //Initialize Variables
    cout << "Enter the month: ";
    cin >> month;
    cout << "Enter the year: ";
    cin >> year;
    cout << "Enter the total amount collected: $";
    cin >> ttlCltd;
    
    //Processing/Mapping Inputs to Outputs
    sales = ttlCltd / (1 + TTLTAXR);  // Calculate product sales
    stteTax = sales * STAXRTE;              // Calculate state sales tax
    cntyTax = sales * CNTTAXR;            // Calculate county sales tax
    ttalTax = stteTax + cntyTax;                // Calculate total sales tax
            
    //Displaying Input/Output Information
    cout << fixed << setprecision(2) << setw(10);  // Format the output to 2 decimal places
    cout << "\nMonth: " << month << endl;
    cout << "--------------------" << endl;
    cout << "Total Collected:  $ " << ttlCltd << endl;
    cout << "Sales:            $ " << sales << endl;
    cout << "County Sales Tax: $ " << cntyTax << endl;
    cout << "State Sales Tax:  $ " << stteTax << endl;
    cout << "Total Sales Tax:  $ " << ttalTax << endl;
    
    //Exiting stage left
    return 0;
}
