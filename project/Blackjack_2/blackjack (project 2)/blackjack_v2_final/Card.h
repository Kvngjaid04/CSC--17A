/**
 * @file Card.h
 * @author Ireoluwa Dairo
 * @brief Playing card class implementation
 * @date 2024-11-27
 */

#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

/**
 * @class Card
 * @brief Represents a single playing card in a standard deck
 * This class implements a playing card with a value (1-13) and suit.
 * It includes functionality for comparing cards, converting to string
 * representations, and tracking the total number of cards created.
 */
class Card {
public:
    /**
     * @brief Enumeration of card suits
     * 
     * Uses enum class for type safety and scoping
     */
    enum class Suit { HEARTS, DIAMONDS, CLUBS, SPADES };
    
    /**
     * @brief Default constructor
     */
    Card();

    /**
     * @brief Constructor with value and suit
     * @param value Card's numeric value (1-13)
     * @param suit Card's suit
     * @throws std::invalid_argument if value is outside valid range
     */
    Card(int value, Suit suit);

    /**
     * @brief Copy constructor
     * @param other Card to copy from
     */
    Card(const Card& other);
    
    /**
     * @brief Destructor
     */
    ~Card();
    
    /**
     * @brief Get card's numeric value
     * @return int Value between 1-13
     */
    int getValue() const;

    /**
     * @brief Get card's suit
     * @return Suit Enumerated suit value
     */
    Suit getSuit() const;

    /**
     * @brief Get string representation of card's suit
     * @return std::string Suit name as string
     */
    std::string getSuitString() const;

    /**
     * @brief Get string representation of card's value
     * @return std::string Card value as string (e.g., "Ace", "King", etc.)
     */
    std::string getValueString() const;
    
    /**
     * @brief Equality comparison operator
     * @param other Card to compare with
     * @return bool True if cards have same value and suit
     */
    bool operator==(const Card& other) const;

    /**
     * @brief Inequality comparison operator
     * @param other Card to compare with
     * @return bool True if cards differ in value or suit
     */
    bool operator!=(const Card& other) const;

    /**
     * @brief Assignment operator
     * @param other Card to assign from
     * @return Card& Reference to this card
     */
    Card& operator=(const Card& other);
    
    /**
     * @brief Get total number of Card objects created
     * @return int Number of cards created
     */
    static int getNumCardsCreated();
    
    /**
     * @brief Stream output operator
     * @param os Output stream
     * @param card Card to output
     * @return std::ostream& Reference to output stream
     */
    friend std::ostream& operator<<(std::ostream& os, const Card& card);
    
private:
    int value;    /**< Card's numeric value (1-13) */
    Suit suit;    /**< Card's suit */
    static int cardCount;  /**< Counter for total card instances */
    
    /**
     * @brief Validate card value is within legal range
     * @param val Value to validate
     * @throws std::invalid_argument if value is outside valid range
     */
    void validateValue(int val);
};

// Inline method implementations
inline int Card::getValue() const { return value; }
inline Card::Suit Card::getSuit() const { return suit; }

#endif // CARD_H