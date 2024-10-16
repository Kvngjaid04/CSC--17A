/*
 * Author: Ireoluwa
 * Created on September 22, 2024
 * Purpose: Create a parallel array of successive sums from input array
 */

#include <iostream>
using namespace std;

// Function Prototypes
int *getData(int &);             // Return the array size and the array from the inputs
int *sumAry(const int *, int);   // Return the array with successive sums
void prntAry(const int *, int);  // Print the array

int main() {
    int size;
    
    // Get the input data array
    int *data = getData(size);
    
    // Create the successive sum array
    int *sumArray = sumAry(data, size);
    
    // Print the original and successive sum arrays
    prntAry(data, size);
    cout << endl;
    
    prntAry(sumArray, size);
    
    // Free dynamically allocated memory
    delete[] data;
    delete[] sumArray;
    
    return 0;
}

// Function to get the array data and size
int *getData(int &size) {
    cin >> size;
    
    int *array = new int[size];
    
    for (int i = 0; i < size; i++) {
        
        cin >> array[i];
    }
    
    return array;
}

// Function to create the successive sum array
int *sumAry(const int *array, int size) {
    int *sumArray = new int[size];
    
    sumArray[0] = array[0];  // First element remains the same
    for (int i = 1; i < size; i++) {
        sumArray[i] = sumArray[i - 1] + array[i];
    }
    
    return sumArray;
}

// Function to print the array
void prntAry(const int *array, int size) {
    for (int i = 0; i < size; i++) {
        if (i != 0) {  
            cout << " ";
        }
        cout << array[i];
    }
    
}
