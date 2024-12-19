
/* 
 * File:   AllKindsOfSorting.cpp
 * Author: Ireoluwa Dairo
 * Created on December 7, 2024, 9:23 PM
 */

#include "AllKindsOfSorting.h"
#include <algorithm>
#include <cstring>

using namespace std;

template<class T>
T* Prob2Sort<T>::sortArray(const T* arr, int size, bool ascending) {
    // Memory allocation
    if (index) delete[] index;
    index = new int[size];
    T* sorted = new T[size];
    
    // Initialize indices
    for (int i = 0; i < size; i++) {
        index[i] = i;
    }
    
    // Sort based on ascending/descending flag
    if (ascending) {
        sort(index, index + size, 
            [arr](int i1, int i2) { return arr[i1] < arr[i2]; });
    } else {
        sort(index, index + size, 
            [arr](int i1, int i2) { return arr[i1] > arr[i2]; });
    }
    
    // Create final sorted array
    for (int i = 0; i < size; i++) {
        sorted[i] = arr[index[i]];
    }
    
    return sorted;
}

template<class T>
T* Prob2Sort<T>::sortArray(const T* arr, int rows, int cols, int column, bool ascending) {
    column--;
    if (column < 0 || column >= cols) return nullptr;
    
    // Memory allocation
    if (index) delete[] index;
    index = new int[rows];
    T* sorted = new T[rows * cols + rows];  // Extra space for newlines
    
    // Initialize row indices
    for (int i = 0; i < rows; i++) {
        index[i] = i;
    }
    
    // Sort rows by specified column
    sort(index, index + rows, 
        [arr, cols, column](int a, int b) {
            return arr[a * cols + column] > arr[b * cols + column];
        });
    
    // Build result with newlines
    int destPos = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sorted[destPos++] = arr[index[i] * cols + j];
        }
        
        if (i == rows - 2) {
            sorted[destPos++] = '\n';
        }
    }
    
    return sorted;
}

template class Prob2Sort<char>;