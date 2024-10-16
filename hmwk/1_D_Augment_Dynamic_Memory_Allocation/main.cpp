#include <iostream>
using namespace std;

// Function prototypes
int *getData(int &);                  // Read the array
int *augment(const int *, int);        // Augment and copy the original array
void prntAry(const int *, int);        // Print the array

int main() {
    int size;
    int *array = getData(size);        // Read the array from the user

    int *augArray = augment(array, size);  // Augment the array

    prntAry(array, size);                  // Print the original array
    cout << endl;

    prntAry(augArray, size + 1);           // Print the augmented array

    delete[] array;   // Free dynamically allocated memory
    delete[] augArray;

    return 0;
}

// Function to read data into a dynamic array
int *getData(int &size) {
    cin >> size;

    int *arr = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
    return arr;
}

// Function to augment the array by 1 element, placing 0 in the first element
int *augment(const int *arr, int size) {
    int *augArr = new int[size + 1];  // New array with one extra element
    augArr[0] = 0;                    // Place 0 in the first element

    for (int i = 0; i < size; i++) {
        augArr[i + 1] = arr[i];       // Copy original array shifted by 1
    }
    return augArr;
}

// Function to print the array
void prntAry(const int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if(i < size - 1 ) cout << " ";
    }
}
