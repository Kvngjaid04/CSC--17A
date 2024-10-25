/*
 * Author: Ireoluwa
 * Created on October 22, 2024, 2:00 PM
 * Purpose: File encryption filter program
 */

// System Libraries
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function Prototypes
void encryptFile(const string &inputFile, const string &outputFile, int offset);

int main() {
    // Declaring Variables
    string inputFile, outputFile;
    int offset;

    // Getting input file name, output file name and offset for encryption
    cout << "Enter the name of the input file: ";
    cin >> inputFile;

    cout << "Enter the name of the output file: ";
    cin >> outputFile;

    cout << "Enter the ASCII offset for encryption (e.g., 10): ";
    cin >> offset;

    // Encrypting the file
    encryptFile(inputFile, outputFile, offset);

    cout << "Encryption completed. Encrypted data written to " << outputFile << endl;

    return 0;
}

// Function to encrypt the contents of the file
void encryptFile(const string &inputFile, const string &outputFile, int offset) {
    // Opening the input file in read mode
    ifstream inFile(inputFile);
    // Opening the output file in write mode
    ofstream outFile(outputFile);

    // Check if input file opened successfully
    if (!inFile) {
        cout << "Error opening input file: " << inputFile << endl;
        return;
    }
    
    // Check if output file opened successfully
    if (!outFile) {
        cout << "Error opening output file: " << outputFile << endl;
        return;
    }

    char ch;
    // Read characters from the input file
    while (inFile.get(ch)) {
        // Encrypt the character by adding the offset
        char encryptedChar = static_cast<char>(ch + offset);
        // Write the encrypted character to the output file
        outFile.put(encryptedChar);
    }

    // Closing the files
    inFile.close();
    outFile.close();
}
