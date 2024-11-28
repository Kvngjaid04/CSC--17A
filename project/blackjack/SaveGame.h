/* 
 * File:   SaveGame.h
 * Author: Ireoluwa Dairo
 *
 * Created on November 27, 2024, 4:24 PM
 */

#ifndef SAVEGAME_H
#define SAVEGAME_H
#include <string>
#include <fstream>
using namespace std;

struct Save {
    char name[30];  // Name
    int funds;      // Money
    int wins;       // Wins
    int games;      // Games
    int gmsAll;     // All games
    int winsAll;    // All wins
};

class SaveGame {  // Changed from SaveGm back to SaveGame
public:
    static bool load(Save& data, const string& user);
    static bool save(const Save& data, const string& user);
    static bool valid(const string& user);
    
private:
    static string fname(const string& user);
};
#endif