/*
 * Author: Ireoluwa
 * Created on October 21, 2024, 1:00 PM
 * Purpose: Corporate Sales Data Output
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Structure to hold division sales data
struct Div {
    string name;
    int qtr;
    float sales;
};

// Function prototypes
void getData(Div&, int);
void wrteFle(ofstream&, Div);

// Execution begins here
int main() {
    // Declaring variables
    Div east, west, north, south;
    ofstream file("sales.txt");

    // Initialize division names
    east.name = "East";
    west.name = "West";
    north.name = "North";
    south.name = "South";

    // Getting sales data for each division
    for (int q = 1; q <= 4; q++) {
        getData(east, q);
        getData(west, q);
        getData(north, q);
        getData(south, q);
    }

    // Writing data to file
    for (int q = 1; q <= 4; q++) {
        wrteFle(file, east);
        wrteFle(file, west);
        wrteFle(file, north);
        wrteFle(file, south);
    }

    // Close the file
    file.close();
    
    cout << "Sales data has been written to sales.txt." << endl;
    
    return 0;
}

// Function to get sales data for a specific division and quarter
void getData(Div& div, int qtr) {
    div.qtr = qtr;
    do {
        cout << "Enter sales for " << div.name << " Division, Quarter " << qtr << ": ";
        cin >> div.sales;
        if (div.sales < 0) {
            cout << "Error: Sales cannot be negative." << endl;
        }
    } while (div.sales < 0);
}

// Function to write division sales data to a file
void wrteFle(ofstream& file, Div div) {
    file << "Division Name: " << div.name << endl;
    file << "Quarter: " << div.qtr << endl;
    file << "Quarterly Sales: $" << div.sales << endl;
  
}
