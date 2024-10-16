/*
 * Author: Ireoluwa
 * Created on October 7, 2024, 10:30 AM
 * Purpose: Soft Drink Machine Simulator
 */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Structure to hold drink data
struct Drink {
    string name;
    float cost; // Cost in dollars
    int qty;    // Quantity
};

// Function prototypes
void dsplyD(const Drink[], int);
int slctD(const Drink[], int&);
int insrtM();

int main() {
    // Declaring variables
    const int numD = 5;
    Drink drks[numD] = {
        {"Cola", 0.75, 20},
        {"Root Beer", 0.75, 20},
        {"Lemon-Lime", 0.75, 20},
        {"Grape Soda", 0.80, 20},
        {"Cream Soda", 0.80, 20}
    };
    float totEarn = 0; // Total earnings in dollars
    bool quit = false; // Quit flag

    // Main loop for the drink machine
    while (!quit) {
        dsplyD(drks, numD); // Display drinks
        int choice;
        quit = slctD(drks, choice); // Select drink

        if (!quit && drks[choice].qty == 0) {
            cout << "Sorry, " << drks[choice].name << " is sold out.\n";
        } else if (!quit) {
            int money = insrtM(); // Insert money
            if (money >= int(drks[choice].cost * 100)) { // Compare with cost in cents
                int chng = money - int(drks[choice].cost * 100); // Calculate change in cents
                cout<< chng << "\n"; // Output change
                drks[choice].qty--; // Decrease quantity
                totEarn += drks[choice].cost; // Accumulate total earnings
            } else {
                cout << "Insufficient amount. Returning money.\n"; // Not enough money
            }
        }
    }

    // Display total earnings before exiting
    cout << totEarn*100.0 << endl;

    return 0;
}

// Function to display available drinks
void dsplyD(const Drink drks[], int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(10) << left << drks[i].name << setw(3) << right << int(drks[i].cost * 100) 
             << "  " << drks[i].qty << endl; // Display drink details
    }
    cout << "Quit" << endl; // Option to quit
}

// Function to select a drink
int slctD(const Drink drks[], int& choice) {
    string sel;
    getline(cin, sel); // Get user selection
    
    for (int i = 0; i < 5; i++) {
        if (sel == drks[i].name) {
            choice = i; // Valid selection
            return false;
        }
    }
    
    if (sel == "Quit") {
        return true; // User chooses to quit
    } else {
        cout << "Invalid selection. Try again.\n"; // Invalid selection
        return slctD(drks, choice); // Recursive call if invalid
    }
}

// Function to get the amount of money inserted
int insrtM() {
    string money;
    getline(cin, money); // Get money input
    int val = stoi(money); // Convert input to integer
    
    if (val < 0 || val > 100) {
        cout << "Invalid amount. Please enter a value between 0 and 100 cents.\n";
        return insrtM(); // Recursively ask for valid input
    }
    return val; // Return value as it is, in cents
}
