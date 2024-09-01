/*
 * Author: Ireoluwa
 * Created on August 31, 2024, 9:00 PM
 * Purpose: Calculate kinetic energy of an object
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Function Prototypes
void kineticEnergy( float, float, float& );

//Execution Begins Here
int main(int argc, char** argv) {
    // Declare Variables
    float mass,      // Input -> Mass of the object (in kilograms)
          velocity,  // Input -> Velocity of the object (in meters per second)
          ke;
    
    // Ask the user for mass and velocity
    cout << "Enter the mass of the object (in kilograms): ";
    cin >> mass;
    cout << "Enter the velocity of the object (in meters per second): ";
    cin >> velocity;
    
    // Call the kineticEnergy function and display the result
   kineticEnergy(mass, velocity, ke);
    cout << "The kinetic energy of the object is: " << ke << " Joules" << endl;
    
    // Exit program
    return 0;
}

// Function to calculate kinetic energy
void kineticEnergy(float mass, float velocity, float& ke) {
    ke = 0.5f * mass * velocity * velocity;
}