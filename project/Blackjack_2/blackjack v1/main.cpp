/* 
 * File:   main.cpp
 * Author: Ireoluwa Dairo
 *
 * Created on November 27, 2024, 3:44 PM
 */

#include <cstdlib>
#include "BlackjackGame.h"
#include <iostream>
using namespace std;

// Optional test function to demonstrate friend and exception handling
void runBlackjackTest() {
    try {
        // Get singleton instance
        Game& game = Game::get();
        
        // Run a test game
        game.start();
    }
    catch (const exception& e) {
        cerr << "Test failed: " << e.what() << endl;
    }
}

int main() {
    try {
        // Create and start the Blackjack game
        Game& game = Game::get();
        game.start();
    }
    catch (const exception& e) {
        cerr << "Game encountered an error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}