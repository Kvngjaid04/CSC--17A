/* 
 * File:   main.cpp
 * Author: Ireoluwa Dairo
 * Created on December 7, 2024, 11:03 PM
 */

#include <iostream>
#include "ssheet.h"
using namespace std;

int main() {
    cout << "Entering problem number 3" << endl;
    
    int rows = 5;
    int cols = 6;
    
    Prob3TableInherited<int> tab("ssheet.txt", rows, cols);
    
    // Print original table
    cout << "Original Table:" << endl;
    const int* naugT = tab.getTable();
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << naugT[i * cols + j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    // Print augmented table
    cout << "Augmented Table:" << endl;
    const int* augT = tab.getAugTable();
    for(int i = 0; i <= rows; i++) {
        for(int j = 0; j <= cols; j++) {
            cout << augT[i * (cols + 1) + j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}