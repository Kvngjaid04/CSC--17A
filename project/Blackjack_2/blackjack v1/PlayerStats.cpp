/* 
 * File: PlayerStats.cpp
 * Author: Ireoluwa Dairo
 * Created on November 27, 2024
 */

#include "PlayerStats.h"
#include <stdexcept>

int PStats::num = 0;

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

PStats::~PStats() {
    delete[] res;
    num--;
}

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

void PStats::setAll(int gms, int wns) {
    games = gms;
    wins = wns;
    if(games > 0) {
        rate = (wins * 100) / games;
    } else {
        rate = 0;
    }
}

Stats PStats::getAll() const {
    return {games, wins};
}

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

int PStats::getRate() const {
    return rate;
}

bool PStats::operator<(const PStats& rhs) const {
    return rate < rhs.rate;
}

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