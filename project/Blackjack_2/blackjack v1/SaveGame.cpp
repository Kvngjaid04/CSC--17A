/* 
 * File:   SaveGame.cpp
 * Author: Ireoluwa Dairo
 * 
 * Created on November 27, 2024, 4:24 PM
 */

#include "SaveGame.h"
#include <cctype>
using namespace std;

bool SaveGame::load(Save& data, const string& user) {
    ifstream file(fname(user), ios::binary);
    if (!file) return false;
    
    file.read(reinterpret_cast<char*>(&data), sizeof(Save));
    file.close();
    return true;
}

bool SaveGame::save(const Save& data, const string& user) {
    ofstream file(fname(user), ios::binary);
    if (!file) return false;
    
    file.write(reinterpret_cast<const char*>(&data), sizeof(Save));
    file.close();
    return true;
}

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

string SaveGame::fname(const string& user) {
    return user + ".dat";
}