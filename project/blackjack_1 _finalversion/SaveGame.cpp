/**
* @file SaveGame.cpp
* @author Ireoluwa Dairo
* @brief Implementation of game state persistence
* @date 2024-11-27
*/

#include "SaveGame.h"
#include <cctype>
using namespace std;

/**
* @brief Load saved game data for user
* @param data Save structure to load data into
* @param user Username to load data for
* @return bool True if load successful
*/
bool SaveGame::load(Save& data, const string& user) {
   ifstream file(fname(user), ios::binary);
   if (!file) return false;
   
   file.read(reinterpret_cast<char*>(&data), sizeof(Save));
   file.close();
   return true;
}

/**
* @brief Save current game state for user
* @param data Save structure containing data
* @param user Username to save data for
* @return bool True if save successful
*/
bool SaveGame::save(const Save& data, const string& user) {
   ofstream file(fname(user), ios::binary);
   if (!file) return false;
   
   file.write(reinterpret_cast<const char*>(&data), sizeof(Save));
   file.close();
   return true;
}

/**
* @brief Validate username format
* @param user Username to validate
* @return bool True if username is valid
* @details Username must be 3-30 characters, alphanumeric or underscore
*/
bool SaveGame::valid(const string& user) {
   if (user.length() < 3 || user.length() > 30) {
       return false;
   }
   
   for (char c : user) {
       if (!isalnum(c) && c != '_') {
           return false;
       }
   }
   return true;
}

/**
* @brief Generate filename for user's save data
* @param user Username
* @return string Filename with .dat extension
*/
string SaveGame::fname(const string& user) {
   return user + ".dat";
}