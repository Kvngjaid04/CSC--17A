
/* 
 * File:   AllKindsOfSorting.cpp
 * Author: Ireoluwa Dairo
 * Created on December 7, 2024, 9:23 PM
 */

#include "AllKindsOfSorting.h"

template<class T>
T* Prob2Sort<T>::sortArray(const T* arr, int size, bool ascending) {
    // Allocate the index array
    if(index) delete [] index;
    index = new int[size];
    
    // Create the result array
    T* result = new T[size];
    
    // Initialize the index array
    for(int i=0; i<size; i++) {
        index[i] = i;
    }
    
    // Sort the index array
    for(int i=0; i<size-1; i++) {
        for(int j=0; j<size-i-1; j++) {
            if(ascending) {
                if(arr[index[j]] > arr[index[j+1]]) {
                    // Swap indices
                    int temp = index[j];
                    index[j] = index[j+1];
                    index[j+1] = temp;
                }
            } else {
                if(arr[index[j]] < arr[index[j+1]]) {
                    // Swap indices
                    int temp = index[j];
                    index[j] = index[j+1];
                    index[j+1] = temp;
                }
            }
        }
    }
    
    // Create the sorted array
    for(int i=0; i<size; i++) {
        result[i] = arr[index[i]];
    }
    
    return result;
}

template<class T>
T* Prob2Sort<T>::sortArray(const T* arr, int rows, int cols, int column, bool ascending) {
    // Allocate the index array
    if(index) delete [] index;
    index = new int[rows];
    
    // Create the result array
    T* result = new T[rows * cols];
    
    // Initialize the index array
    for(int i=0; i<rows; i++) {
        index[i] = i;
    }
    
    // Sort based on the specified column
    for(int i=0; i<rows-1; i++) {
        for(int j=0; j<rows-i-1; j++) {
            if(ascending) {
                if(arr[index[j]*cols + column] > arr[index[j+1]*cols + column]) {
                    // Swap indices
                    int temp = index[j];
                    index[j] = index[j+1];
                    index[j+1] = temp;
                }
            } else {
                if(arr[index[j]*cols + column] < arr[index[j+1]*cols + column]) {
                    // Swap indices
                    int temp = index[j];
                    index[j] = index[j+1];
                    index[j+1] = temp;
                }
            }
        }
    }
    
    // Copy entire rows based on sorted index
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            result[i*cols + j] = arr[index[i]*cols + j];
        }
    }
    
    return result;
}

// Explicit instantiation
template class Prob2Sort<char>;