/*
 * Author: Ireoluwa
 * Created on October 15, 2024, 12:19 PM
 * Purpose: Array to File and File to Array Functions
 */

//System Libraries
#include <iostream>
#include <fstream>
using namespace std;

//User Libraries

//Global Constants - Mathematical, Scientific, Conversions

//Higher Dimensions go here. No Variables

//Function Prototypes
void arToFle(const char *fileName, int *arr, int size);
void fleToAr(const char *fileName, int *arr, int size);

//Execution Begins here
int main() {
    //Declaring Variables
    const int SIZE = 5;
    int arr[SIZE] = {1, 2, 3, 4, 5};
    const char *fileName = "data.bin";
    
    //Writing array to file
    arToFle(fileName, arr, SIZE);
    
    //Reading array from file
    int arr2[SIZE] = {0};  // Array to store read data
    fleToAr(fileName, arr2, SIZE);
    
    //Displaying the array's contents
    cout << "Array contents read from file: ";
    for (int i = 0; i < SIZE; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    
    //Exiting stage left/right
    return 0;
}

// Function to write an array to a file in binary mode
void arToFle(const char *fileName, int *arr, int size) {
    ofstream outFile(fileName, ios::out | ios::binary);
    if (!outFile) {
        cout << "Error opening file for writing!" << endl;
        return;
    }
    
    outFile.write(reinterpret_cast<char*>(arr), size * sizeof(int));
    outFile.close();
}

// Function to read an array from a file in binary mode
void fleToAr(const char *fileName, int *arr, int size) {
    ifstream inFile(fileName, ios::in | ios::binary);
    if (!inFile) {
        cout << "Error opening file for reading!" << endl;
        return;
    }
    
    inFile.read(reinterpret_cast<char*>(arr), size * sizeof(int));
    inFile.close();
}
