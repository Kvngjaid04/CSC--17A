/**
* @file Card.cpp
* @author Ireoluwa Dairo
* @brief Implementation of Card class
* @date 2024-11-27
*/

#include "Card.h"

using namespace std;

/** Initialize static counter for card instances */
int Card::cardCount = 0;

/**
* @brief Default constructor
* Creates Ace of Hearts by default
*/
Card::Card() : value(1), suit(Suit::HEARTS) {
   cardCount++;
}

/**
* @brief Parameterized constructor
* @param value Card value (1-13)
* @param suit Card suit
*/
Card::Card(int value, Suit suit) : suit(suit) {
   validateValue(value);
   this->value = value;
   cardCount++;
}

/**
* @brief Copy constructor
* @param other Card to copy from
*/
Card::Card(const Card& other) : value(other.value), suit(other.suit) {
   cardCount++;
}

/**
* @brief Destructor
* Decrements card count
*/
Card::~Card() {
   cardCount--;
}

/**
* @brief Validate card value is within legal range
* @param val Value to validate
* @throws invalid_argument if value outside 1-13 range
*/
void Card::validateValue(int val) {
   if (val < 1 || val > 13) {
       cout << "Invalid card value, Must be between 1 and 13.\n";
       return;
   }
}

/**
* @brief Get string representation of card suit
* @return string Name of suit
*/
string Card::getSuitString() const {
   switch(suit) {
       case Suit::HEARTS: return "Hearts";
       case Suit::DIAMONDS: return "Diamonds";
       case Suit::CLUBS: return "Clubs";
       case Suit::SPADES: return "Spades";
       default: return "Unknown";
   }
}

/**
* @brief Get string representation of card value
* @return string Card value or face card name
*/
string Card::getValueString() const {
   switch(value) {
       case 1: return "Ace";
       case 11: return "Jack";
       case 12: return "Queen";
       case 13: return "King";
       default: return to_string(value);
   }
}

/**
* @brief Equality comparison operator
* @param other Card to compare with
* @return bool True if cards match in value and suit
*/
bool Card::operator==(const Card& other) const {
   return (value == other.value) && (suit == other.suit);
}

/**
* @brief Inequality comparison operator
* @param other Card to compare with
* @return bool True if cards differ in value or suit
*/
bool Card::operator!=(const Card& other) const {
   return !(*this == other);
}

/**
* @brief Assignment operator
* @param other Card to assign from
* @return Card& Reference to this card
*/
Card& Card::operator=(const Card& other) {
   if (this != &other) {
       value = other.value;
       suit = other.suit;
   }
   return *this;
}

/**
* @brief Get total number of Card objects created
* @return int Number of cards currently in existence
*/
int Card::getNumCardsCreated() {
   return cardCount;
}

/**
* @brief Stream output operator
* @param os Output stream
* @param card Card to output
* @return ostream& Reference to output stream
*/
ostream& operator<<(ostream& os, const Card& card) {
   os << card.getValueString() << " of " << card.getSuitString();
   return os;
}
