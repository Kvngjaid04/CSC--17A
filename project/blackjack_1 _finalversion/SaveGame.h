/**
* @file SaveGame.h
* @author Ireoluwa Dairo
* @brief Game state  implementation
* @date 2024-11-27
*/

#ifndef SAVEGAME_H
#define SAVEGAME_H

#include <string>
#include <fstream>
using namespace std;

/**
* @struct Save
* @brief Structure containing saveable game state data
*/
struct Save {
   char name[30];  /**< Player name */
   int funds;      /**< Current funds */
   int wins;       /**< Current session wins */
   int games;      /**< Current session games */
   int gmsAll;     /**< Total games played */
   int winsAll;    /**< Total games won */
};

/**
* @class SaveGame
* @brief Static class for managing game state persistence
*/
class SaveGame {
public:
   /**
    * @brief Load saved game data
    * @param data Save structure to load into
    * @param user Username to load data for
    * @return bool True if load successful
    */
   static bool load(Save& data, const string& user);

   /**
    * @brief Save current game data
    * @param data Save structure containing data to save
    * @param user Username to save data for
    * @return bool True if save successful
    */
   static bool save(const Save& data, const string& user);

   /**
    * @brief Check if save data exists for user
    * @param user Username to check
    * @return bool True if save data exists
    */
   static bool valid(const string& user);
   
private:
   /**
    * @brief Generate filename for user's save data
    * @param user Username
    * @return string Filename for save data
    */
   static string fname(const string& user);
};

#endif