#include <iostream>
#include <iomanip> // For setting decimal precision
#include <algorithm> // For sorting

using namespace std;

// Function Prototypes
int *getData(int &);         // Return the array size and the array
void prntDat(int *, int);    // Print the integer array
float *median(int *, int);   // Fill the median array with the float array size, the median, and the integer array data
void prntMed(float *);       // Print the median array

int main() {
    int size;
    int *intArray = getData(size);  // Step 1: Get the data

    prntDat(intArray, size);        // Step 2: Print the integer array

    float *medianArray = median(intArray, size);  // Step 3: Calculate the median and store it in a float array

    prntMed(medianArray);           // Step 4: Print the median array

    // Clean up dynamically allocated memory
    delete[] intArray;
    delete[] medianArray;

    return 0;
}

// Function to get the integer array from the user
int *getData(int &size) {
    
    cin >> size;

    int *array = new int[size];  // Dynamically allocate memory for the integer array

    
    for (int i = 0; i < size; ++i) {
        cin >> array[i];
    }

    return array;  // Return the dynamically allocated array
}

// Function to print the integer array
void prntDat(int *array, int size) {
    for (int i = 0; i < size; ++i) {
        if (i != 0) {  
            cout << " ";
        }
        cout << array[i];
    }
    cout << endl;
}

// Function to calculate the median and return a float array
float *median(int *array, int size) {
    // Step 1: Create a sorted copy of the integer array
    int *sortedArray = new int[size];
    copy(array, array + size, sortedArray);  // Copy original array to sortedArray
    sort(sortedArray, sortedArray + size);   // Sort the copied array

    // Step 2: Calculate the median
    float med;
    if (size % 2 == 0) {
        // If even, median is the average of the two middle elements
        med = (sortedArray[size / 2 - 1] + sortedArray[size / 2]) / 2.0;
    } else {
        // If odd, median is the middle element
        med = sortedArray[size / 2];
    }

    // Step 3: Dynamically allocate the float array with size 2 larger than the original array
    float *medArray = new float[size + 2];
    medArray[0] = size + 2;  // Store the size of the float array
    medArray[1] = med;       // Store the median value

    // Step 4: Copy the original (unsorted) integer array into the float array
    for (int i = 0; i < size; ++i) {
        medArray[i + 2] = array[i];
    }

    delete[] sortedArray;  // Clean up dynamically allocated memory for sortedArray

    return medArray;  // Return the dynamically allocated float array
}


// Function to print the float median array
void prntMed(float *medArray) {
    // Print the size of the median array and the median value with 2 decimal places
    cout << medArray[0] << " " << fixed << setprecision(2) << medArray[1];

    // Print the remaining elements without a trailing space
    for (int i = 2; i < medArray[0]; ++i) {
        cout << " " << fixed << setprecision(2) << medArray[i];
    }
}
