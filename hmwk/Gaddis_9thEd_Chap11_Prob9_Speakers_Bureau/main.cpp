/*
 * Author: Ireoluwa
 * Created on October 15, 2024, 12:19 PM
 * Purpose: Speakers' Bureau Program
 */

//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - Mathematical, Scientific, Conversions

//Higher Dimensions go here. No Variables

//Function Prototypes
void addSpkr(struct Spkr[], int);
void edtSpkr(struct Spkr[], int);
void dspSpkr(const struct Spkr[], int);

//Structure to hold speaker information
struct Spkr {
    string name;
    string phone;
    string topic;
    float fee;
};

//Execution Begins here
int main() {
    //Setting the random number seed
    
    //Declaring Variables
    const int SIZE = 10;
    Spkr spkrs[SIZE];
    int choice;
    
    //Initialize Variables
    for (int i = 0; i < SIZE; i++) {
        spkrs[i].name = "";
        spkrs[i].phone = "";
        spkrs[i].topic = "";
        spkrs[i].fee = 0.0f; // Using float for the fee
    }

    //Processing/Mapping Inputs to Outputs
    do {
        //Displaying Input/Output Information
        cout << endl << "Speakers' Bureau Menu" << endl;
        cout << "1. Add Speaker" << endl;
        cout << "2. Edit Speaker" << endl;
        cout << "3. Display All Speakers" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addSpkr(spkrs, SIZE);
                break;
            case 2:
                edtSpkr(spkrs, SIZE);
                break;
            case 3:
                dspSpkr(spkrs, SIZE);
                break;
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4."
                        << endl;
        }
    } while (choice != 4);
    
    //Exiting stage left/right
    return 0;
}

// Function to add a speaker
void addSpkr(Spkr spkrs[], int size) {
    int index;
    cout << "Enter the index of the speaker to add (0-" << size - 1 << "): ";
    cin >> index;
    
    if (index >= 0 && index < size) {
        cout << "Enter speaker name: ";
        cin.ignore();
        getline(cin, spkrs[index].name);
        
        cout << "Enter telephone number: ";
        getline(cin, spkrs[index].phone);
        
        cout << "Enter speaking topic: ";
        getline(cin, spkrs[index].topic);
        
        do {
            cout << "Enter fee required: ";
            cin >> spkrs[index].fee;
            if (spkrs[index].fee < 0)
                cout << "Fee cannot be negative. Please try again." << endl;
        } while (spkrs[index].fee < 0);
    } else {
        cout << "Invalid index. Please enter a value between 0 and " << size - 
                1 << "." << endl;
    }
}

// Function to edit a speaker
void edtSpkr(Spkr spkrs[], int size) {
    int index;
    cout << "Enter the index of the speaker to edit (0-" << size - 1 << "): ";
    cin >> index;

    if (index >= 0 && index < size) {
        cout << "Editing speaker at index " << index << "..." << endl;
        cout << "Enter new speaker name: ";
        cin.ignore();
        getline(cin, spkrs[index].name);
        
        cout << "Enter new telephone number: ";
        getline(cin, spkrs[index].phone);
        
        cout << "Enter new speaking topic: ";
        getline(cin, spkrs[index].topic);
        
        do {
            cout << "Enter new fee required: ";
            cin >> spkrs[index].fee;
            if (spkrs[index].fee < 0)
                cout << "Fee cannot be negative. Please try again." << endl;
        } while (spkrs[index].fee < 0);
    } else {
        cout << "Invalid index. Please enter a value between 0 and " << size - 
                1 << "." << endl;
    }
}

// Function to display all speakers
void dspSpkr(const Spkr spkrs[], int size) {
    for (int i = 0; i < size; i++) {
        if (spkrs[i].name != "") { // display if the speaker's name is filled
            cout << endl << "Speaker " << i + 1 << ":" << endl;
            cout << "Name: " << spkrs[i].name << endl;
            cout << "Telephone: " << spkrs[i].phone << endl;
            cout << "Topic: " << spkrs[i].topic << endl;
            cout << "Fee: $" << fixed << setprecision(2) << spkrs[i].fee <<endl;
        }
    }
}
