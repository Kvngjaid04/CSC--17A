/**
 * @file Deck.h
 * @author Ireoluwa Dairo
 * @brief Template class for a card deck implementation
 * @date 2024-11-27
 */

#ifndef DECK_H
#define DECK_H

#include <vector>
#include <algorithm>
#include <random>
#include <stdexcept>
#include "Card.h"

using namespace std;

/** 
 * @class Deck
 * @brief Template class representing a deck of cards
 * @tparam T Card type that comprises the deck (defaults to Card class)
 * Implements a deck of cards with shuffle, draw and tracking functionality.
 * Supports multiple deck initialization and duplicate card detection.
 */
template <typename T = Card>
class Deck {
public:
    /** @brief Default constructor. Initializes a single deck */
    Deck();

    /** 
     * @brief Constructor for multiple decks
     * @param numDecks Number of decks to initialize
     */
    Deck(int numDecks);
    
    /** 
     * @brief Copy constructor
     * @param other Deck to copy from 
     */
    Deck(const Deck& other);

    /** 
     * @brief Assignment operator
     * @param other Deck to assign from
     * @return Deck& Reference to this deck 
     */
    Deck& operator=(const Deck& other);

    /** @brief Destructor */
    ~Deck();
    
    /** 
     * @brief Shuffle the deck. Randomizes card order and clears dealt cards tracking 
     */
    void shuffle();

    /** 
     * @brief Draw a card from the deck
     * @return T The drawn card
     * @throws runtime_error if deck is empty
     * @note Automatically reinitializes deck if duplicate card detected 
     */
    T drawCard();

    /** 
     * @brief Check if deck is empty
     * @return bool True if no cards remain 
     */
    bool isEmpty() const;

    /** 
     * @brief Get number of remaining cards
     * @return int Number of undealt cards 
     */
    int remainingCards() const;
    
    /** 
     * @brief Array subscript operator
     * @param index Index of card to access
     * @return T Card at specified index
     * @throws out_of_range if index is invalid 
     */
    T operator[](int index) const;
    
    /** @brief Friend class for debugging purposes */
    template <typename U>
    friend class DeckLogger;
    
protected:
    /** 
     * @brief Initialize deck(s) with cards
     * @param numDecks Number of decks to initialize 
     */
    void initializeDeck(int numDecks);
    
private:
    vector<T> cards;      /**< Vector of undealt cards */
    vector<T> dealtCards; /**< Vector tracking dealt cards */
    random_device rd;     /**< Random device for shuffling */
    mt19937 gen;         /**< Mersenne Twister random generator */
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
        cout << "Deck is empty!" << endl;
        return T(); 
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
        throw out_of_range("Index is out of range");
    }
    return cards[index];
}
#endif // DECK_H