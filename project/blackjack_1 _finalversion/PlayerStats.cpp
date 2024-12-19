/**
* @file PlayerStats.cpp
* @author Ireoluwa Dairo
* @brief Implementation of player statistics tracking
* @date 2024-11-27
*/

#include "PlayerStats.h"
#include <stdexcept>

/** Initialize static counter for statistics objects */
int PStats::num = 0;

/**
* @brief Constructor
* @param maxSz Maximum number of game results to store
* @throws runtime_error if memory allocation fails
*/
PStats::PStats(int maxSz) {
   try {
       res = new GameRes[maxSz];
       max = maxSz;
       size = 0;
       rate = 0;
       games = 0;
       wins = 0;
       num++;
   } catch (bad_alloc& ba) {
       throw runtime_error("Memory fail");
   }
}

/**
* @brief Copy constructor
* @param old PStats object to copy from
* @throws runtime_error if memory allocation fails
*/
PStats::PStats(const PStats& old) {
   try {
       res = new GameRes[old.max];
       max = old.max;
       size = old.size;
       rate = old.rate;
       games = old.games;
       wins = old.wins;
       
       for(int i = 0; i < size; i++) {
           res[i] = old.res[i];
       }
       num++;
   } catch (bad_alloc& ba) {
       throw runtime_error("Copy fail");
   }
}

/**
* @brief Destructor
* Frees allocated memory and decrements counter
*/
PStats::~PStats() {
   delete[] res;
   num--;
}

/**
* @brief Assignment operator
* @param rhs PStats to assign from
* @return PStats& Reference to this object
* @throws runtime_error if memory allocation fails
*/
PStats& PStats::operator=(const PStats& rhs) {
   if(this != &rhs) {
       try {
           delete[] res;
           res = new GameRes[rhs.max];
           max = rhs.max;
           size = rhs.size;
           rate = rhs.rate;
           games = rhs.games;
           wins = rhs.wins;
           
           for(int i = 0; i < size; i++) {
               res[i] = rhs.res[i];
           }
       } catch (bad_alloc& ba) {
           throw runtime_error("Set fail");
       }
   }
   return *this;
}

/**
* @brief Set total games and wins
* @param gms Total games
* @param wns Total wins
*/
void PStats::setAll(int gms, int wns) {
   games = gms;
   wins = wns;
   if(games > 0) {
       rate = (wins * 100) / games;
   } else {
       rate = 0;
   }
}

/**
* @brief Get games and wins stats
* @return Stats Structure containing games and wins
*/
Stats PStats::getAll() const {
   return {games, wins};
}

/**
* @brief Add new game result
* @param newRes Game result to add
* @throws runtime_error if results array is full
*/
void PStats::add(const GameRes& newRes) {
   if(size >= max) {
       throw runtime_error("Stats full");
   }
   
   res[size++] = newRes;
   games++;
   if(newRes.isWin()) {
       wins++;
   }
   
   if(games > 0) {
       rate = (wins * 100) / games;
   }
}

/**
* @brief Get win rate percentage
* @return int Win rate as percentage
*/
int PStats::getRate() const {
   return rate;
}

/**
* @brief Less than comparison operator
* @param rhs PStats to compare with
* @return bool True if this win rate is less than rhs
*/
bool PStats::operator<(const PStats& rhs) const {
   return rate < rhs.rate;
}

/**
* @brief Addition operator
* @param rhs PStats to add
* @return PStats Combined statistics
*/
PStats PStats::operator+(const PStats& rhs) const {
   PStats tmp(max + rhs.max);
   tmp.size = 0;
   tmp.rate = (rate + rhs.rate) / 2;
   
   for(int i = 0; i < size; i++) {
       tmp.res[tmp.size++] = res[i];
   }
   for(int i = 0; i < rhs.size; i++) {
       tmp.res[tmp.size++] = rhs.res[i];
   }
   
   return tmp;
}