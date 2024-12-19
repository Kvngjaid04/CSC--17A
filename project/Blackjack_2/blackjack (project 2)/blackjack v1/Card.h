/* 
 * File:   Card.h
 * Author: Ireoluwa Dairo
 *
 * Created on November 27, 2024, 3:46 PM
 */

#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

class Card {
public:
    // Enum for Suit to improve type safety
    enum class Suit { HEARTS, DIAMONDS, CLUBS, SPADES };
    
    // Constructors
    Card();
    Card(int value, Suit suit);
    Card(const Card& other); // Copy constructor
    
    // Destructor
    ~Card();
    
    // Getter methods
    int getValue() const;
    Suit getSuit() const;
    std::string getSuitString() const;
    std::string getValueString() const;
    
    // Operator overloading
    bool operator==(const Card& other) const;
    bool operator!=(const Card& other) const;
    Card& operator=(const Card& other); // Assignment operator
    
    // Static methods
    static int getNumCardsCreated();
    
    // Friend function for output
    friend std::ostream& operator<<(std::ostream& os, const Card& card);
    
private:
    int value;          // Card's numeric value (1-13)
    Suit suit;          // Card's suit
    static int cardCount; // Static member to track total card instances
    
    // Private helper method
    void validateValue(int val);
};

// Inline method implementations
inline int Card::getValue() const { return value; }
inline Card::Suit Card::getSuit() const { return suit; }

#endif // CARD_H