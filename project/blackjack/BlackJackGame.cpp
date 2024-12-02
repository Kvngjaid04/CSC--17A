/* 
 * File: BlackJackGame.cpp
 * Author: Ireoluwa Dairo
 * Created on November 27, 2024
 */
#include "BlackjackGame.h"
#include <iostream>
#include <cstring>
using namespace std;

// Initialize static instance pointer
Game* Game::inst = nullptr;

Game& Game::get() {
    if (!inst) {
        inst = new Game();
    }
    return *inst;
}

Game::Game() : deck(6) {
    init();
}

Game::~Game() {
    saveGame();
    delete inst;
    inst = nullptr;
}

void Game::start() {
    init();
    mainLoop();
    saveGame();
}

void Game::init() {
    char choice;
    do {
        cout << "Load game? (y/n): ";
        cin >> choice;
        cin.ignore();
    } while (choice != 'y' && choice != 'n');
    
    if (choice == 'y') {
        loadGame();
    } else {
        newGame();
    }
}

void Game::loadGame() {
    do {
        cout << "Enter username: ";
        getline(cin, user);
    } while (!SaveGame::valid(user));
    
    if (SaveGame::load(save, user)) {
        plyr = make_unique<Human>(save.name);
        plyr->setFund(save.funds);
        plyr->getStat().setAll(save.gmsAll, save.winsAll);
        dlr = make_unique<Dealer>();
        
        cout << "\nWelcome back " << save.name << "!\n";
        cout << "Funds: $" << save.funds << "\n";
        cout << "Wins: " << save.wins << "\n";
        cout << "Games: " << save.games << "\n";
        
        char show;
        cout << "\nView win rate? (y/n): ";
        cin >> show;
        cin.ignore();
        
        if (show == 'y' || show == 'Y') {
            cout << "Win Rate: " << plyr->getRate() << "%\n\n";
        }

        if (save.funds == 0) {
            char pick;
            cout << "\nYou have $0!\n";
            cout << "Start with $1000? (y/n): ";
            cin >> pick;
            cin.ignore();
            
            if (pick == 'y' || pick == 'Y') {
                plyr->setFund(1000);
                save.funds = 1000;
                saveGame();
                cout << "\nRefreshed! Balance: $1000\n";
            } else {
                cout << "\nNo funds. Game Over!\n";
                exit(0);
            }
        }
    } else {
        cout << "No save found.\n";
        newGame();
    }
}

void Game::newGame() {
    do {
        cout << "Enter new username: ";
        getline(cin, user);
    } while (!SaveGame::valid(user));
    
    strncpy(save.name, user.c_str(), 29);
    save.name[29] = '\0';
    save.funds = 1000;
    save.wins = 0;
    save.games = 0;
    save.gmsAll = 0;
    save.winsAll = 0;
    
    plyr = make_unique<Human>(user);
    dlr = make_unique<Dealer>();
    
    cout << "\nWelcome " << user << "!\n";
    cout << "Starting funds: $" << save.funds << "\n\n";
}

void Game::deal() {
    plyr->addCard(deck.drawCard());
    dlr->addCard(deck.drawCard());
    plyr->addCard(deck.drawCard());
    dlr->addCard(deck.drawCard());
    
    plyr->dispHand();
    dlr->dispHand();
}

void Game::plyrTurn() {
    while (!plyr->isBust() && plyr->wantHit()) {
        plyr->addCard(deck.drawCard());
        plyr->dispHand();
        
        if (plyr->isBust()) {
            cout << "\nBust!\n";
        }
    }
}

void Game::dlrTurn() {
    dlr->showAll();
    
    while (dlr->wantHit()) {
        dlr->addCard(deck.drawCard());
        dlr->showAll();
        
        if (dlr->isBust()) {
            cout << "\nDealer busts!\n";
        }
    }
}

void Game::endRound() {
    dlr->showAll();
    
    int pVal = plyr->getVal();
    int dVal = dlr->getVal();
    int bet = plyr->getBet();
    
    if (plyr->isBust()) {
        cout << "\nBust!\n";
        plyr->addGame(false, bet);
        save.games++;
        return;
    }
    
    if (dlr->isBust()) {
        cout << "\nDealer busts!\n";
        plyr->addWin(bet * 2);
        plyr->addGame(true, bet);
        save.wins++;
        save.games++;
        return;
    }
    
    if (pVal > dVal) {
        cout << "\nYou win!\n";
        plyr->addWin(bet * 2);
        plyr->addGame(true, bet);
        save.wins++;
    } else if (pVal < dVal) {
        cout << "\nYou lose!\n";
        plyr->addGame(false, bet);
    } else {
        cout << "\nPush!\n";
        plyr->addWin(bet);
        plyr->addGame(false, 0);
    }
    save.games++;
    
    Stats st = plyr->getStat().getAll();
    save.gmsAll = st.games;
    save.winsAll = st.wins;
}

void Game::round() {
    plyr->clear();
    dlr->clear();
    
    int bet = getBet();
    if (!plyr->setBet(bet)) {
        cout << "Invalid bet!\n";
        return;
    }
    
    deck.shuffle();
    deal();
    plyrTurn();
    
    if (!plyr->isBust()) {
        dlrTurn();
    }
    
    endRound();
}

void Game::saveGame() {
    save.funds = plyr->getFund();
    SaveGame::save(save, user);
}

int Game::getBet() {
    int bet;
    do {
        cout << "\nFunds: $" << plyr->getFund() 
             << "\nBet amount: $";
        cin >> bet;
        
        if (bet > plyr->getFund()) {
            cout << "Can't bet more than you have!\n";
        }
        if (bet < 1) {
            cout << "Min bet is $1\n";
        }
    } while (bet > plyr->getFund() || bet < 1);
    
    return bet;
}

void Game::mainLoop() {
    while (true) {
        round();
        saveGame();
        
        if (save.funds == 0) {
            char choice;
            cout << "\nYou're broke!\n";
            cout << "Start fresh with $1000? (y/n): ";
            cin >> choice;
            
            if (choice == 'y' || choice == 'Y') {
                plyr->setFund(1000);
                save.funds = 1000;
                saveGame();
                cout << "\nRefreshed! Balance: $1000\n";
            } else {
                cout << "\nGame Over!\n";
                break;
            }
        }
        
        char cont;
        cout << "\nPlay again? (y/n): ";
        cin >> cont;
        if (cont != 'y' && cont != 'Y') break;
        
        if (deck.remainingCards() < 15) {
            deck = Deck<Card>(6);
    