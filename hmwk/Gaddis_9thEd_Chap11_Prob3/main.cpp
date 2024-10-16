/* 
 * File:   division_sales.cpp
 * Author: Ireoluwa
 * Created on October 7, 2024, 12:00 PM
 * Purpose:  Calculate total and average quarterly sales for each division.
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Structure to store division sales data
struct Div {
    string name;
    float firstQ, secQtr, thirdQ, fourQ, totSale, avgSale;
};

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    Div east = {"East"}, west = {"West"}, north = {"North"}, south = {"South"};
    
    //Process or map Inputs to Outputs
    Div divs[4] = {north, west, east, south}; // Change order to match expected output
    
    //Loop to input sales data for each division
    for (int i = 0; i < 4; i++) {
        cout << divs[i].name << endl;
        cout << "Enter first-quarter sales:" << endl;
        cin >> divs[i].firstQ;
        cout << "Enter second-quarter sales:" << endl;
        cin >> divs[i].secQtr;
        cout << "Enter third-quarter sales:" << endl;
        cin >> divs[i].thirdQ;
        cout << "Enter fourth-quarter sales:" << endl;
        cin >> divs[i].fourQ;
        
        //Calculate total and average sales for the division
        divs[i].totSale = divs[i].firstQ + divs[i].secQtr + divs[i].thirdQ + divs[i].fourQ;
        divs[i].avgSale = divs[i].totSale / 4;
        
        //Display total and average sales
        cout << "Total Annual sales:$" << fixed << setprecision(2) << divs[i].totSale << endl;
        
        //print endl except for South division
        cout << "Average Quarterly Sales:$" << divs[i].avgSale;
        if (divs[i].name != "South") {
            cout << endl;
        }
    }

    //Exit stage right!
    return 0;
}