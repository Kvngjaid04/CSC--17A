/* 
 * File:   Player.cpp
 * Author: Ireoluwa Dairo
 * 
 * Created on November 27, 2024, 3:49 PM
 */
#include "Player.h"
#include <iostream>
using namespace std;

// Base class constructor/methods
Player::Player() {
    name = "Anon";
    funds = 1000;
    bet = 0;
    stats = PStats(100);  // Changed to PStats
}

Player::Player(const string& n, int f) {
    name = n;
    funds = f;
    bet = 0;
    stats = PStats(100);  // Changed to PStats
}

Player::~Player() {
    clear();
}

void Player::addCard(const Card& card) {
    hand.push_back(card);
}

int Player::getVal() const {
    int total = 0;
    int aces = 0;
    
    for (const auto& card : hand) {
        int val = card.getValue();
        if (val > 10) val = 10;
        if (val == 1) {
            aces++;
        } else {
            total += val;
        }
    }
    
    for (int i = 0; i < aces; ++i) {
        if (total + 11 <= 21) {
            total += 11;
        } else {
            total += 1;
        }
    }
    
    return total;
}

bool Player::isBust() const {
    return getVal() > 21;
}

void Player::clear() {
    hand.clear();
    bet = 0;
}

bool Player::setBet(int amt) {  // Changed from placeBet
    if (amt > funds || amt < 1) {
        return false;
    }
    bet = amt;
    funds -= amt;
    return true;
}

void Player::addWin(int amt) {
    funds += amt;
}

void Player::loseBet(int amt) {
    // No need to subtract - bet already removed when placed
}

void Player::setFund(int amt) {  // Changed from setFunds
    funds = amt;
}

void Player::addGame(bool won, int amt) {  // Changed from recordGameResult
    try {
        GameRes result(won, amt);
        stats.add(result);
    } catch (const runtime_error& e) {
        cerr << "Failed to record game result: " << e.what() << endl;
    }
}

int Player::getRate() const {  // Changed from getWinRate
    return stats.getRate();
}

string Player::getName() const {
    return name;
}

int Player::getFund() const {  // Changed from getFunds
    return funds;
}

int Player::getBet() const {
    return bet;
}

PStats& Player::getStat() {  // Added getter for stats
    return stats;
}

bool Player::operator==(const Player& other) const {
    return name == other.name && funds == other.funds;
}

bool Player::operator!=(const Player& other) const {
    return !(*this == other);
}

// Human class constructor/methods
Human::Human(const string& n) {
    name = n;
    funds = 1000;
    bet = 0;
    stats = PStats(100);  // Changed to PStats
}

bool Human::wantHit() {
    char resp;
    cout << "Hit? (y/n): ";
    cin >> resp;
    return (resp == 'y' || resp == 'Y');
}

void Human::dispHand() const {
    cout << "\n----------------------------------------\n";
    cout << "*** " << getName() << "'s Hand ***\n";
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

// Dealer class constructor/methods
Dealer::Dealer() {
    name = "Dealer";
    funds = 0;
    bet = 0;
    stats = PStats(100);  // Changed to PStats
}

bool Dealer::wantHit() {
    return getVal() < 17;
}

void Dealer::dispHand() const {
    cout << "\n----------------------------------------\n";
    cout << "*** Dealer's Hand ***\n";
    cout << "----------------------------------------\n";
    if (!hand.empty()) {
        cout << "| " << hand[0] << " |\n";
        cout << "| [Hidden Card] |\n";
    }
    cout << "----------------------------------------\n";
}

void Dealer::showAll() const {
    cout << "\n----------------------------------------\n";
    cout << "*** Dealer's Full Hand ***\n";
    cout << "----------------------------------------\n";
    for (size_t i = 0; i < hand.size(); ++i) {
        cout << "| " << hand[i] << " |\n";
    }
    cout << "----------------------------------------\n";
    cout << "Total: " << getVal() << "\n";
    cout << "----------------------------------------\n";
}