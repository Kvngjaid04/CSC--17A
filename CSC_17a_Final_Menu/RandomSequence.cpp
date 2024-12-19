/* 
 * File:   RandomSequence.cpp
 * Author: Ireoluwa Dairo
 * 
 * Created on December 6, 2024, 3:43 PM
 */

#include "RandomSequence.h"
#include <cstdlib>
#include <ctime>

Prob1Random::Prob1Random(const char n, const char *s) {
    nset = n;
    numRand = 0;
    
    // Allocate and initialize set
    set = new char[n];
    for(int i = 0; i < n; i++) {
        set[i] = s[i];
    }
    
    // Allocate and initialize frequency array
    freq = new int[n];
    for(int i = 0; i < n; i++) {
        freq[i] = 0;
    }
    
    // Seed the random number generator
    srand(time(0));
}

Prob1Random::~Prob1Random() {
    delete[] set;
    delete[] freq;
}

char Prob1Random::randFromSet() {
    int index = rand() % nset;
    freq[index]++;
    numRand++;
    return set[index];
}

int *Prob1Random::getFreq() const {
    return freq;
}

char *Prob1Random::getSet() const {
    return set;
}

int Prob1Random::getNumRand() const {
    return numRand;
}