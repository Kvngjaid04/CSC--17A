/*
 * Author: Ireoluwa
 * Created on September 22, 2024, 1:00 PM
 * Purpose: Read, sort, and reverse a dynamic array
 */

//System Libraries
#include <iostream>
using namespace std;

//Function Prototypes
int *getData(int &);               //Fill the array
int *sort(const int *, int);       //Sort smallest to largest
int *reverse(const int *, int);    //Sort in reverse order
void prntDat(const int *, int);    //Print the array

int main() {
    int size;          // Size of the array
    int *arr = getData(size);       // Dynamically allocate and fill array

    int *sortedArr = sort(arr, size);  // Sort array from smallest to largest
    int *reversedArr = reverse(sortedArr, size);  // Reverse the sorted array

    // Print the sorted array
    prntDat(sortedArr, size);
    cout<< endl;

    // Print the reversed sorted array
    prntDat(reversedArr, size);

    // Deallocate the memory used for the arrays
    delete[] arr;
    delete[] sortedArr;
    delete[] reversedArr;

    return 0;
}

// Function to read and fill an array dynamically
int *getData(int &size) {
    cin >> size;

    int *array = new int[size];  // Dynamically allocate an array of given size
    for (int i = 0; i < size; i++) {
        cin >> array[i];
    }

    return array;
}

// Function to sort an array in ascending order
int *sort(const int *arr, int size) {
    int *sortedArr = new int[size];  // Dynamically allocate a new array for sorting

    // Copy the original array to the new one
    for (int i = 0; i < size; i++) {
        sortedArr[i] = arr[i];
    }

    // Sort the array using bubble sort
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (sortedArr[j] > sortedArr[j + 1]) {
                // Swap
                int temp = sortedArr[j];
                sortedArr[j] = sortedArr[j + 1];
                sortedArr[j + 1] = temp;
            }
        }
    }

    return sortedArr;
}

// Function to reverse an array
int *reverse(const int *arr, int size) {
    int *reversedArr = new int[size];  // Dynamically allocate a new array for reversing

    // Copy the elements in reverse order
    for (int i = 0; i < size; i++) {
        reversedArr[i] = arr[size - 1 - i];
    }

    return reversedArr;
}

// Function to print the array without trailing spaces
void prntDat(const int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) {
            cout << " ";  
        }
    }
}

