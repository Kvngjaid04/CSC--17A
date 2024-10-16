/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 22nd, 2021, 1:30 PM
 * Purpose:  Compare 1 and 2 Dimensional Dynamic Arrays
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;  

//Function Prototypes Here
void prntAry(const int*, int, int);
void prntAry(int**, int, int);
int* fillAry(int, int, int);
int** fillAry(int, int);
void fillAry(int**, const int*, int, int);
void swap(int&, int&);
void smlLst(int*, int, int);
void mrkSrt(int*, int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    int rowsize = 4; // Row size for both 1 and 2 D arrays
    int colsize = 3; // The column size for a 2 dimensional Array
    int lowRng = 100, highRng = 999;
    int perLine = 4;
    
    //Fill each parallel array
    int* array = fillAry(rowsize, highRng, lowRng);
    int* brray = fillAry(rowsize, highRng / 10, lowRng / 10);
    int* crray = fillAry(rowsize, highRng / 100, lowRng / 100);
    
    //Sort the arrays for all positions
    mrkSrt(array, rowsize);
    mrkSrt(brray, rowsize);
    mrkSrt(crray, rowsize);
    
    //Fill the 2-D array
    int** table = fillAry(rowsize, colsize);
    fillAry(table, array, rowsize, 0);
    fillAry(table, brray, rowsize, 1);
    fillAry(table, crray, rowsize, 2);
    
    //Print the values in the arrays
    prntAry(array, rowsize, perLine);
    prntAry(brray, rowsize, perLine);
    prntAry(crray, rowsize, perLine);
    prntAry(table, rowsize, colsize);
    
    //Free the memory
    delete[] array;
    delete[] brray;
    delete[] crray;
    for (int i = 0; i < rowsize; i++) {
        delete[] table[i];
    }
    delete[] table;
    
    //Exit
    return 0;
}

void fillAry(int** a, const int* c, int rowSize, int col) {
    for (int row = 0; row < rowSize; row++) {
        a[row][col] = c[row];
    }
}

int* fillAry(int n, int hr, int lr) {
    n = n < 2 ? 2 : n;
    int* a = new int[n];
    for (int indx = 0; indx < n; indx++) {
        a[indx] = rand() % (hr - lr + 1) + lr;
    }
    return a;
}

int** fillAry(int rows, int cols) {
    rows = rows < 2 ? 2 : rows;
    cols = cols < 2 ? 2 : cols;
    int** a = new int*[rows];
    for (int i = 0; i < rows; i++) {
        a[i] = new int[cols];
        for (int j = 0; j < cols; j++) {
            a[i][j] = 0; // initialize with 0
        }
    }
    return a;
}

void prntAry(int** a, int rowsize, int colsize) {
    cout << endl << "The Array Values" << endl;
    for (int row = 0; row < rowsize; row++) {
        for (int col = 0; col < colsize; col++) {
            cout << setw(4) << a[row][col];
        }
        cout << endl;
    }
}

void prntAry(const int* a, int size, int perLine) {
    //Print the values in the array
    cout << endl << "The Array Values" << endl;
    for (int indx = 0; indx < size; indx++) {
        cout << a[indx] << " ";
        if (indx % perLine == (perLine - 1)) cout << endl;
    }
    cout << endl;
}

void mrkSrt(int* a, int size) {
    for (int pos = 0; pos < size - 1; pos++) {
        smlLst(a, size, pos);
    }
}

void smlLst(int* a, int n, int pos) {
    for (int i = pos + 1; i < n; i++) {
        if (a[pos] > a[i]) {
            swap(a[pos], a[i]);
        }
    }
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}