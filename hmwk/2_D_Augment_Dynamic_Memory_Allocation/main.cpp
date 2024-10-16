/*
 * Author: Ireoluwa
 * Created on October 1, 2024, 1:00 PM
 * Purpose: Augment a matrix by adding a row and column of zeros.
 */

//System Libraries
#include <iostream>
using namespace std;

//Function Prototypes
int **getData(int &, int &); // Get the Matrix Data
void printDat(const int * const *, int, int); // Print the Matrix
int **augment(const int * const *, int, int); // Augment the original array
void destroy(int **, int); // Destroy the Matrix, reallocate memory

//Execution Begins here
int main() {
    int rows, cols;
    // Getting the matrix data
    int **matrix = getData(rows, cols);
    
    // Print original matrix
    printDat(matrix, rows, cols);
    cout << endl;
    
    // Augment the matrix
    int **augMatrix = augment(matrix, rows, cols);
    
    // Print augmented matrix
    printDat(augMatrix, rows + 1, cols + 1);
    
    
    // Clean up the dynamically allocated memory
    destroy(matrix, rows);
    destroy(augMatrix, rows + 1);
    
    return 0;
}

// Function to get matrix data from user input
int **getData(int &rows, int &cols) {
    cin >> rows;
 
    cin >> cols;

    // Dynamically allocate 2-D array
    int **matrix = new int*[rows];
    for(int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
    }

    // Fill the matrix with input data
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    return matrix;
}

// Function to print the matrix
void printDat(const int * const *matrix, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << matrix[i][j];
            if (j < cols - 1 ) cout << " ";
            
        }
        if (i < rows - 1) cout << endl; 
    }
}

// Function to augment the matrix by adding an extra row and column of zeros
int **augment(const int * const *matrix, int rows, int cols) {
    // Dynamically allocate augmented matrix (1 row and 1 column larger)
    int **augMatrix = new int*[rows + 1];
    for(int i = 0; i < rows + 1; i++) {
        augMatrix[i] = new int[cols + 1];
    }

    // Fill the first row and column with 0's
    for(int i = 0; i < rows + 1; i++) {
        for(int j = 0; j < cols + 1; j++) {
            if(i == 0 || j == 0) {
                augMatrix[i][j] = 0;
            } else {
                augMatrix[i][j] = matrix[i - 1][j - 1];
            }
        }
    }

    return augMatrix;
}

// Function to destroy matrix and free allocated memory
void destroy(int **matrix, int rows) {
    for(int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}
