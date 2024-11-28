/* 
 * Author: Ireoluwa
 * Created on October 29, 2024, 12:19 PM
 * Purpose: blackjack
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
#include <cctype>
#include <cstring>
using namespace std;

//User Libraries
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

//Global Constants
enum Suit {HEART, DIAM, SPADE, CLUB};

//Function Prototypes
void init(Card*, int&);    //Initialize deck
void shuf(Card*, int);     //Shuffle deck
int draw(Card*, int&);     //Draw card
void prnt(Card*, int);     //Print cards
char getSuit(int);         //Get card suit
void pCard(int, char);     //Print card
bool load(Save&, string);  //Load game
void save(Save, string);   //Save game
int* sum(int*, int);       //Sum hand
bool hit();               //Ask hit/stand
bool vName(string);       //Validate name
void clrBuf();           //Clear buffer
string fllSuit(int);       // Get full name of suit
string cardVal(int);       // Get card value as string
void inzeGme(Save&, string&);    // Initialize new or load existing game
bool hdSVFLd(Save&, string&);    // Load user save file
void crtNwUr(Save&, string&);    // Create new user profile
void dpUsrSt(const Save&);       // Display user stats
int  gtBtAnt(const Save&);       // Get bet amount from player
void dlInCrd(Card*, int&, int*, int&, int*, int&); // Deal initial cards
void dspInDl(const int*, int, const int*, const Card*, int);//Show initial cards
void plyPrTn(Card*, int&, int*, int&, int&);       // Player's turn
void plyDrTn(Card*, int&, int*, int&, int&);       // Dealer's turn
void hndlGOt(Save&, int, int, int);               // Handle game outcome
bool chcGmCe(const Save&);                       // Check if player can continue
bool plyARnd();                             // Ask if player wants to play again
void cNuGame(Card*, int*, int*);                   // Clean up for a new game

//Execution Begins here
int main(int argc, char** argv) {
    srand(time(0));
    
    const int SIZE = 52;
    Card* deck = new Card[SIZE];
    int* hand = new int[10];
    int* dHand = new int[10];
    int nCards = SIZE;
    int pSum = 0, dSum = 0;
    int nHand = 0, nDHand = 0;
    Save user;
    string fname;
    
    inzeGme(user, fname);
    
    do {
        init(deck, nCards);
        shuf(deck, nCards);
        
        int bet = gtBtAnt(user);
        
        dlInCrd(deck, nCards, hand, nHand, dHand, nDHand);
        dspInDl(hand, nHand, dHand, deck, nCards);
        
        plyPrTn(deck, nCards, hand, nHand, pSum);
        
        if (pSum <= 21) {
            plyDrTn(deck, nCards, dHand, nDHand, dSum);
        }
        
        hndlGOt(user, bet, pSum, dSum);
        save(user, fname);
        
        if (!chcGmCe(user)) break;
        
        if (plyARnd()) {
            nHand = 0;
            nDHand = 0;
            nCards = SIZE;
        }
        
    } while (true);
    
    cNuGame(deck, hand, dHand);
    return 0;
}

void inzeGme(Save& user, string& fname) {
    char resp;
    cout << "Want to load a save file? (y/n): ";
    cin >> resp;
    clrBuf();
    
    if (resp == 'y') {
        if (hdSVFLd(user, fname)) {
            dpUsrSt(user);
        } else {
            crtNwUr(user, fname);
        }
    } else {
        crtNwUr(user, fname);
    }
}

bool hdSVFLd(Save& user, string& fname) {
    do {
        cout << "Enter username to load: ";
        getline(cin, fname);
    } while (!vName(fname));
    
    if (load(user, fname)) {
        return true;
    }
    cout << "Save file not found.\n";
    return false;
}

void crtNwUr(Save& user, string& fname) {
    do {
        cout << "Enter new username (3-30 chars, alphanumeric): ";
        getline(cin, fname);
    } while (!vName(fname));
    
    strncpy(user.name, fname.c_str(), 29);
    user.name[29] = '\0';
    user.wins = 0;
    user.games = 0;
    user.cash = 1000;
    cout << "\nWelcome " << user.name << "!\n";
    cout << "Starting cash: $" << user.cash << "\n\n";
}

void dpUsrSt(const Save& user) {
    cout << "\nWelcome back " << user.name << "!\n";
    cout << "Stats from last game:\n";
    cout << "Wins: " << user.wins << endl;
    cout << "Games: " << user.games << endl;
    cout << "Cash: $" << user.cash << endl << endl;
    
    if (user.cash <= 0) {
        cout << "You have no money left in saved game!\n";
        cout << "Starting new game with fresh bankroll.\n\n";
    }
}

int gtBtAnt(const Save& user) {
    int bet;
    do {
        cout << "Cash: $" << user.cash << endl;
        cout << "Bet amount: $";
        if (!(cin >> bet)) {
            cout << "Invalid bet. Enter a number.\n";
            clrBuf();
            bet = 0;
            continue;
        }
        if (bet > user.cash) cout << "Can't bet more than you have!\n";
        if (bet < 1) cout << "Minimum bet is $1\n";
    } while (bet > user.cash || bet < 1);
    clrBuf();
    return bet;
}

void dlInCrd(Card* deck, int& nCards, int* hand, int& nHand, 
                     int* dHand, int& nDHand) {
    cout << "\nYour cards:\n";
    hand[nHand] = draw(deck, nCards);
    pCard(hand[nHand], deck[nCards].suit);
    nHand++;
    
    hand[nHand] = draw(deck, nCards);
    pCard(hand[nHand], deck[nCards].suit);
    nHand++;
}

void dspInDl(const int* hand, int nHand, const int* dHand, 
                       const Card* deck, int nCards) {
    cout << "\nDealer's up card:\n";
    pCard(dHand[0], deck[nCards].suit);
    cout << "Dealer's visible total: " << dHand[0] << endl;
}

void plyPrTn(Card* deck, int& nCards, int* hand, int& nHand, int& pSum) {
    pSum = *sum(hand, nHand);
    cout << "\nYour total: " << pSum << endl;
    
    while (pSum < 21 && hit()) {
        hand[nHand] = draw(deck, nCards);
        cout << "\nYou drew:\n";
        pCard(hand[nHand], deck[nCards].suit);
        nHand++;
        pSum = *sum(hand, nHand);
        cout << "\nYour total: " << pSum << endl;
    }
}

void plyDrTn(Card* deck, int& nCards, int* dHand, int& nDHand, int& dSum) {
    dSum = *sum(dHand, nDHand);
    cout << "\nDealer shows hidden card:\n";
    for (int i = 0; i < nDHand; i++) {
        pCard(dHand[i], deck[nCards + i].suit);
    }
    cout << "Dealer total: " << dSum << endl;
    
    while (dSum < 17) {
        dHand[nDHand] = draw(deck, nCards);
        cout << "\nDealer drew:\n";
        pCard(dHand[nDHand], deck[nCards].suit);
        nDHand++;
        dSum = *sum(dHand, nDHand);
        cout << "Dealer total: " << dSum << endl;
    }
    cout << "\nFinal dealer total: " << dSum << endl;
}

void hndlGOt(Save& user, int bet, int pSum, int dSum) {
    cout << "\nFinal totals:\n";
    cout << "Your total: " << pSum << endl;
    if (pSum <= 21) cout << "Dealer total: " << dSum << endl;
    
    user.games++;
    if (pSum > 21) {
        cout << "\nBust! You lose $" << bet << endl;
        user.cash -= bet;
    }
    else if (dSum > 21) {
        cout << "\nDealer bust! You win $" << bet << endl;
        user.cash += bet;
        user.wins++;
    }
    else if (pSum > dSum) {
        cout << "\nYou win $" << bet << endl;
        user.cash += bet;
        user.wins++;
    }
    else if (pSum < dSum) {
        cout << "\nYou lose $" << bet << endl;
        user.cash -= bet;
    }
    else cout << "\nPush!\n";
    
    cout << "Current cash: $" << user.cash << endl;
}

bool chcGmCe(const Save& user) {
    if (user.cash <= 0) {
        cout << "\nYou're broke! Game over!\n";
        return false;
    }
    return true;
}

bool plyARnd() {
    char cont;
    do {
        cout << "\nPlay again? (y/n): ";
        cin >> cont;
        cont = tolower(cont);
        if (cont != 'y' && cont != 'n')
            cout << "Please enter y or n\n";
    } while (cont != 'y' && cont != 'n');
    clrBuf();
    return cont == 'y';
}

void cNuGame(Card* deck, int* hand, int* dHand) {
    delete[] deck;
    delete[] hand;
    delete[] dHand;
}

bool vName(string name) {
    if (name.length() < 3 || name.length() > 30) {
        cout << "Username must be 3-30 characters\n";
        return false;
    }
    
    for (char c : name) {
        if (!isalnum(c) && c != '_') {
            cout << "Username can only contain letters, numbers, and underscore\n";
            return false;
        }
    }
    return true;
}

void clrBuf() {
    cin.clear();
    cin.ignore(1000, '\n');
}

bool load(Save& user, string name) {
    string fname = name + ".dat";
    ifstream in(fname, ios::binary);
    if (!in) return false;
    in.read(reinterpret_cast<char*>(&user), sizeof(Save));
    in.close();
    return true;
}

void save(Save user, string name) {
    string fname = name + ".dat";
    ofstream out(fname, ios::binary);
    out.write(reinterpret_cast<char*>(&user), sizeof(Save));
    out.close();
}

void init(Card* deck, int& size) {
    for (int i = 0; i < size; i++) {
        deck[i].val = i % 13 + 1;
        deck[i].suit = static_cast<Suit>(i / 13);
    }
}

void shuf(Card* deck, int size) {
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

int draw(Card* deck, int& size) {
    return deck[--size].val > 10 ? 10 : deck[size].val;
}

char getSuit(int s) {
    switch (s) {
        case HEART: return 'H';
        case DIAM: return 'D';
        case SPADE: return 'S';
        case CLUB: return 'C';
        default: return 'X';
    }
}

string fllSuit(int s) {
    switch (s) {
        case HEART: return "Hearts";
        case DIAM: return "Diamonds";
        case SPADE: return "Spades";
        case CLUB: return "Clubs";
        default: return "Unknown";
    }
}

string cardVal(int val) {
    switch (val) {
        case 1: return "Ace";
        case 2: return "Two";
        case 3: return "Three";
        case 4: return "Four";
        case 5: return "Five";
        case 6: return "Six";
        case 7: return "Seven";
        case 8: return "Eight";
        case 9: return "Nine";
        case 10: return "Ten";
        case 11: return "Jack";
        case 12: return "Queen";
        case 13: return "King";
        default: return "Unknown";
    }
}

void pCard(int val, char suit) {
    cout << cardVal(val) << " of " << fllSuit(suit) << endl;
}

int* sum(int* hand, int size) {
    static int total = 0;
    total = 0;
    int aces = 0;
    
    for (int i = 0; i < size; i++) {
        if (hand[i] == 1) {
            aces++;
            total += 11;
        } else {
            total += hand[i];
        }
    }
    
    while (total > 21 && aces > 0) {
        total -= 10;
        aces--;
    }
    
    return &total;
}

bool hit() {
    char ch;
    do {
        cout << "\nHit? (y/n): ";
        cin >> ch;
        ch = tolower(ch);
        if (ch != 'y' && ch != 'n')
            cout << "Please enter y or n\n";
    } while (ch != 'y' && ch != 'n');
    return ch == 'y';
}