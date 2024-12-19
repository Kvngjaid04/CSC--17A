/* 
 * File:   ssheet.cpp
 * Author: Ireoluwa Dairo
 * 
 * Created on December 7, 2024, 11:06 PM
 */

#include "ssheet.h"
#include <fstream>
#include <iostream>
using namespace std;

template<class T>
Prob3Table<T>::Prob3Table(char* filename, int r, int c) {
    rows = r;
    cols = c;
    
    // Allocate memory
    table = new T[rows * cols];
    rowSum = new T[rows];
    colSum = new T[cols];
    
    // Read the file
    ifstream inFile(filename);
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            inFile >> table[i * cols + j];
        }
    }
    inFile.close();
    
    // Calculate sums
    calcTable();
}

template<class T>
void Prob3Table<T>::calcTable(void) {
    // Initialize sums to 0
    for(int i = 0; i < rows; i++) rowSum[i] = 0;
    for(int j = 0; j < cols; j++) colSum[j] = 0;
    grandTotal = 0;
    
    // Calculate row sums and column sums
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            rowSum[i] += table[i * cols + j];
            colSum[j] += table[i * cols + j];
        }
    }
    
    // Calculate grand total
    for(int i = 0; i < rows; i++) {
        grandTotal += rowSum[i];
    }
}

template<class T>
Prob3TableInherited<T>::Prob3TableInherited(char* filename, int r, int c) 
    : Prob3Table<T>(filename, r, c) {
    // Allocate augmented table
    augTable = new T[(this->rows + 1) * (this->cols + 1)];
    
    // Copy original table to augmented table
    for(int i = 0; i < this->rows; i++) {
        for(int j = 0; j < this->cols; j++) {
            augTable[i * (this->cols + 1) + j] = this->table[i * this->cols + j];
        }
    }
    
    // Add row sums
    for(int i = 0; i < this->rows; i++) {
        augTable[i * (this->cols + 1) + this->cols] = this->rowSum[i];
    }
    
    // Add column sums
    for(int j = 0; j < this->cols; j++) {
        augTable[this->rows * (this->cols + 1) + j] = this->colSum[j];
    }
    
    // Add grand total
    augTable[(this->rows) * (this->cols + 1) + this->cols] = this->grandTotal;
}

// Explicit template instantiation
template class Prob3Table<int>;
template class Prob3TableInherited<int>;
template class Prob3Table<float>;
template class Prob3TableInherited<float>;