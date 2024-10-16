/*
 * Author: Ireoluwa
 * Created on October 1, 2024
 * Purpose: Total the elements in a 2-D array using functions.
 */

//System Libraries
#include <iostream>
using namespace std;

// Function prototypes
int **getData(int &, int &);             // Return the 2-D array and its size.
void prntDat(const int* const *, int, int); // Print the 2-D array.
void destroy(int **, int, int);          // Deallocate memory.
int sum(const int * const *, int, int);  // Return the sum of the 2-D array.

int main(){
    int rows, cols;
    int **array = getData(rows, cols); // Get 2-D array and its size.
    
    prntDat(array, rows, cols);        // Print the array.
    
    cout << sum(array, rows, cols); // Print the sum.
    
    destroy(array, rows, cols);        // Deallocate the memory.

    return 0;
}

// Function to dynamically allocate a 2-D array and input data.
int **getData(int &rows, int &cols) {
    // Input the number of rows and columns.
    cin >> rows;
    cin >> cols;
    
    // Dynamically allocate the 2-D array.
    int **arr = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        arr[i] = new int[cols];
    }
    
    // Input the elements of the 2-D array.
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> arr[i][j];
        }
    }
    
    return arr;
}

// Function to print the 2-D array.
void prntDat(const int* const *arr, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << arr[i][j];
            if (j < cols - 1) cout << " ";
        }
        cout << endl;
    }
}


// Function to calculate the sum of the elements in the 2-D array.
int sum(const int * const *arr, int rows, int cols) {
    int total = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            total += arr[i][j];
        }
    }
    return total;
}

// Function to deallocate the dynamically allocated memory for the 2-D array.
void destroy(int **arr, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        delete[] arr[i]; // Delete each row.
    }
    delete[] arr; // Delete the array of pointers.
}
