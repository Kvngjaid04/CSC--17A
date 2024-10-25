/*
 * Author: Ireoluwa
 * Created on October 25, 2024
 * Purpose: Midterm project for CSC 17a
 */

// System Libraries
#include <iostream>  // Input/Output Library
#include <string>    // String Library
#include <iomanip>   // Manipulating output formats
#include <sstream>   // String stream for converting numbers to words
#include <cmath>     // Math Library
#include <limits>
using namespace std;

// User Libraries
struct Cstmr {             // Structure for Customer
    int accNum;            // Account number
    string name;           // Customer name
    string addr;           // Customer address
    float bal;             // Balance
    float* chks;           // Dynamic array for checks
    int numChks;           // Number of checks written
    float* deps;           // Dynamic array for deposits
    int numDeps;           // Number of deposits credited
};
struct Emp {               // Structure for Employee
    string name;           // Employee name
    float hrs;             // Hours worked
    float rate;            // Rate of pay
    float grs;             // Gross pay
};
struct Prime {
    unsigned char power;     // Power associated with the prime number
    unsigned short prime;    // Prime number factor
};
struct Primes {
    unsigned short n;        // Number to factor into Primes
    unsigned char nPrimes;   // Number of Primes
    Prime *pStrAry;         // The Prime Structure Array
};

// Function Prototypes
void problem1();                  // Prototype for Problem 1
void problem2();                  // Prototype for problem 2
void problem4();                  // Prototype for problem 4
void problem5();                  // Prototype for problem 5
void problem6();                  // Prototype for problem 6
void problem7();                  // Prototype for problem 7
            // problem 1
void inptCtm(Cstmr& c);            
void inptChk(Cstmr& c);
void inptDps(Cstmr& c);
void calcBal(Cstmr& c);
void dspyCtm(const Cstmr& c);
void cleanUp(Cstmr& c);
            // Problem 2
void getCmp(string& name, string& addr);        
void getEmp(Emp* emp, int num);
void calGrs(Emp* emp, int num);
void prtChk(Emp* emp, int num, const string& cmpName, const string& cmpAddr);
string numWrd(int num);
            // Problem 4
void encrypt(const string &input);      
void decrypt(const string &input);
bool validateInput(const string &input);
            // problem 5
unsigned long long factorial(int n);
            // Problem 7
Primes* factor(int num);
void prtPrms(const Primes* primes);
void cleanUp(Primes* primes);
bool isPrime(int num);
int power(int prime, int& num);
int nPrimes(int num);

int main() {
    int choice;
    do {
        // Display the menu
        cout << "Select a problem to execute (1-7) or 8 to exit:" << endl;
        cout << "1. Customer Checking Account" << endl;
        cout << "2. Employee Gross Pay" << endl;
        cout << "3. Statistics (Mean, Median, Mode)" << endl;
        cout << "4. Data Encryption" << endl;
        cout << "5. Factorial Exploration" << endl;
        cout << "6. NASA Float Conversion" << endl;
        cout << "7. Prime Factorization" << endl;
        cout << "8. Exit" << endl;
        cout << endl; cin >> choice; cout << endl;

        // Call the corresponding function based on user input
        switch (choice) {
            case 1:
                problem1(); 
                cout << "\n\n";                                          break;
            case 2:
                problem2(); 
                cout << "\n\n";                                          break;
            case 3:
                cout << "It is included in another project"; 
                cout << "\n\n";                                          break;
            case 4:
                problem4();
                cout << "\n\n";                                          break;
            case 5:
                problem5();
                cout << "\n\n";                                          break;
            case 6:
                cout << "It is included in another project";  
                cout << "\n\n";                                          break;
            case 7:
                problem7();                                       
                cout << "\n\n";                                          break;
            case 8:
                exit(0);              
            default:
                cout << "Invalid choice. Please select a valid option.";
                cout << "\n\n";                                          break;
        }
    } while (choice != 0);

    return 0;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 1
//Input:  -> Customer Information
//Output: -> Updated account balance with customer information 
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void problem1() {
    Cstmr customer; // Customer structure

    // Input customer data
    inptCtm(customer);
    
    // Input checks
    inptChk(customer);
    
    // Input deposits
    inptDps(customer);
    
    // Calculate the new balance
    calcBal(customer);
    
    // Display the customer data
    dspyCtm(customer);
    
    // Clean up dynamically allocated memory
    cleanUp(customer);
}

// Input customer data
void inptCtm(Cstmr& c) {
    do {
        cout << "Enter account number: ";
        cin >> c.accNum;
    } while (c.accNum < 10000 || c.accNum > 99999); // Validate 5 digits

    cin.ignore(); // Clear the newline character 
    cout << "Enter name: ";
    getline(cin, c.name);
    
    cout << "Enter address: ";
    getline(cin, c.addr);
    
    cout << "Enter balance at the beginning of the month: $";
    cin >> c.bal;

    c.numChks = 0;
    c.numDeps = 0;
    c.chks = nullptr;
    c.deps = nullptr;
}

// Input checks written
void inptChk(Cstmr& c) {
    float chk;
    
    do {
        cout << "Enter check amount written (enter a negative amount to stop): $";
        cin >> chk;
        if (chk >= 0) {
            // Increase the size of the dynamic array
            float* temp = new float[c.numChks + 1];
            for (int i = 0; i < c.numChks; i++) {
                temp[i] = c.chks[i];
            }
            temp[c.numChks] = chk; 
            delete[] c.chks;
            c.chks = temp; 
            c.numChks++; 
        }
    } while (chk >= 0);
}

// Input deposits credited
void inptDps(Cstmr& c) {
    float dep;
    
    do {
        cout << "Enter deposit amount (enter a negative amount to stop): ";
        cin >> dep;
        if (dep >= 0) {
            // Increase the size of the dynamic array
            float* temp = new float[c.numDeps + 1];
            for (int i = 0; i < c.numDeps; i++) {
                temp[i] = c.deps[i];
            }
            temp[c.numDeps] = dep;
            delete[] c.deps;
            c.deps = temp; 
            c.numDeps++; 
        }
    } while (dep >= 0);
}

// Calculate the new balance
void calcBal(Cstmr& c) {
    float totalChks = 0;
    float totalDeps = 0;

    // Calculate total checks written
    for (int i = 0; i < c.numChks; i++) {
        totalChks += c.chks[i];
    }
    
    // Calculate total deposits credited
    for (int i = 0; i < c.numDeps; i++) {
        totalDeps += c.deps[i];
    }

    // Calculate new balance
    c.bal = c.bal + totalDeps - totalChks;

    // Check for overdraft
    if (c.bal < 0) {
        cout << endl << "Overdraft! Your balance is negative." << endl;
        c.bal -= 35; // Apply $35 overdraft fee
        cout << "An additional $35 fee has been applied." << endl;
        cout << "New balance with fee included: $" << 
                fixed << setprecision(2) << c.bal << endl;
    } else {
        cout << endl << "Your new balance is: $" << fixed 
             << setprecision(2) << c.bal << endl;
    }
}

// Display customer data
void dspyCtm(const Cstmr& c) {
    cout << "\n--- Customer Information ---" << endl;
    cout << "Account Number: " << c.accNum << endl;
    cout << "Name: " << c.name << endl;
    cout << "Address: " << c.addr << endl;
    cout << "Balance: $" << fixed << setprecision(2) << c.bal << endl;

    // Display checks
    cout << "Checks Written: ";
    for (int i = 0; i < c.numChks; i++) {
        cout << "$" << fixed << setprecision(2) << c.chks[i] << " ";
    }
    cout << endl;

    // Display deposits
    cout << "Deposits Credited: ";
    for (int i = 0; i < c.numDeps; i++) {
        cout << "$" << fixed << setprecision(2) << c.deps[i] << " ";
    }
    cout << endl;
}

// Clean up dynamically allocated memory
void cleanUp(Cstmr& c) {
    delete[] c.chks;
    delete[] c.deps;
}


//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 2
//Input:  -> Company name and address
//         -> Number of employees
//         -> Each employee's name, hours worked (>=0), and pay rate (>=0)
//Output: -> Paychecks for each employee showing:
//         -> Gross pay calculated with overtime rates
//         -> Amount in both numbers and words
//         -> Company details and signature line
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890

void problem2() {
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
}

void getCmp(string& name, string& addr) {
    cout << "Enter company name: ";
    cin.ignore();  // Clear newline from buffer
    getline(cin, name);
    
    cout << "Enter company address: ";
    getline(cin, addr);
}

void getEmp(Emp* emp, int num) {
    for (int i = 0; i < num; i++) {
        cout << "Enter name for employee " << (i + 1) << ": ";
        cin.ignore(i == 0 ? 0 : numeric_limits<streamsize>::max(), '\n');
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

void calGrs(Emp* emp, int num) {
    for (int i = 0; i < num; i++) {
        float totHrs = emp[i].hrs;
        emp[i].grs = 0.0;

        if (totHrs <= 20) {
            emp[i].grs = totHrs * emp[i].rate;
        } else if (totHrs <= 40) {
            emp[i].grs = (20 * emp[i].rate) + ((totHrs - 20) * emp[i].rate * 2);
        } else {
            emp[i].grs = (20 * emp[i].rate) + (20 * emp[i].rate * 2) + 
                        ((totHrs - 40) * emp[i].rate * 3);
        }
    }
}

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

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 4
//Input:  -> Four-digit integer or decryption
//Output: -> Encrypted / Decrypted four-digit integer where:
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890

void problem4() {
    char choice;
    string number;
    cout << "Would you like to (E)ncrypt or (D)ecrypt? ";
    cin >> choice;
    
    if (toupper(choice) == 'E') {
        cout << "Enter a four-digit integer to encrypt: ";
        cin >> number;
        
        if (!validateInput(number)) {
            cout << "Invalid input. Only digits 0-7 are allowed." << endl;
            return;
        }
        encrypt(number);
    }
    else if (toupper(choice) == 'D') {
        cout << "Enter a four-digit encrypted integer: ";
        cin >> number;
        
        if (!validateInput(number)) {
            cout << "Invalid input. Only digits 0-7 are allowed." << endl;
            return;
        }
        decrypt(number);
    }
    else {
        cout << "Invalid choice." << endl;
    }
}

bool validateInput(const string &input) {
    if (input.length() != 4) return false; // Ensure it's a four-digit number
    
    for (char c : input) {
        if (c < '0' || c > '7') {
            return false; // Check if each character is between 0-7
        }
    }
    return true;
}

void encrypt(const string &input) {
    int encryptedDigits[4];
    
    // Encrypt each digit
    for (int i = 0; i < 4; ++i) {
        encryptedDigits[i] = (input[i] - '0' + 6) % 8; // Replace and encrypt
    }
    
    // Swap digits
    swap(encryptedDigits[0], encryptedDigits[2]); // Swap 1st and 3rd
    swap(encryptedDigits[1], encryptedDigits[3]); // Swap 2nd and 4th
    
    // Output the encrypted integer
    cout << "Encrypted integer: ";
    for (int i = 0; i < 4; ++i) {
        cout << encryptedDigits[i];
    }
    cout << endl;
}

void decrypt(const string &input) {
    int decryptedDigits[4];
    
    // Decrypt by reversing the process
    for (int i = 0; i < 4; ++i) {
        decryptedDigits[i] = (input[i] - '0' + 2) % 8; // Inverse operation
    }
    
    // Swap back digits
    swap(decryptedDigits[0], decryptedDigits[2]); // Swap 1st and 3rd
    swap(decryptedDigits[1], decryptedDigits[3]); // Swap 2nd and 4th
    
    // Output the decrypted integer
    cout << "Decrypted integer: ";
    for (int i = 0; i < 4; ++i) {
        cout << decryptedDigits[i];
    }
    cout << endl;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 5
//Output: -> Maximum n for factorial calculations (n!) for Data Types
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890

void problem5() {
    cout << "Largest n for different data types calculating n!:\n\n";
    
    // Byte
    cout << "Largest n for Signed Byte: " << 5 << " (5! = " << factorial(5) << ")\n";
    cout << "Largest n for Unsigned Byte: " << 5 << " (5! = " << factorial(5) << ")\n\n";
    
    // Short
    cout << "Largest n for Signed Short: " << 7 << " (7! = " << factorial(7) << ")\n";
    cout << "Largest n for Unsigned Short: " << 8 << " (8! = " << factorial(8) << ")\n\n";
    
    // Int
    cout << "Largest n for Signed Int: " << 12 << " (12! = " << factorial(12) << ")\n";
    cout << "Largest n for Unsigned Int: " << 13 << " (13! = " << factorial(13) << ")\n\n";
    
    // Long
    cout << "Largest n for Signed Long: " << 20 << " (20! = " << factorial(20) << ")\n";
    cout << "Largest n for Unsigned Long: " << 20 << " (20! = " << factorial(20) << ")\n\n";
    
    // Long Long
    cout << "Largest n for Signed Long Long: " << 20 << " (20! = " << factorial(20) << ")\n";
    cout << "Largest n for Unsigned Long Long: " << 20 << " (20! = " << factorial(20) << ")\n\n";
    
    // Float (up to 34)
    cout << "Largest n for Float: " << 34 << "\n\n";
    
    // Double (up to 170)
    cout << "Largest n for Double: " << 170 << "\n";
    
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
//                         Problem 7
//Input:  -> Integer between 2 and 65000 to factorize
//Output: -> Prime factorization in the form: n = p1^a × p2^b × p3^c
//000000011111111112222222222333333333344444444445555555555666666666677777777778
//345678901234567890123456789012345678901234567890123456789012345678901234567890
void problem7() {
    int number;

    // Input validation
    do {
        cout << "Enter a number between 2 and 65000 to factorize: ";
        cin >> number;
    } while (number < 2 || number > 65000);

    // Factor the number
    Primes* result = factor(number);

    // Print the results
    prtPrms(result);

    // Clean up
    cleanUp(result);

    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

bool isPrime(int num) {
    if (num < 2) return false;
    if (num == 2) return true;
    if (num % 2 == 0) return false;

    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

int power(int prime, int& num) {
    int pow = 0;
    while (num % prime == 0) {
        pow++;
        num /= prime;
    }
    return pow;
}

int nPrimes(int num) {
    int count = 0;
    int temp = num;

    for (int i = 2; i <= temp && temp > 1; i++) {
        if (isPrime(i) && temp % i == 0) {
            count++;
            while (temp % i == 0) {
                temp /= i;
            }
        }
    }
    return count;
}

Primes* factor(int num) {
    Primes* result = new Primes;
    result->n = num;
    result->nPrimes = nPrimes(num);
    result->pStrAry = new Prime[result->nPrimes];

    int temp = num;
    int index = 0;

    for (int i = 2; i <= temp && temp > 1; i++) {
        if (isPrime(i) && temp % i == 0) {
            result->pStrAry[index].prime = i;
            result->pStrAry[index].power = power(i, temp);
            index++;
        }
    }

    return result;
}

void prtPrms(const Primes* primes) {
    cout << primes->n << " = ";

    for (int i = 0; i < primes->nPrimes; i++) {
        cout << primes->pStrAry[i].prime;
        cout << "^" << static_cast<int>(primes->pStrAry[i].power);
        
        if (i < primes->nPrimes - 1) {
            cout << " × ";
        }
    }
    cout << endl;
}

void cleanUp(Primes* primes) {
    if (primes) {
        delete[] primes->pStrAry;
        delete primes;
    }
}