//System Libraries
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
void dispM(string, string, int, int);

//Execution Begins Here
int main(int argc, char** argv) {
    //Set Random Number seed
    
    //Declare Variable Data Types and Constants
    string titles[10], dirs[10];
    int years[10], mins[10], count;
    
    //Initialize Variables
    cout << "This program reviews structures" << endl;
    cout << "Input how many movies, the Title of the Movie, Director, Year "
            "Released, and the Running Time in (minutes)." << endl;
    cout << endl;
    cin >> count;
    cin.ignore();
    
    //Process or map Inputs to Outputs
    for (int i = 0; i < count && i < 10; i++) {
        getline(cin, titles[i]);
        getline(cin, dirs[i]);
        cin >> years[i];
        cin >> mins[i];
        cin.ignore();
    }
    
    //Display Outputs
    for (int i = 0; i < count && i < 10; i++) {
        dispM(titles[i], dirs[i], years[i], mins[i]);
        
        if (i < count - 1) cout << endl; // New line after each movie except the last
    }

    //Exit stage right!
    return 0;
}

//Function Implementations
void dispM(string title, string dir, int year, int mins) {
    cout << left;
    cout << setw(11) << "Title:" << title << endl;
    cout << setw(11) << "Director:" << dir << endl;
    cout << setw(11) << "Year:" << year << endl;
    cout << setw(11) << "Length:" << mins << endl;
}
