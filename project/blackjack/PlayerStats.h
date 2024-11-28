/* 
 * File: PlayerStats.h
 * Author: Ireoluwa Dairo
 * Created on November 27, 2024
 */

#ifndef PLAYERSTATS_H
#define PLAYERSTATS_H

#include <string>
using namespace std;

class GameRes {
public:
    inline int getAmt() const { return amt; }
    inline bool isWin() const { return win; }
    
    GameRes(bool win = false, int amt = 0) : win(win), amt(amt) {}
    
private:
    bool win;
    int amt;
};

struct Stats {
    int games;
    int wins;
};

class PStats {
public:
    PStats(int max = 100);
    PStats(const PStats& other);
    ~PStats();
    
    PStats& operator=(const PStats& rhs);
    PStats operator+(const PStats& rhs) const;
    bool operator<(const PStats& rhs) const;
    
    void add(const GameRes& res);
    int getRate() const;
    void setAll(int games, int wins);
    Stats getAll() const;
    
private:
    GameRes* res;
    int size;
    int max;
    int rate;
    int games;
    int wins;
    static int num;
    
    friend void showAll(const PStats& st);
};

#endif