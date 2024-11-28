/* 
 * Author: Ireoluwa
 * Created on October 29, 2024, 12:19 PM
 * Purpose: blackjack
 */

//System Libraries
#include <iostream>
using namespace std;

//User Libraries
#include "Blackjack.h"

//Execution Begins here
int main(int argc, char** argv) {
    //Setting the random number seed
    srand(time(0));
    
    //Declaring Variables
    const int SIZE = 52;          // Deck size
    Card* deck = new Card[SIZE];  // Create deck array
    int* hand = new int[10];      // Player's hand array
    int* dHand = new int[10];     // Dealer's hand array
    int nCards = SIZE;            // Number of cards in deck
    int pSum = 0, dSum = 0;       // Player and dealer totals
    int nHand = 0, nDHand = 0;    // Number of cards in each hand
    Save user;                    // User profile data
    string fname;                 // Save file name
    
    inzeGme(user, fname);  // Initialize game
    
    do {
        init(deck, nCards);    // Initialize deck
        shuf(deck, nCards);    // Shuffle deck
        int bet = gtBtAnt(user); // Get player's bet
        
        dlInCrd(deck, nCards, hand, nHand, dHand, nDHand); // Deal initial cards
        dspInDl(hand, nHand, dHand, deck, nCards);         // Show initial hands
        
        plyPrTn(deck, nCards, hand, nHand, pSum); // Player's turn
        
        // Dealer's turn if player didn't bust
        if (pSum <= 21) {
            plyDrTn(deck, nCards, dHand, nDHand, dSum); 
        }
        
        hndlGOt(user, bet, pSum, dSum); // Handle outcome
        save(user, fname);             // Save game state
        
        if (!chcGmCe(user)) break;  // Check if player can continue
        
        if (plyARnd()) {   // Reset if player wants to play again
            nHand = 0;
            nDHand = 0;
            nCards = SIZE;
        }
        
    } while (true);   // Game loop
    
    cNuGame(deck, hand, dHand);  // Clean up memory
    return 0;
}

// Function prototype to initialize a new game or load a previous game
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

// Function prototype to handle loading of save file if it exists
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

// Function prototype to create a new user profile
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

// Function prototype to display user stats
void dpUsrSt(Save& user) { 
    cout << "\nWelcome back " << user.name << "!\n";
    cout << "Stats from last game:\n";
    cout << "Wins: " << setw(5) << user.wins << endl;
    cout << "Games: " << setw(4) <<  user.games << endl;
    cout << "Cash: $" << user.cash << endl << endl;
    
    if (user.cash <= 0) {
        cout << "You have no money left in saved game!\n";
        cout << "Starting new game with fresh bankroll.\n\n";
        user.cash = 1000;  // Reset cash to 1000
    }
}

// Function prototype to get the player's betting amount
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

// Function prototype to deal initial cards to the player and dealer
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

// Function prototype to display the initial cards of player and dealer
void dspInDl(const int* hand, int nHand, const int* dHand, 
                       const Card* deck, int nCards) {
    cout << "\nDealer's up card:\n";
    pCard(dHand[0], deck[nCards].suit);
    cout << "Dealer's visible total: " << dHand[0] << endl;
}

// Function prototype to play the player's turn
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

// Function prototype to play the dealer's turn
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

// Function prototype to handle the game outcome and update the player's stats
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

// Function prototype to check if the player can continue the game
bool chcGmCe(const Save& user) {
    if (user.cash <= 0) {
        cout << "\nYou're broke! Game over!\n";
        return false;
    }
    return true;
}

// Function prototype to prompt the player if they want to play another round
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
    if (cont == 'n') { cout << "Exiting the game. Goodbye!" << endl;
        exit(0); return true;}}

// Function prototype to clean up memory and end the game
void cNuGame(Card* deck, int* hand, int* dHand) {
    delete[] deck;
    delete[] hand;
    delete[] dHand;
}

// Function prototype to validate the player's username
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

// Function prototype to clear the input buffer
void clrBuf() {
    cin.clear();
    cin.ignore(1000, '\n');
}

// Function prototype to load a saved game
bool load(Save& user, string name) {
    string fname = name + ".dat";
    ifstream in(fname, ios::binary | ios::in);
    if (!in) return false; in.seekg(0, ios::end);long fileSize = in.tellg();
    in.seekg(0, ios::beg); in.read(reinterpret_cast<char*>(&user),sizeof(Save));
    in.close();
    return true;
}

// Function prototype to save the current game state
void save(Save user, string name) {
    string fname = name + ".dat";
    ofstream out(fname, ios::binary | ios::out);
    out.write(reinterpret_cast<char*>(&user), sizeof(Save));
    out.close();
}

// Function prototype to initialize the deck of cards
void init(Card* deck, int& size) {
    for (int i = 0; i < size; i++) {
        deck[i].val = i % 13 + 1;
        deck[i].suit = static_cast<Suit>(i / 13);
    }
}

// Function prototype to shuffle the deck of cards
void shuf(Card* deck, int size) {
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Function prototype to draw a card from the deck
int draw(Card* deck, int& size) {
    return deck[--size].val > 10 ? 10 : deck[size].val;
}

// Function prototype to return the full name of a suit (e.g., Hearts)
string fllSuit(int s) {
    switch (s) {
        case HEART: return "Hearts";
        case DIAM: return "Diamonds";
        case SPADE: return "Spades";
        default: return "Clubs";
    }
}

// Function prototype to return the full name of a card's value (e.g., Ace)
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
        default: return "King";
    }
}

// Function prototype to print a single card's value and suit
void pCard(int val, char suit) {
    cout << cardVal(val) << " of " << fllSuit(suit) << endl;
}

// Function prototype to calculate the sum of a hand
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

// Function prototype to prompt the player for hit or stand
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