/* 
 * File:   main.cpp
 * Author: Ireoluwa Dairo
 * Created on December 8, 2024, 11:13 PM
 */

#include <iostream>
#include <cstdlib>
#include <ctime>   
#include "SavAccCls.h"
using namespace std;

int main() {
    srand(time(0));  // Seed the random number generator
    
    SavingsAccount mine(-300);
    
    for(int i=1;i<=10;i++) {
        mine.Transaction((float)(rand()%500)*(rand()%3-1));
    }
    
    mine.toString();
    
    cout<<"Balance after 7 years given 10% interest = "
        <<mine.Total((float)(0.10),7)<<endl;
    
    cout<<"Balance after 7 years given 10% interest = "
        <<mine.TotalRecursive((float)(0.10),7)
        <<" Recursive Calculation "<<endl;
        
    return 0;
}