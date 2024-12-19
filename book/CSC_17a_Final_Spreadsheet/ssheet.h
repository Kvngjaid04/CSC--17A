/* 
 * File:   ssheet.h
 * Author: Ireoluwa Dairo
 *
 * Created on December 7, 2024, 11:06 PM
 */

#ifndef SSHEET_H
#define SSHEET_H

template<class T>
class Prob3Table {
protected:
    int rows;        // Number of rows in the table
    int cols;        // Number of cols in the table
    T* rowSum;       // RowSum array
    T* colSum;       // ColSum array
    T* table;        // Table array
    T grandTotal;    // Grand total
    void calcTable(void); // Calculate all the sums

public:
    Prob3Table(char*, int, int);  // Constructor
    ~Prob3Table() {               // Destructor
        delete[] table;
        delete[] rowSum;
        delete[] colSum;
    }
    const T* getTable(void) { return table; }
    const T* getRowSum(void) { return rowSum; }
    const T* getColSum(void) { return colSum; }
    T getGrandTotal(void) { return grandTotal; }
};

template<class T>
class Prob3TableInherited : public Prob3Table<T> {
protected:
    T* augTable;    // Augmented Table with sums

public:
    Prob3TableInherited(char*, int, int);  // Constructor
    ~Prob3TableInherited() {               // Destructor
        delete[] augTable;
    }
    const T* getAugTable(void) { return augTable; }
};

#endif