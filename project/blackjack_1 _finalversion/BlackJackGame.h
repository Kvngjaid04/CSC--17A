/**
 * @file BlackJackGame.h
 * @author Ireoluwa Dairo
 * @brief Main game controller class for Blackjack card game
 * @date 2024-11-27
 */

#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Deck.h"
#include "Player.h"
#include "SaveGame.h"
#include <memory>

using namespace std;

/**
 * @class Game
 * @brief Main controller class implementing Blackjack game logic
 * 
 * This class implements the Singleton pattern and manages the complete
 * lifecycle of a Blackjack game including player turns, dealer actions,
 * betting, and game state persistence.
 */
class Game {
public:
    /**
     * @brief Get the single instance of the Game class
     * @return Game& Reference to the singleton game instance
     */
    static Game& get();
    
    /**
     * @brief Starts a new game session
     * 
     * Initializes game components and begins the main game loop.
     */
    void start();
    
    // Delete copy/move operations to ensure singleton pattern
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
    
private:
    /**
     * @brief Private constructor for singleton pattern
     */
    Game();

    /**
     * @brief Destructor
     */
    ~Game();
    
    /**
     * @brief Initialize game components and settings
     */
    void init();

    /**
     * @brief Load a previously saved game state
     */
    void loadGame();

    /**
     * @brief Initialize and start a new game
     */
    void newGame();

    /**
     * @brief Execute the main game loop
     */
    void mainLoop();

    /**
     * @brief Execute one complete round of Blackjack
     */
    void round();

    /**
     * @brief Deal initial cards to player and dealer
     */
    void deal();

    /**
     * @brief Handle player's turn including hit/stand decisions
     */
    void plyrTurn();

    /**
     * @brief Handle dealer's turn according to house rules
     */
    void dlrTurn();

    /**
     * @brief Process end of round including determining winner and paying bets
     */
    void endRound();

    /**
     * @brief Get bet amount from player
     * @return int The amount bet by the player
     */
    int getBet();

    /**
     * @brief Save current game state
     */
    void saveGame();
    
    /** @brief Deck of cards used in the game */
    Deck<Card> deck;

    /** @brief Pointer to human player object */
    unique_ptr<Human> plyr;

    /** @brief Pointer to dealer object */
    unique_ptr<Dealer> dlr;

    /** @brief Current player's username */
    string user;

    /** @brief Save game data handler */
    Save save;
    
    /** @brief Pointer to singleton instance */
    static Game* inst;
};

#endif