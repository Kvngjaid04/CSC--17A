/**
* @file PlayerStats.h
* @author Ireoluwa Dairo
* @brief Player statistics tracking implementation
* @date 2024-11-27
*/

#ifndef PLAYERSTATS_H
#define PLAYERSTATS_H

#include <string>
using namespace std;

/**
* @class GameRes
* @brief Represents the result of a single game
* Stores win/loss status and amount won/lost
*/
class GameRes {
public:
   /** 
    * @brief Get amount won/lost
    * @return int Amount from game result
    */
   inline int getAmt() const { return amt; }

   /**
    * @brief Check if game was won
    * @return bool True if game was won
    */
   inline bool isWin() const { return win; }
   
   /**
    * @brief Constructor
    * @param win Whether game was won
    * @param amt Amount won/lost
    */
   GameRes(bool win = false, int amt = 0) : win(win), amt(amt) {}
   
private:
   bool win; /**< Win/loss status */
   int amt;  /**< Amount won/lost */
};

/**
* @struct Stats
* @brief Simple structure holding game statistics
*/
struct Stats {
   int games; /**< Total games played */
   int wins;  /**< Total games won */
};

/**
* @class PStats
* @brief Player statistics manager
* Tracks game results and calculates statistics
*/
class PStats {
public:
   /**
    * @brief Constructor
    * @param max Maximum number of results to store
    */
   PStats(int max = 100);

   /**
    * @brief Copy constructor
    * @param other PStats to copy from
    */
   PStats(const PStats& other);

   /** @brief Destructor */
   ~PStats();
   
   /**
    * @brief Assignment operator
    * @param rhs PStats to assign from
    * @return PStats& Reference to this object
    */
   PStats& operator=(const PStats& rhs);

   /**
    * @brief Addition operator
    * @param rhs PStats to add
    * @return PStats Combined statistics
    */
   PStats operator+(const PStats& rhs) const;

   /**
    * @brief Less than operator
    * @param rhs PStats to compare with
    * @return bool True if this win rate is less than rhs
    */
   bool operator<(const PStats& rhs) const;
   
   /**
    * @brief Add game result
    * @param res Result to add
    */
   void add(const GameRes& res);

   /**
    * @brief Get win rate percentage
    * @return int Win rate as percentage
    */
   int getRate() const;

   /**
    * @brief Set total games and wins
    * @param games Total games
    * @param wins Total wins
    */
   void setAll(int games, int wins);

   /**
    * @brief Get all statistics
    * @return Stats Structure with games and wins
    */
   Stats getAll() const;
   
private:
   GameRes* res;  /**< Array of game results */
   int size;      /**< Current size of results array */
   int max;       /**< Maximum size of results array */
   int rate;      /**< Cached win rate */
   int games;     /**< Total games played */
   int wins;      /**< Total games won */
   static int num;/**< Static counter for all PStats instances */
   
   /** 
    * @brief Friend function to display all statistics
    * @param st PStats to display
    */
   friend void showAll(const PStats& st);
};

#endif