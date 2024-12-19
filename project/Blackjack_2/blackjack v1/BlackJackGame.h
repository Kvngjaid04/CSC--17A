/* 
 * File:   BlackJackGame.h
 * Author: Ireoluwa Dairo
 *
 * Created on November 27, 2024, 3:52 PM
 */

#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Deck.h"
#include "Player.h"
#include "SaveGame.h"
#include <memory>
using namespace std;

class Game {
public:
    // Get singleton instance
    static Game& get();
    
    // Start game session
    void start();
    
    // Delete copy/move operations
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
    
private:
    // Constructor/Destructor
    Game();
    ~Game();
    
    // Game flow methods
    void init();         // Initialize game
    void loadGame();     // Load saved game
    void newGame();      // Start new game
    void mainLoop();     // Main game loop
    void round();        // Play one round
    void deal();         // Deal initial cards
    void plyrTurn();     // Player's turn
    void dlrTurn();      // Dealer's turn
    void endRound();     // Handle round end
    int getBet();        // Get bet amount
    void saveGame();     // Save current game
    
    // Game components
    Deck<Card> deck;                // Card deck - specify Card as template parameter
    unique_ptr<Human> plyr;         // Player
    unique_ptr<Dealer> dlr;         // Dealer
    string user;                    // Username
    Save save;                      // Save data
    
    static Game* inst;              // Singleton instance
};
#endif