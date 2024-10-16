/*
 * Author: Ireoluwa
 * Created on October 15, 2024, 12:19 PM
 * Purpose: Sentence Filter for Binary Files
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

//User Libraries

//Global Constants - Mathematical, Scientific, Conversions

//Higher Dimensions go here. No Variables

//Function Prototypes
void fltrBin(ifstream &inFile, ofstream &outFile);

//Execution Begins here
int main() {
    //Declaring Variables
    string inName, outName;
    ifstream inFile;
    ofstream outFile;
    
    //Getting file names from the user
    cout << "Enter input binary file name: ";
    cin >> inName;
    cout << "Enter output binary file name: ";
    cin >> outName;
    
    //Opening the input file in binary mode
    inFile.open(inName, ios::in | ios::binary);
    if (!inFile) {
        cout << "Error opening input file!" << endl;
        return 1;
    }
    
    //Opening the output file in binary mode
    outFile.open(outName, ios::out | ios::binary);
    if (!outFile) {
        cout << "Error opening output file!" << endl;
        return 1;
    }

    //Processing/Mapping Inputs to Outputs
    fltrBin(inFile, outFile);
    
    //Closing the files
    inFile.close();
    outFile.close();
    
    //Exiting stage left/right
    return 0;
}

// Function to process data from input file and write data to output file
void fltrBin(ifstream &inFile, ofstream &outFile) {
    char ch;
    bool newSnt = true; // Flag to track new sentence

    // Read one byte (character) at a time from the binary file
    while (inFile.read(&ch, sizeof(ch))) {
        // Check if we are at the beginning of a sentence
        if (newSnt && isalpha(ch)) {
            // Make first character of the sentence uppercase
            ch = toupper(ch);
            newSnt = false; // We are no longer at the start of a sentence
        } else {
            // Convert everything else to lowercase
            ch = tolower(ch);
        }

        // Write the modified character to the output binary file
        outFile.write(&ch, sizeof(ch));

        // If a period is found, the next non-space character will 
        // be the start of a new sentence
        if (ch == '.') {
            newSnt = true;
        }
    }
}
