/* 
 * File:   Blackjack.h
 * Author: Ireoluwa Dairo
 *
 * Created on November 27, 2024, 3:14 PM
 */

// blackjack.h
#ifndef BLACKJACK_H
#define BLACKJACK_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>
using namespace std;

// Struct Definitions
struct Card {
    char suit;
    int val;
};

struct Save {
    char name[30];
    int wins;
    int games;
    int cash;
};

// Enumeration
enum Suit {HEART, DIAM, SPADE, CLUB};

// Function Prototypes
void init(Card*, int&);    // Initialize deck
void shuf(Card*, int);     // Shuffle deck
int draw(Card*, int&);     // Draw card
void pCard(int, char);     // Print card
bool load(Save&, string);  // Load game
void save(Save, string);   // Save game
int* sum(int*, int);       // Sum hand
bool hit();               // Ask hit/stand
bool vName(string);       // Validate name
void clrBuf();           // Clear buffer
string fllSuit(int);       // Get full name of suit
string cardVal(int);       // Get card value as string
void inzeGme(Save&, string&);    // Initialize new or load existing game
bool hdSVFLd(Save&, string&);    // Load user save file
void crtNwUr(Save&, string&);    // Create new user profile
void dpUsrSt(Save&);       // Display user stats
int  gtBtAnt(const Save&);       // Get bet amount from player
void dlInCrd(Card*, int&, int*, int&, int*, int&); // Deal initial cards
void dspInDl(const int*, int, const int*, const Card*, int);//Show initial cards
void plyPrTn(Card*, int&, int*, int&, int&);       // Player's turn
void plyDrTn(Card*, int&, int*, int&, int&);       // Dealer's turn
void hndlGOt(Save&, int, int, int);               // Handle game outcome
bool chcGmCe(const Save&);                       // Check if player can continue
bool plyARnd();                             // Ask if player wants to play again
void cNuGame(Card*, int*, int*);                   // Clean up for a new game

#endif /* BLACKJACK_H */
