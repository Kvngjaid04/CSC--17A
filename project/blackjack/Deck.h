/* 
 * File:   Deck.h
 * Author: Ireoluwa Dairo
 *
 * Created on November 27, 2024, 3:55 PM
 */

#ifndef DECK_H
#define DECK_H

#include <vector>
#include <algorithm>
#include <random>
#include <stdexcept>
#include "Card.h"

using namespace std;

// Template class for Deck
template <typename T = Card>
class Deck {
public:
    // Constructors
    Deck();
    Deck(int numDecks);
    
    // Rule of Three
    Deck(const Deck& other);             // Copy constructor
    Deck& operator=(const Deck& other);  // Assignment operator
    ~Deck();                             // Destructor
    
    // Deck operations
    void shuffle();
    T drawCard();
    bool isEmpty() const;
    int remainingCards() const;
    
    // Operator overloading
    T operator[](int index) const;
    
    // Friend class for debugging/logging
    template <typename U>
    friend class DeckLogger;
    
protected:
    void initializeDeck(int numDecks);
    
private:
    vector<T> cards;
    vector<T> dealtCards;  // Track dealt cards to prevent duplicates
    random_device rd;
    mt19937 gen;
};

// Template implementation
template <typename T>
Deck<T>::Deck() : gen(rd()) {
    initializeDeck(1);  // Default to one deck
}

template <typename T>
Deck<T>::Deck(int numDecks) : gen(rd()) {
    initializeDeck(numDecks);
}

template <typename T>
void Deck<T>::initializeDeck(int numDecks) {
    cards.clear();
    dealtCards.clear();  // Clear dealt cards when reinitializing
    for (int deck = 0; deck < numDecks; ++deck) {
        for (int suit = 0; suit < 4; ++suit) {
            for (int value = 1; value <= 13; ++value) {
                cards.push_back(T(value, static_cast<typename T::Suit>(suit)));
            }
        }
    }
}

template <typename T>
void Deck<T>::shuffle() {
    std::random_shuffle(cards.begin(), cards.end());  // Changed to random_shuffle
    dealtCards.clear();  // Clear dealt cards tracking when shuffling
}

template <typename T>
T Deck<T>::drawCard() {
    if (isEmpty()) {
        throw runtime_error("Deck is empty");
    }
    
    T card = cards.back();
    cards.pop_back();
    
    // Check for duplicates
    for (const auto& dealtCard : dealtCards) {
        if (card == dealtCard) {
            // Reinitialize deck if duplicate found
            initializeDeck(6);
            shuffle();
            return drawCard();
        }
    }
    
    dealtCards.push_back(card);
    return card;
}

template <typename T>
bool Deck<T>::isEmpty() const {
    return cards.empty();
}

template <typename T>
int Deck<T>::remainingCards() const {
    return cards.size();
}

// Copy constructor
template <typename T>
Deck<T>::Deck(const Deck& other) : gen(rd()) {
    cards = other.cards;
    dealtCards = other.dealtCards;
}

// Assignment operator
template <typename T>
Deck<T>& Deck<T>::operator=(const Deck& other) {
    if (this != &other) {
        cards = other.cards;
        dealtCards = other.dealtCards;
    }
    return *this;
}

// Destructor
template <typename T>
Deck<T>::~Deck() {
    cards.clear();
    dealtCards.clear();
}

// Subscript operator
template <typename T>
T Deck<T>::operator[](int index) const {
    if (index < 0 || index >= cards.size()) {
        throw out_of_range("Index out of range");
    }
    return cards[index];
}

#endif // DECK_H