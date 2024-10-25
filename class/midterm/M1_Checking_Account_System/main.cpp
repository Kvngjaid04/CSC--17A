/*
 * Author: Ireoluwa
 * Created on October 24, 2024
 * Purpose: Manage customer checking accounts
 */

// System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// User Libraries
struct Cstmr {             // Structure for Customer
    int accNum;            // Account number
    string name;           // Customer name
    string addr;           // Customer address
    float bal;             // Balance
    float* chks;           // Dynamic array for checks
    int numChks;           // Number of checks written
    float* deps;           // Dynamic array for deposits
    int numDeps;           // Number of deposits credited
};

// Function Prototypes
void inptCtm(Cstmr& c);
void inptChk(Cstmr& c);
void inptDps(Cstmr& c);
void calcBal(Cstmr& c);
void dspyCtm(const Cstmr& c);
void cleanUp(Cstmr& c);

// Execution Begins here
int main() {
    Cstmr customer; // Customer structure

    // Input customer data
    inptCtm(customer);
    
    // Input checks
    inptChk(customer);
    
    // Input deposits
    inptDps(customer);
    
    // Calculate the new balance
    calcBal(customer);
    
    // Display the customer data
    dspyCtm(customer);
    
    // Clean up dynamically allocated memory
    cleanUp(customer);
    
    return 0;
}

// Input customer data
void inptCtm(Cstmr& c) {
    do {
        cout << "Enter account number: ";
        cin >> c.accNum;
    } while (c.accNum < 10000 || c.accNum > 99999); // Validate 5 digits

    cin.ignore(); // Clear the newline character 
    cout << "Enter name: ";
    getline(cin, c.name);
    
    cout << "Enter address: ";
    getline(cin, c.addr);
    
    cout << "Enter balance at the beginning of the month: $";
    cin >> c.bal;

    c.numChks = 0;
    c.numDeps = 0;
    c.chks = nullptr;
    c.deps = nullptr;
}

// Input checks written
void inptChk(Cstmr& c) {
    float chk;
    
    do {
        cout << "Enter check amount written (enter a negative amount to stop): $";
        cin >> chk;
        if (chk >= 0) {
            // Increase the size of the dynamic array
            float* temp = new float[c.numChks + 1];
            for (int i = 0; i < c.numChks; i++) {
                temp[i] = c.chks[i];
            }
            temp[c.numChks] = chk; 
            delete[] c.chks;
            c.chks = temp; 
            c.numChks++; 
        }
    } while (chk >= 0);
}

// Input deposits credited
void inptDps(Cstmr& c) {
    float dep;
    
    do {
        cout << "Enter deposit amount (enter a negative amount to stop): ";
        cin >> dep;
        if (dep >= 0) {
            // Increase the size of the dynamic array
            float* temp = new float[c.numDeps + 1];
            for (int i = 0; i < c.numDeps; i++) {
                temp[i] = c.deps[i];
            }
            temp[c.numDeps] = dep;
            delete[] c.deps;
            c.deps = temp; 
            c.numDeps++; 
        }
    } while (dep >= 0);
}

// Calculate the new balance
void calcBal(Cstmr& c) {
    float totalChks = 0;
    float totalDeps = 0;

    // Calculate total checks written
    for (int i = 0; i < c.numChks; i++) {
        totalChks += c.chks[i];
    }
    
    // Calculate total deposits credited
    for (int i = 0; i < c.numDeps; i++) {
        totalDeps += c.deps[i];
    }

    // Calculate new balance
    c.bal = c.bal + totalDeps - totalChks;

    // Check for overdraft
    if (c.bal < 0) {
        cout << endl << "Overdraft! Your balance is negative." << endl;
        c.bal -= 35; // Apply $35 overdraft fee
        cout << "An additional $35 fee has been applied." << endl;
        cout << "New balance with fee included: $" << 
                fixed << setprecision(2) << c.bal << endl;
    } else {
        cout << endl << "Your new balance is: $" << fixed 
             << setprecision(2) << c.bal << endl;
    }
}

// Display customer data
void dspyCtm(const Cstmr& c) {
    cout << "\n--- Customer Information ---" << endl;
    cout << "Account Number: " << c.accNum << endl;
    cout << "Name: " << c.name << endl;
    cout << "Address: " << c.addr << endl;
    cout << "Balance: $" << fixed << setprecision(2) << c.bal << endl;

    // Display checks
    cout << "Checks Written: ";
    for (int i = 0; i < c.numChks; i++) {
        cout << "$" << fixed << setprecision(2) << c.chks[i] << " ";
    }
    cout << endl;

    // Display deposits
    cout << "Deposits Credited: ";
    for (int i = 0; i < c.numDeps; i++) {
        cout << "$" << fixed << setprecision(2) << c.deps[i] << " ";
    }
    cout << endl;
}

// Clean up dynamically allocated memory
void cleanUp(Cstmr& c) {
    delete[] c.chks;
    delete[] c.deps;
}
