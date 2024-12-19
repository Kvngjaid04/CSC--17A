/* 
 * File:   main.cpp
 * Author: Ireoluwa Dairo
 * Created on December 8, 2024, 12:03 AM
 */

#include <cstdlib>
#include <iostream>
#include <ctime>  
#include <fstream>
using namespace std;

//User Libraries
#include "RandomSequence.h"
#include "AllKindsOfSorting.h"
#include "ssheet.h"
#include "SavAccCls.h"
#include "empclass.h"

//Global Constants - Mathematical, Scientific, Conversions

//Higher Dimensions go here. No Variables

//Function Prototypes
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
//Execution Begins here

int main(int argc, char** argv) {
    //Setting the random number seed
    srand(time(0));
    //Processing/Mapping Inputs to Outputs & Displaying Input/Output Information
    int choice;
    do { // Display menu
        cout << "\nFinal Exam - Menu Program\n";
        cout << "1. Random Sequence Problem\n";
        cout << "2. Sorting Problem\n";
        cout << "3. Spreadsheet Problem\n";
        cout << "4. Savings Account Problem\n";
        cout << "5. Employee Class Problem\n";
        cout << "6. Conversions Problem\n";
        cout << "7. Exit\n";
        cout << "Enter your choice (1-6, 7 to exit): ";
        cin >> choice;
        
        switch(choice) {         // Process menu choice
            case 1:
                cout << "\nProblem 1 - Random Sequence\n";
                problem1();                                    break;
                
            case 2:
                cout << "\nProblem 2 - Sorting Problem\n";
                problem2();                                    break;
                
            case 3:
                cout << "\nProblem 3 - Spreadsheet\n";
                problem3();                                    break;
                
            case 4:
                cout << "\nProblem 4 - Savings Account\n";
                problem4();                                    break;
                
            case 5:
                cout << "\nProblem 5 - Employee Class\n";
                problem5();                                    break;
                
            case 6:
                cout << "\nProblem 6 - Conversions\n";
                problem6();                                    break;
            
            case 7:
                cout << "Exiting program...\n";                break;
                
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while(choice != 7); 
    return 0;} //Exiting stage left/right

// Function definitions

// Problem 1
void problem1(){
    char n=5;
    char rndseq[]={19,34,57,79,126};
    int ntimes=100000;
    
    Prob1Random a(n,rndseq);
    
    for(int i=1;i<=ntimes;i++){
        a.randFromSet();
    }
    
    int *x=a.getFreq();
    char *y=a.getSet();
    
    for(int i=0;i<n;i++){
        cout<<int(y[i])<<" occurred "<<x[i]<<" times"<<endl;
    }
    cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;
}

// Problem 2
void problem2(){
    cout<<"The start of Problem 2, the sorting problem"<<endl;
    
    Prob2Sort<char> rc;
    bool ascending=true;
    
    ifstream infile;
    infile.open("Problem2.txt",ios::in);
    
    char *ch2=new char[10*16];
    char *ch2p=ch2;
    
    while(infile.get(*ch2)){
        cout<<*ch2;
        ch2++;
    }
    infile.close();
    cout<<endl;
    
    cout<<"Sorting on which column"<<endl;
    int column;
    cin>>column;
    
    char *zc=rc.sortArray(ch2p,10,16,column,ascending);
    
    for(int i=0;i<10;i++){
        for(int j=0;j<16;j++){
            cout<<zc[i*16+j];
        }
      }
    
    delete []zc;
    }

// Problem 3
void problem3(){
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
    
}

// Problem 4
void problem4(){
        SavingsAccount mine(-300);
    
    for(int i=1;i<=10;i++) {
        mine.Transaction((float)(rand()%500)*(rand()%3-1));
    }
    
    mine.toString();
    
    cout<<"Balance after 7 years given 10% interest = "
        <<mine.Total((float)(0.10),7)<<endl;
    
    cout<<"Balance after 7 years given 10% interest = "
        <<mine.TotalRecursive((float)(0.10),7)
        <<" Recursive Calculation "<<endl;
}

// Problem 5
void problem5(){
    Employee Mark("Mark", "Boss", 215.50);
    Mark.setHoursWorked(-3);
    Mark.toString();
    
    Mark.CalculatePay(Mark.setHourlyRate(20.0), Mark.setHoursWorked(25));
    Mark.toString();
    
    Mark.CalculatePay(Mark.setHourlyRate(40.0), Mark.setHoursWorked(25));
    Mark.toString();
    
    Mark.CalculatePay(Mark.setHourlyRate(60.0), Mark.setHoursWorked(25));
    Mark.toString();
    
    Employee Mary("Mary", "VP", 50.0);
    Mary.toString();
    
    Mary.CalculatePay(Mary.setHourlyRate(50.0), Mary.setHoursWorked(40));
    Mary.toString();
    
    Mary.CalculatePay(Mary.setHourlyRate(50.0), Mary.setHoursWorked(50));
    Mary.toString();
    
    Mary.CalculatePay(Mary.setHourlyRate(50.0), Mary.setHoursWorked(60));
    Mary.toString();
    
}

// Problem 6
void problem6(){
    cout << "Problem 6 - Conversion Results\n\n";
    cout << "a) 5.75\n";
    cout << "Binary: [Enter your answer here]\n";
    cout << "Octal: [Enter your answer here]\n";
    cout << "Hex: [Enter your answer here]\n";
    cout << "NASA Hex float: [Enter your answer here]\n";
    cout << "Scaled Binary (1 byte): [Enter your answer here]\n";
    cout << "Result after multiplication: [Enter your answer here]\n";
    cout << "IEEE 754: [Enter your answer here]\n\n";
    
    cout << "b) 0.9\n";
    cout << "Binary: [Enter your answer here]\n";
    cout << "Octal: [Enter your answer here]\n";
    cout << "Hex: [Enter your answer here]\n";
    cout << "NASA Hex float: [Enter your answer here]\n";
    cout << "Scaled Binary (2 byte): [Enter your answer here]\n";
    cout << "Result after multiplication: [Enter your answer here]\n";
    cout << "IEEE 754: [Enter your answer here]\n\n";
    
    cout << "c) 99.7\n";
    cout << "Binary: [Enter your answer here]\n";
    cout << "Octal: [Enter your answer here]\n";
    cout << "Hex: [Enter your answer here]\n";
    cout << "NASA Hex float: [Enter your answer here]\n";
    cout << "Scaled Binary (3 byte): [Enter your answer here]\n";
    cout << "Result after multiplication: [Enter your answer here]\n";
    cout << "IEEE 754: [Enter your answer here]\n";
}
