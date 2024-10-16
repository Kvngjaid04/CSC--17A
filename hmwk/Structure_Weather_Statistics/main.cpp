// System Libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

// Structure to hold weather data
struct Weather {
    string mth;      // Month name
    float rain;      // Total Rainfall in inches
    float high;      // High Temperature in °F
    float low;       // Low Temperature in °F
    float avgT;      // Average Temperature in °F
};

// Function prototypes
void getD(Weather* wthr);
void calcA(Weather* wthr);

int main() {
    // Array to hold weather data for 12 months
    Weather wthr[12];

    // Get weather data for each month
    getD(wthr);

    // Calculate and display results
    calcA(wthr);

    return 0;
}

// Function to get weather data from user
void getD(Weather* wthr) {
    for (int i = 0; i < 12; i++) {
        cin >> wthr[i].mth >> wthr[i].rain >> wthr[i].low >> wthr[i].high;

        // Input validation for high temperature
        while (wthr[i].high < -100 || wthr[i].high > 140) {
            cout << "Invalid input! Enter a high temperature between -100 and +140 °F: ";
            cin >> wthr[i].high;
        }

        // Input validation for low temperature
        while (wthr[i].low < -100 || wthr[i].low > 140) {
            cout << "Invalid input! Enter a low temperature between -100 and +140 °F: ";
            cin >> wthr[i].low;
        }

        // Calculate average temperature
        wthr[i].avgT = (wthr[i].high + wthr[i].low) / 2;
    }
}

// Function to calculate and display averages
void calcA(Weather* wthr) {
    float tRain = 0, tAvgT = 0;
    float hTemp = wthr[0].high, lTemp = wthr[0].low;
    string hMth = wthr[0].mth, lMth = wthr[0].mth;

    for (int i = 0; i < 12; i++) {
        tRain += wthr[i].rain;
        tAvgT += wthr[i].avgT;

        // Check for highest temperature
        if (wthr[i].high > hTemp) {
            hTemp = wthr[i].high;
            hMth = wthr[i].mth;
        }

        // Check for lowest temperature
        if (wthr[i].low < lTemp) {
            lTemp = wthr[i].low;
            lMth = wthr[i].mth;
        }
    }

    float avgR = tRain / 12;
    float avgMT = tAvgT / 12;

    // Display results
    cout << fixed << setprecision(1);
    cout << "Average Rainfall " << avgR << " inches/month" << endl;
    cout << "Lowest  Temperature " << lMth << "  " << static_cast<int>(lTemp) << " Degrees Fahrenheit" << endl;
    cout << "Highest Temperature " << hMth << "  " << static_cast<int>(hTemp) << " Degrees Fahrenheit" << endl;
    cout << "Average Temperature for the year " << static_cast<int>(round(avgMT))  << " Degrees Fahrenheit" << endl;
}
