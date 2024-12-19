/* 
 * File:   AllKindsOfSorting.h
 * Author: Ireoluwa Dairo
 *
 * Created on December 6, 2024, 3:59 PM
 */

#ifndef ALLKINDSOFSORTING_H
#define ALLKINDSOFSORTING_H
#include <cstddef>

template<class T> 
class Prob2Sort {
private:
    int *index;    //Index that is utilized in the sort
public:
    Prob2Sort(){index=NULL;};  //Constructor
    ~Prob2Sort(){delete []index;}; //Destructor
    T * sortArray(const T*,int,bool);     //Sorts a single column array
    T * sortArray(const T*,int,int,int,bool);//Sorts a 2 dimensional array
                                            //represented as a 1 dim array
};

#endif /* ALLKINDSOFSORTING_H */

