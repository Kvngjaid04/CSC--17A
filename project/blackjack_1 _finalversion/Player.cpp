/**
* @file Player.cpp
* @author Ireoluwa Dairo
* @brief Implementation of Player base class and derived Human/Dealer classes
* @date 2024-11-27
*/

#include "Player.h"
#include <iostream>
using namespace std;

/** Base Player Class Implementation */

/**
* @brief Default constructor
* Initializes anonymous player with default values
*/
Player::Player() {
   name = "Anon";
   funds = 1000;
   bet = 0;
   stats = PStats(100);
}

/**
* @brief Parameterized constructor
* @param n Player name
* @param f Initial funds
*/
Player::Player(const string& n, int f) {
   name = n;
   funds = f;
   bet = 0; 
   stats = PStats(100);
}

/**
* @brief Destructor
*/
Player::~Player() {
   clear();
}

/**
* @brief Add card to player's hand
* @param card Card to add
*/
void Player::addCard(const Card& card) {
   hand.push_back(card);
}

/**
* @brief Calculate hand value considering aces
* @return int Total hand value
*/
int Player::getVal() const {
   int total = 0;
   int aces = 0;
   
   // Calculate non-ace values first
   for (const auto& card : hand) {
       int val = card.getValue();
       if (val > 10) val = 10;
       if (val == 1) {
           aces++;
       } else {
           total += val;
       }
   }
   
   // Handle aces
   for (int i = 0; i < aces; ++i) {
       if (total + 11 <= 21) {
           total += 11;
       } else {
           total += 1;
       }
   }
   
   return total;
}

/**
* @brief Check if player has bust
* @return bool True if hand value exceeds 21
*/
bool Player::isBust() const {
   return getVal() > 21;
}

/**
* @brief Clear hand and bet
*/
void Player::clear() {
   hand.clear();
   bet = 0;
}

/**
* @brief Set bet amount
* @param amt Amount to bet
* @return bool True if bet is valid and set
*/
bool Player::setBet(int amt) {
   if (amt > funds || amt < 1) {
       return false;
   }
   bet = amt;
   funds -= amt;
   return true;
}

/**
* @brief Add winnings to funds
* @param amt Amount won
*/
void Player::addWin(int amt) {
   funds += amt;
}

/**
* @brief Handle lost bet
* @param amt Amount lost
*/
void Player::loseBet(int amt) {
   // Bet already deducted when placed
}

/**
* @brief Set player's funds
* @param amt New fund amount
*/
void Player::setFund(int amt) {
   funds = amt;
}

/**
* @brief Record game result
* @param won Whether game was won
* @param amt Amount won/lost
*/
void Player::addGame(bool won, int amt) {
   try {
       GameRes result(won, amt);
       stats.add(result);
   } catch (const runtime_error& e) {
       cerr << "Failed to record game result: " << e.what() << endl;
   }
}

/** Getter Methods */
int Player::getRate() const { return stats.getRate(); }
string Player::getName() const { return name; }
int Player::getFund() const { return funds; }
int Player::getBet() const { return bet; }
PStats& Player::getStat() { return stats; }

/**
* @brief Equality comparison operator
* @param other Player to compare with 
*/
bool Player::operator==(const Player& other) const {
   return name == other.name && funds == other.funds;
}

/**
* @brief Inequality comparison operator
* @param other Player to compare with
*/
bool Player::operator!=(const Player& other) const {
   return !(*this == other);
}

/** Human Class Implementation */

/**
* @brief Human constructor
* @param n Player name
*/
Human::Human(const string& n) {
   name = n;
   funds = 1000;
   bet = 0;
   stats = PStats(100);
}

/**
* @brief Get hit decision from human player
* @return bool True if player wants to hit
*/
bool Human::wantHit() {
   char resp;
   cout << "Hit? (y/n): ";
   cin >> resp;
   return (resp == 'y' || resp == 'Y');
}

/**
* @brief Display human player's hand
*/
void Human::dispHand() const {
    cout << "\n----------------------------------------\n";
    cout << getName() << "'s HAND \n";
    cout << "----------------------------------------\n";
    for (size_t i = 0; i < hand.size(); ++i) {
        cout << "| " << hand[i] << " |\n";
    }
    cout << "----------------------------------------\n";
    cout << "Total: " << getVal() << "\n";
    cout << "Funds: $" << getFund() << "\n";  // Changed to getFund
    if (bet > 0) {
        cout << "Current Bet: $" << bet << "\n";
    }
    cout << "----------------------------------------\n";
}

/** Dealer Class Implementation */

/**
* @brief Dealer constructor
* Initializes dealer with default values
*/
Dealer::Dealer() {
   name = "Dealer";
   funds = 0;
   bet = 0;
   stats = PStats(100);
}

/**
* @brief Get dealer's hit decision based on rules
* @return bool True if dealer must hit (< 17)
*/
bool Dealer::wantHit() {
   return getVal() < 17;
}

/**
* @brief Display dealer's initial hand (one card hidden)
*/
void Dealer::dispHand() const {
    cout << "\n----------------------------------------\n";
    cout << "DEALER'S HAND\n";
    cout << "----------------------------------------\n";
    if (!hand.empty()) {
        cout << " " << hand[0] << " \n";
        cout << " [Hidden Card] \n";
    }
    cout << "----------------------------------------\n";
}

/**
 * @brief Display dealer's complete hand
 * Shows all cards and total value
 */
void Dealer::showAll() const {
    cout << "\n----------------------------------------\n";
    cout << "DEALER'S FULL HAND\n";
    cout << "----------------------------------------\n";
    for (size_t i = 0; i < hand.size(); ++i) {
        cout << hand[i]<< " \n";
    }
    cout << "----------------------------------------\n";
    cout << "Total: " << getVal() << "\n";
    cout << "----------------------------------------\n";
}