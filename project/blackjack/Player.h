/* 
 * File: Player.h
 * Author: Ireoluwa Dairo
 * Created on November 27, 2024
 */

#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include "Card.h"
#include "PlayerStats.h"

using namespace std;

class Player {
public:
    Player();
    Player(const string& name, int funds = 1000);
    virtual ~Player();
    
    virtual bool wantHit() = 0;
    virtual void dispHand() const = 0;
    
    virtual void addCard(const Card& card);
    virtual int getVal() const;
    virtual bool isBust() const;
    virtual void clear();
    
    bool setBet(int amt);
    void addWin(int amt);
    void loseBet(int amt);
    void setFund(int amt);
    
    void addGame(bool won, int amt);
    int getRate() const;
    PStats& getStat();
    
    string getName() const;
    int getFund() const;
    int getBet() const;
    
    bool operator==(const Player& other) const;
    bool operator!=(const Player& other) const;
    
protected:
    string name;
    vector<Card> hand;
    int funds;
    int bet;
    PStats stats;
};

class Human : public Player {
public:
    Human(const string& name);
    bool wantHit() override;
    void dispHand() const override;
};

class Dealer : public Player {
public:
    Dealer();
    bool wantHit() override;
    void dispHand() const override;
    void showAll() const;
};

#endif