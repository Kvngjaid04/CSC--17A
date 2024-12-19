/* 
 * File:   RandomSequence.h
 * Author: Ireoluwa Dairo
 *
 * Created on December 6, 2024, 3:43 PM
 */

#ifndef RANDOMSEQUENCE_H
#define RANDOMSEQUENCE_H

class Prob1Random {
private:
    char *set;    //The set of numbers to draw random numbers from
    char nset;    //The number of variables in the sequence
    int *freq;    //Frequency of all the random numbers returned
    int numRand;  //The total number of times the random number
                  //function is called
public:
    Prob1Random(const char,const char *);  //Constructor
    ~Prob1Random(void);                    //Destructor
    char randFromSet(void);                //Returns a random number from the set
    int *getFreq(void) const;             //Returns the frequency histogram
    char *getSet(void) const;             //Returns the set used
    int getNumRand(void) const;           //Gets the number of times randFromSet
                                         //has been called
};

#endif/* RANDOMSEQUENCE_H */

