/*
 * Author: Ireoluwa
 * Created on October 21, 2024, 5:00 PM
 * Purpose: Inventory management program
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip> // For formatting output
using namespace std;

//User Libraries

//Global Constants - Mathematical, Scientific, Conversions

//Higher Dimensions go here. No Variables

//Function Prototypes
void addRec(fstream &);         // Add a new record
void displayRec(fstream &);     // Display a record
void changeRec(fstream &);      // Modify a record

// Structure to store inventory data
struct InvItem {
    char desc[50];   // Item description
    int qty;         // Quantity on hand
    float whlCost;   // Wholesale cost
    float retCost;   // Retail cost
    char date[11];   // Date added (dd/mm/yyyy)
};

//Execution Begins here
int main() {
    //Declaring Variables
    fstream invFile;
    int choice;

    //Initialize Variables
    invFile.open("inventory.dat", ios::in | ios::out | ios::binary | ios::app);
    if (!invFile) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    // Menu Loop
    do {
        // Display menu options
        cout << "\nInventory Menu" << endl;
        cout << "1. Add new record" << endl;
        cout << "2. Display record" << endl;
        cout << "3. Change record" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Input validation for choice
        while (choice < 1 || choice > 4) {
            cout << "Invalid choice. Enter again: ";
            cin >> choice;
        }

        // Processing/Mapping Inputs to Outputs
        switch (choice) {
            case 1:
                addRec(invFile);
                break;
            case 2:
                displayRec(invFile);
                break;
            case 3:
                changeRec(invFile);
                break;
        }
    } while (choice != 4);

    // Close file
    invFile.close();
    
    //Exiting stage left/right
    return 0;
}

// Function to add new records to the file
void addRec(fstream &file) {
    InvItem item;
    
    // Get inventory details from the user
    cout << "Enter item description: ";
    cin.ignore(); // to clear the newline from the previous input
    cin.getline(item.desc, 50);
    
    cout << "Enter quantity on hand: ";
    cin >> item.qty;
    while (item.qty < 0) {
        cout << "Quantity cannot be negative. Enter again: ";
        cin >> item.qty;
    }

    cout << "Enter wholesale cost: ";
    cin >> item.whlCost;
    while (item.whlCost < 0) {
        cout << "Wholesale cost cannot be negative. Enter again: ";
        cin >> item.whlCost;
    }

    cout << "Enter retail cost: ";
    cin >> item.retCost;
    while (item.retCost < 0) {
        cout << "Retail cost cannot be negative. Enter again: ";
        cin >> item.retCost;
    }

    cout << "Enter date added (dd/mm/yyyy): ";
    cin >> item.date;

    // Write the structure to the file
    file.write(reinterpret_cast<char *>(&item), sizeof(item));

    cout << "Record added successfully!" << endl;
}

// Function to display a record from the file
void displayRec(fstream &file) {
    InvItem item;
    int recNum;

    // Get record number to display
    cout << "Enter record number to display: ";
    cin >> recNum;

    // Move to the specified record in the file
    file.seekg((recNum - 1) * sizeof(item), ios::beg);
    
    // Read the record from the file
    file.read(reinterpret_cast<char *>(&item), sizeof(item));

    // Display the record
    if (file) {
        cout << "\nItem Description: " << item.desc << endl;
        cout << "Quantity: " << item.qty << endl;
        cout << "Wholesale Cost: $" << fixed << setprecision(2) << item.whlCost << endl;
        cout << "Retail Cost: $" << fixed << setprecision(2) << item.retCost << endl;
        cout << "Date Added: " << item.date << endl;
    } else {
        cout << "Record not found!" << endl;
    }
}

// Function to change an existing record in the file
void changeRec(fstream &file) {
    InvItem item;
    int recNum;

    // Get record number to modify
    cout << "Enter record number to modify: ";
    cin >> recNum;

    // Move to the specified record in the file
    file.seekg((recNum - 1) * sizeof(item), ios::beg);
    
    // Read the record from the file
    file.read(reinterpret_cast<char *>(&item), sizeof(item));

    if (!file) {
        cout << "Record not found!" << endl;
        return;
    }

    // Display the current record
    cout << "Current record:" << endl;
    cout << "Item Description: " << item.desc << endl;
    cout << "Quantity: " << item.qty << endl;
    cout << "Wholesale Cost: $" << fixed << setprecision(2) << item.whlCost << endl;
    cout << "Retail Cost: $" << fixed << setprecision(2) << item.retCost << endl;
    cout << "Date Added: " << item.date << endl;

    // Get new values from the user
    cout << "Enter new quantity on hand: ";
    cin >> item.qty;
    while (item.qty < 0) {
        cout << "Quantity cannot be negative. Enter again: ";
        cin >> item.qty;
    }

    cout << "Enter new wholesale cost: $";
    cin >> item.whlCost;
    while (item.whlCost < 0) {
        cout << "Wholesale cost cannot be negative. Enter again: ";
        cin >> item.whlCost;
    }

    cout << "Enter new retail cost: $";
    cin >> item.retCost;
    while (item.retCost < 0) {
        cout << "Retail cost cannot be negative. Enter again: ";
        cin >> item.retCost;
    }

    cout << "Enter new date added (dd/mm/yyyy): ";
    cin >> item.date;

    // Move to the correct position in the file
    file.seekp((recNum - 1) * sizeof(item), ios::beg);

    // Write the updated record back to the file
    file.write(reinterpret_cast<char *>(&item), sizeof(item));

    cout << "Record updated successfully!" << endl;
}
