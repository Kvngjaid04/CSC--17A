/**
* @file Player.h
* @author Ireoluwa Dairo
* @brief Base player class and derived player types for blackjack
* @date 2024-11-27
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Card.h"
#include "PlayerStats.h"

using namespace std;

/**
* @class Player
* @brief Abstract base class for blackjack players
* Defines common functionality for managing hands, bets, funds and statistics
*/
class Player {
public:
   /** @brief Default constructor */
   Player();

   /**
    * @brief Constructor with name and initial funds
    * @param name Player's name
    * @param funds Initial funds (defaults to 1000)
    */
   Player(const string& name, int funds = 1000);

   /** @brief Virtual destructor */
   virtual ~Player();
   
   /**
    * @brief Pure virtual method for hit/stand decision
    * @return bool True if player wants another card
    */
   virtual bool wantHit() = 0;

   /** @brief Pure virtual method to display player's hand */
   virtual void dispHand() const = 0;
   
   /**
    * @brief Add card to player's hand
    * @param card Card to add
    */
   virtual void addCard(const Card& card);

   /**
    * @brief Calculate hand value
    * @return int Total value of cards in hand
    */
   virtual int getVal() const;

   /**
    * @brief Check if hand value exceeds 21
    * @return bool True if player has bust
    */
   virtual bool isBust() const;

   /** @brief Clear player's hand */
   virtual void clear();
   
   /**
    * @brief Set bet amount
    * @param amt Bet amount
    * @return bool True if bet is valid and set
    */
   bool setBet(int amt);

   /**
    * @brief Add winnings to funds
    * @param amt Amount won
    */
   void addWin(int amt);

   /**
    * @brief Deduct lost bet from funds
    * @param amt Amount lost
    */
   void loseBet(int amt);

   /**
    * @brief Set player's funds
    * @param amt New fund amount
    */
   void setFund(int amt);
   
   /**
    * @brief Record game result in stats
    * @param won Whether game was won
    * @param amt Amount won/lost
    */
   void addGame(bool won, int amt);

   /** @brief Get win rate from stats
    * @return int Win percentage
    */
   int getRate() const;

   /**
    * @brief Get player statistics
    * @return PStats& Reference to player stats
    */
   PStats& getStat();
   
   /** @brief Get player's name
    * @return string Player name
    */
   string getName() const;

   /** @brief Get current funds
    * @return int Available funds
    */
   int getFund() const;

   /** @brief Get current bet
    * @return int Current bet amount
    */
   int getBet() const;
   
   /**
    * @brief Equality comparison
    * @param other Player to compare with
    * @return bool True if players are equal
    */
   bool operator==(const Player& other) const;

   /**
    * @brief Inequality comparison
    * @param other Player to compare with
    * @return bool True if players are not equal
    */
   bool operator!=(const Player& other) const;
   
protected:
   string name;        /**< Player's name */
   vector<Card> hand;  /**< Current hand of cards */
   int funds;         /**< Available funds */
   int bet;          /**< Current bet amount */
   PStats stats;     /**< Player statistics */
};

/**
* @class Human
* @brief Human player class
* Implements interactive player decisions
*/
class Human : public Player {
public:
   /**
    * @brief Constructor
    * @param name Player's name
    */
   Human(const string& name);

   bool wantHit() override;
   void dispHand() const override;
};

/**
* @class Dealer
* @brief Dealer class
* Implements dealer-specific logic and display
*/
class Dealer : public Player {
public:
   /** @brief Constructor */
   Dealer();

   bool wantHit() override;
   void dispHand() const override;

   /** @brief Display all cards in dealer's hand */
   void showAll() const;
};

#endif