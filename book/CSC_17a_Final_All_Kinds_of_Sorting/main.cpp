/* 
 * File:   main.cpp
 * Author: Ireoluwa dairo
 * Created on December 6, 2024, 3:58 PM
 */

#include <iostream>
#include <fstream>
#include "AllKindsOfSorting.h"
using namespace std;

int main() {
    cout<<"The start of Problem 2, the sorting problem"<<endl;
    Prob2Sort<char> rc;
    bool ascending=true;
    
    ifstream infile;
    infile.open("Problem2.txt",ios::in);
    char *ch2=new char[10*16];
    char *ch2p=ch2;
    while(infile.get(*ch2)){cout<<*ch2;ch2++;}
    infile.close();
    cout<<endl;
    
    cout<<"Sorting on which column"<<endl;
    int column;
    cin>>column;
    
    char *zc=rc.sortArray(ch2p,10,16,column,ascending);
    for(int i=0;i<10;i++){
        for(int j=0;j<16;j++){
            cout<<zc[i*16+j];
        }
        //if(i== 8) cout<<endl;
    }
    delete []zc;

    return 0;
}