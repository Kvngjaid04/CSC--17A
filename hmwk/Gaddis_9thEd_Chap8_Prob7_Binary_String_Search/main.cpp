/*
 * Author: Ireoluwa
 * Created on September 1, 2024, 3:00 AM
 * Purpose: Binary search for strings in a sorted array
 */

// System Libraries
#include <iostream>
#include <string>
using namespace std;

// Function Prototypes
int binSrch(const string[], int, const string&);
void bblSort(string[], int);

// Main Function
int main() {
    const int NUM_NAMES = 20; // Define constant within main

    // Array of names (unsorted)
    string names[NUM_NAMES] = {
        "Collins, Bill", "Smith, Bart", "Allen, Jim",
        "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
        "Taylor, Terri", "Johnson, Jill", "Allison, Jeff",
        "Looney, Joe", "Wolfe, Bill", "James, Jean",
        "Weaver, Jim", "Pore, Bob", "Rutherford, Greg",
        "Javens, Renee", "Harrison, Rose", "Setzer, Cathy",
        "Pike, Gordon", "Holland, Beth"
    };
    
    // Sort the array before performing binary search
    bblSort(names, NUM_NAMES);
    
    // Get the name to search for
    string srchnme;
    cout << "Enter the name you wish to search for: ";
    getline(cin, srchnme); // To read the full name including spaces
    
    // Perform the search
    int result = binSrch(names, NUM_NAMES, srchnme);
    
    // Display results
    if (result == -1)
        cout << "That name does not exist in the array." << endl;
    else
        cout << "That name is found at element " << result << " in the array." << endl;
    
    return 0;
}

int binSrch(const string array[], int size, const string& value) {
    int first = 0; // First array element
    int last = size - 1; // Last array element
    int middle; // Midpoint of search
    int pos = -1; // Position of search value
    bool found = false; // Flag
    
    while (!found && first <= last) {
        middle = (first + last) / 2; // Calculate midpoint
        
        if (array[middle] == value) { // If value is found at mid
            found = true;
            pos = middle;
        } else if (array[middle] > value) { // If value is in lower half
            last = middle - 1;
        } else { // If value is in upper half
            first = middle + 1;
        }
    }
    
    return pos;
}

void bblSort(string array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                swap(array[j], array[j + 1]);
            }
        }
    }
}
