/*
 * Author: Ireoluwa
 * Created on August 31, 2024, 12:00 PM
 * Purpose: Track weather conditions over three months and generate a weather report
 */

//System Libraries
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

//Function Prototypes
void readWeather(const char* fname, char weather[3][30]);
void generateReport(const char weather[3][30]);

//Execution Begins here
int main() {
    //Declaring Variables
    char weather[3][30];
    
    //Initialize Variables
    readWeather("RainOrShine.txt", weather);
    
    //Processing/Mapping Inputs to Outputs
    generateReport(weather);
    
    //Exiting stage left/right
    return 0;
}

//Function Definitions
void readWeather(const char* fname, char weather[3][30]) {
    ifstream file(fname);
    
    // Check if file opened successfully
    if (!file.is_open()) {
        cout << "Error: Unable to open file " << fname << endl;
        exit(1);
    }
    
    for (int m = 0; m < 3; ++m) {
        for (int d = 0; d < 30; ++d) {
            file >> weather[m][d];
        }
    }
    
    file.close();
}

void generateReport(const char weather[3][30]) {
    int rain[3] = {0};
    int cloud[3] = {0};
    int sun[3] = {0};
    int totalRain = 0;
    int totalCloud = 0;
    int totalSun = 0;
    int maxRainMonth = 0;

    for (int m = 0; m < 3; ++m) {
        for (int d = 0; d < 30; ++d) {
            switch (weather[m][d]) {
                case 'R':
                    rain[m]++;
                    totalRain++;
                    break;
                case 'C':
                    cloud[m]++;
                    totalCloud++;
                    break;
                case 'S':
                    sun[m]++;
                    totalSun++;
                    break;
            }
        }
        
        if (rain[m] > rain[maxRainMonth]) {
            maxRainMonth = m;
        }
    }
    
    cout << fixed << setprecision(0);  // No decimal places needed
    cout << setw(15) << "Month" << setw(15) << "Rainy" << setw(15) 
            << "Cloudy" << setw(15) << "Sunny" << endl;
    cout << "----------------------------------------" << endl;
    
    for (int m = 0; m < 3; ++m) {
        cout << setw(15) << (m == 0 ? "June" : (m == 1 ? "July" : "August")) 
             << setw(15) << rain[m] 
             << setw(15) << cloud[m] 
             << setw(15) << sun[m] 
             << endl;
    }
    
    cout << "----------------------------------------" << endl;
    cout << setw(15) << "Total" << setw(15) << totalRain << setw(15) << totalCloud << setw(15) << totalSun << endl;
    cout << "Month with most rainy days: " 
         << (maxRainMonth == 0 ? "June" : (maxRainMonth == 1 ? "July" : "August")) 
         << endl;
}
