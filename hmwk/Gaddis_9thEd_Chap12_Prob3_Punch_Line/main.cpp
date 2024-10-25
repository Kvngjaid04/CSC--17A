/*
 * Author: Ireoluwa
 * Created on October 21, 2024, 3:00 PM
 * Purpose: Display a joke and its punchline from two files
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//User Libraries

//Global Constants - Mathematical, Scientific, Conversions

//Higher Dimensions go here. No Variables

//Function Prototypes
void readJk(ifstream&);
void readPL(ifstream&);

//Execution Begins here
int main() {
    //Setting the random number seed
    
    //Declaring Variables
    ifstream jkFile, plFile;

    //Initialize Variables
    jkFile.open("joke.txt");
    plFile.open("punchline.txt");

    //Processing/Mapping Inputs to Outputs
    if (!jkFile || !plFile) {
        cout << "Error opening files!" << endl;
        return 1;
    }

    //Displaying Input/Output Information
    readJk(jkFile);   // Reads joke file
    readPL(plFile);   // Reads punchline file

    //Close files
    jkFile.close();
    plFile.close();
    
    //Exiting stage left/right
    return 0;
}

// Function to read and display joke file
void readJk(ifstream& jkFile) {
    string line;
    while (getline(jkFile, line)) {
        cout << line << endl;
    }
}

// Function to read and display punchline file's last line
void readPL(ifstream& plFile) {
    string lastLn;
    char ch;

    // Move to the end of the file
    plFile.seekg(0, ios::end);
    
    // Back up and find the start of the last line
    plFile.seekg(-1, ios::cur); 
    while (plFile.tellg() > 0) {
        plFile.get(ch);
        if (ch == '\n') {
            break; 
        }
        plFile.seekg(-2, ios::cur); 
    }

    // Read the last line
    getline(plFile, lastLn);
    cout << lastLn << endl;
}
