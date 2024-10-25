/*
 * Author: Ireoluwa
 * Created on October 25, 2024
 * Purpose: Factor an input integer into its prime numbers.
 */

// Libraries
#include <iostream>
#include <cmath>
using namespace std;

// Structure definitions
struct Prime {
    unsigned char power;     // Power associated with the prime number
    unsigned short prime;    // Prime number factor
};

struct Primes {
    unsigned short n;        // Number to factor into Primes
    unsigned char nPrimes;   // Number of Primes
    Prime *pStrAry;         // The Prime Structure Array
};

// Function prototypes
Primes* factor(int num); // Factor the number into its primes
void prtPrms(const Primes* primes); // Print the prime factors
bool isPrime(int num); // Determine if the number is prime
int power(int prime, int& num); // Calculate the power of the prime factor
int nPrimes(int num); // Count how many distinct primes are there
void cleanUp(Primes* primes); // Clean up allocated memory

int main() {
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

    return 0;
}

// Function to determine if the number is prime
bool isPrime(int num) {
    if (num < 2) return false; // Numbers less than 2 are not prime
    if (num == 2) return true; // 2 is prime
    if (num % 2 == 0) return false; // Exclude even numbers greater than 2

    // Check only odd numbers up to square root
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) return false; // Found a divisor
    }
    return true; // Number is prime
}

// Function to calculate the power of the prime factor
int power(int prime, int& num) {
    int pow = 0; // Initialize power count
    while (num % prime == 0) {
        pow++; // Increment power count
        num /= prime; // Divide out the prime factor
    }
    return pow; // Return the power
}

// Function to count how many distinct primes are there
int nPrimes(int num) {
    int count = 0; // Initialize prime count
    int temp = num; // Temporary variable for factorization

    // Count number of prime factors
    for (int i = 2; i <= temp && temp > 1; i++) {
        if (isPrime(i) && temp % i == 0) {
            count++; // Found a distinct prime
            while (temp % i == 0) {
                temp /= i; // Remove all occurrences of the prime factor
            }
        }
    }
    return count; // Return the count of distinct primes
}

// Function to factor the number into its primes
Primes* factor(int num) {
    Primes* result = new Primes; // Allocate memory for Primes structure
    result->n = num; // Store the number to factor
    result->nPrimes = nPrimes(num); // Count distinct primes
    result->pStrAry = new Prime[result->nPrimes]; // Allocate memory for the prime array

    int temp = num; // Temporary variable for factorization
    int index = 0; // Index for prime array

    // Find prime factors and their powers
    for (int i = 2; i <= temp && temp > 1; i++) {
        if (isPrime(i) && temp % i == 0) {
            result->pStrAry[index].prime = i; // Store prime
            result->pStrAry[index].power = power(i, temp); // Store power
            index++; // Move to the next index
        }
    }

    return result; // Return the result
}

// Function to print the prime factors
void prtPrms(const Primes* primes) {
    cout << primes->n << " = ";

    // Print each prime factor with its power
    for (int i = 0; i < primes->nPrimes; i++) {
        cout << primes->pStrAry[i].prime; // Print the prime

        // Always print the power, even if it is 1
        cout << "^" << static_cast<int>(primes->pStrAry[i].power); 

        // Add multiplication symbol except for last factor
        if (i < primes->nPrimes - 1) {
            cout << " × ";
        }
    }
    cout << endl; // New line after printing all factors
}

// Function to clean up allocated memory
void cleanUp(Primes* primes) {
    if (primes) {
        delete[] primes->pStrAry; // Delete the prime array
        delete primes; // Delete the Primes structure
    }
}
