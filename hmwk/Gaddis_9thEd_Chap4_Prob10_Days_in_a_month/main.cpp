/*
 * Author: Ireoluwa
 * Created on August 25, 2024, 9:00 AM
 * Purpose: Determine the number of days in a given month and year
 */

//System Libraries
#include <iostream>
using namespace std;

//Function Prototypes

//Execution Begins here
int main(int argc, char** argv) {
    //Declaring Variables
    int month,   // Input -> Month (1-12)
        year,    // Input -> Year
        days;    // Output -> Number of days in the month
    
    //Input
    cout << "Enter a month (1-12): ";
    cin >> month;
    cout << "Enter a year: ";
    cin >> year;
    
    // Determine if the year is a leap year
    bool isLeap = (year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0));
    
    //Determine the number of days in the given month
    switch (month) {
        case 1:  // January
        case 3:  // March
        case 5:  // May
        case 7:  // July
        case 8:  // August
        case 10: // October
        case 12: // December
            days = 31;
            break;
        case 4:  // April
        case 6:  // June
        case 9:  // September
        case 11: // November
            days = 30;
            break;
        case 2:  // February
            days = isLeap ? 29 : 28;
            break;
        default:
            cout << "Invalid month entered." << endl;
            exit(0); // Exit with error code
    }
    
    //Output
    cout << days << " days" << endl;
    
    //Exiting stage left
    return 0;
}
