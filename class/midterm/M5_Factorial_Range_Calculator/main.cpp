/*
 * Author: Ireoluwa
 * Created on October 25, 2024
 * Purpose: To explore maximum n for factorial calculations using various data types.
 */

// Libraries
#include <iostream>
#include <limits>
using namespace std;

// Function Prototypes
unsigned long long factorial(int n);

// Execution begins here
int main() {
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
    cout << "Largest n for Double: " << 170;

    return 0;
}

// Function to calculate factorial
unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}