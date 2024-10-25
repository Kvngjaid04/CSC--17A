/*
 * Author: Ireoluwa
 * Created on October 25, 2024
 * Purpose: Decrypt a four-digit integer.
 */

// Libraries
#include <iostream>
#include <string>

using namespace std;

// Function Prototypes
void decrypt(const string &input);
bool validateInput(const string &input);

// Execution begins here
int main() {
    string number;
    cout << "Enter a four-digit encrypted integer: ";
    cin >> number;

    if (!validateInput(number)) {
        cout << "Error: Invalid input. Only digits 0-7 are allowed." << endl;
        return 1;
    }

    decrypt(number);

    return 0;
}

// Function to validate input
bool validateInput(const string &input) {
    if (input.length() != 4) return false; // Ensure it's a four-digit number
    for (char c : input) {
        if (c < '0' || c > '7') {
            return false; // Check if each character is between 0 and 7
        }
    }
    return true;
}

// Function to decrypt the number
void decrypt(const string &input) {
    int decryptedDigits[4];

    // Decrypt by reversing the process
    for (int i = 0; i < 4; ++i) {
        decryptedDigits[i] = (input[i] - '0' + 2) % 8; // Inverse operation
    }

    // Swap back digits
    swap(decryptedDigits[0], decryptedDigits[2]); // Swap 1st and 3rd
    swap(decryptedDigits[1], decryptedDigits[3]); // Swap 2nd and 4th

    // Output the decrypted integer
    cout << "Decrypted integer: ";
    for (int i = 0; i < 4; ++i) {
        cout << decryptedDigits[i];
    }
    cout << endl;
}
