/**
* @file main.cpp
* @author Ireoluwa Dairo
* @brief Main entry point for Blackjack game
* @date 2024-11-27
*/

#include <cstdlib>
#include "BlackjackGame.h"
#include <iostream>
using namespace std;

/**
* @brief Test function demonstrating friend functionality and exception handling
* @details Creates a game instance and runs a test session
*/
void runBlackjackTest() {
   try {
       Game& game = Game::get();
       game.start();
   }
   catch (const exception& e) {
       cerr << "Test failed: " << e.what() << endl;
   }
}

/**
* @brief Main program entry point
* @return int Exit status (0 for success, 1 for error)
*/
int main() {
   try {
       Game& game = Game::get();
       game.start();
   }
   catch (const exception& e) {
       cerr << "Game encountered an error: " << e.what() << endl;
       return 1;
   }
   
   return 0;
}