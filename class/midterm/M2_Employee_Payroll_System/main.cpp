/*
 * File:   main.cpp
 * Author: Ireoluwa
 * Created on October 24, 2024
 * Purpose: Manage employee payroll 
 */

// System Libraries
#include <iostream>  // Input/Output Library
#include <string>    // String Library
#include <iomanip>   // Manipulating output formats
#include <sstream>   // String stream for converting numbers to words
using namespace std;

// User Libraries
struct Emp {     // Structure for Employee
    string name; // Employee name
    float hrs;   // Hours worked
    float rate;  // Rate of pay
    float grs;   // Gross pay
};

// Function Prototypes
void getCmp(string& name, string& addr); // Input company info
void getEmp(Emp* emp, int num);          // Input employee data
void calGrs(Emp* emp, int num);          // Calculate gross pay
void prtChk(Emp* emp, int num, const string& cmpName, const string& cmpAddr); // Print paychecks
string numWrd(int num); // Convert numbers to words

// Execution Begins Here!
int main() {
    int numEmp;
    string cmpName, cmpAddr;
    
    // Get company information
    getCmp(cmpName, cmpAddr);

    cout << "Enter the number of employees: ";
    cin >> numEmp;

    // Dynamic allocation of employee array
    Emp* emps = new Emp[numEmp];

    // Input employee data
    getEmp(emps, numEmp);
    
    // Calculate gross pay for each employee
    calGrs(emps, numEmp);
    
    // Print paychecks with company details
    prtChk(emps, numEmp, cmpName, cmpAddr);

    // Clean up dynamically allocated memory
    delete[] emps;

    return 0;
}

// Function to input company name and address
void getCmp(string& name, string& addr) {
    cout << "Enter company name: ";
    cin.ignore();  // Clear newline from buffer
    getline(cin, name);
    
    cout << "Enter company address: ";
    getline(cin, addr);
}

// Input employee data
void getEmp(Emp* emp, int num) {
    for (int i = 0; i < num; i++) {
        cout << "Enter name for employee " << (i + 1) << ": ";
        cin.ignore(); // Clear newline
        getline(cin, emp[i].name);

        do {
            cout << "Enter hours worked for " << emp[i].name << ": ";
            cin >> emp[i].hrs;
            if (emp[i].hrs < 0) {
                cout << "Invalid input!" << endl;
            }
        } while (emp[i].hrs < 0);

        do {
            cout << "Enter rate of pay for " << emp[i].name << ": $";
            cin >> emp[i].rate;
            if (emp[i].rate < 0) {
                cout << "Invalid input!" << endl;
            }
        } while (emp[i].rate < 0);
    }
}

// Calculate gross pay for each employee
void calGrs(Emp* emp, int num) {
    for (int i = 0; i < num; i++) {
        float totHrs = emp[i].hrs;
        emp[i].grs = 0.0;

        if (totHrs <= 20) {
            emp[i].grs = totHrs * emp[i].rate;
        } else if (totHrs <= 40) {
            emp[i].grs = (20 * emp[i].rate) + ((totHrs - 20) * emp[i].rate * 2);
        } else {
            emp[i].grs = (20 * emp[i].rate) + (20 * emp[i].rate * 2) + ((totHrs 
                    - 40) * emp[i].rate * 3);
        }
    }
}

// Print paychecks with company details for each employee
void prtChk(Emp* emp, int num, const string& cmpName, const string& cmpAddr) {
    cout << "\n--- Company Paychecks ---" << endl;

    for (int i = 0; i < num; i++) {
        cout << "\nCompany Name: " << cmpName << endl;
        cout << "Address: " << cmpAddr << endl;
        cout << "Name: " << emp[i].name << endl;
        cout << "Amount: $" << fixed << setprecision(2) << emp[i].grs << endl;
        cout << "Amount in words: " << numWrd(static_cast<int>(emp[i].grs)) << 
                " dollars" << endl;
        cout << "Signature Line: ___________________________" << endl;
    }
}

// Convert numbers to English words
string numWrd(int num) {
    if (num == 0) return "zero";
    if (num < 0) return "negative " + numWrd(-num);
    
    string words;
    string belowTwenty[] = {"", "one", "two", "three", "four", "five", "six", 
                            "seven", "eight", "nine", "ten", "eleven", "twelve",
                            "thirteen", "fourteen", "fifteen", "sixteen",
                            "seventeen", "eighteen", "nineteen"};
    string tens[] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", 
                     "seventy", "eighty", "ninety"};
    
    if (num >= 1000) {
        words += belowTwenty[num / 1000] + " thousand ";
        num %= 1000;
    }
    if (num >= 100) {
        words += belowTwenty[num / 100] + " hundred";
        num %= 100;
        if (num > 0) words += " and ";
    }
    if (num >= 20) {
        words += tens[num / 10];
        num %= 10;
        if (num > 0) words += "-" + belowTwenty[num];
    } else if (num > 0) {
        words += belowTwenty[num];
    }
    
    return words;
}
