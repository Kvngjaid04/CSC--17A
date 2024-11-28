/* 
 * File:   Card.cpp
 * Author: Ireoluwa Dairo
 * 
 * Created on November 27, 2024, 3:46 PM
 */

#include "Card.h"
#include <stdexcept>

// Initialize static member
int Card::cardCount = 0;

// Default Constructor
Card::Card() : value(1), suit(Suit::HEARTS) {
    cardCount++;
}

// Parameterized Constructor
Card::Card(int value, Suit suit) : suit(suit) {
    validateValue(value);
    this->value = value;
    cardCount++;
}

// Copy Constructor
Card::Card(const Card& other) : value(other.value), suit(other.suit) {
    cardCount++;
}

// Destructor
Card::~Card() {
    cardCount--;
}

// Validate card value
void Card::validateValue(int val) {
    if (val < 1 || val > 13) {
        throw std::invalid_argument("Card value must be between 1 and 13");
    }
}

// Get suit as string
std::string Card::getSuitString() const {
    switch(suit) {
        case Suit::HEARTS: return "Hearts";
        case Suit::DIAMONDS: return "Diamonds";
        case Suit::CLUBS: return "Clubs";
        case Suit::SPADES: return "Spades";
        default: return "Unknown";
    }
}

// Get value as string
std::string Card::getValueString() const {
    switch(value) {
        case 1: return "Ace";
        case 11: return "Jack";
        case 12: return "Queen";
        case 13: return "King";
        default: return std::to_string(value);
    }
}

// Equality operator
bool Card::operator==(const Card& other) const {
    return (value == other.value) && (suit == other.suit);
}

// Inequality operator
bool Card::operator!=(const Card& other) const {
    return !(*this == other);
}

// Assignment operator
Card& Card::operator=(const Card& other) {
    if (this != &other) {
        value = other.value;
        suit = other.suit;
    }
    return *this;
}

// Static method to get total card count
int Card::getNumCardsCreated() {
    return cardCount;
}

// Friend output operator
std::ostream& operator<<(std::ostream& os, const Card& card) {
    os << card.getValueString() << " of " << card.getSuitString();
    return os;
}