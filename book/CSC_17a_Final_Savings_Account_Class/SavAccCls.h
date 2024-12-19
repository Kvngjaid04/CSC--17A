/* 
 * File:   SavAccCls.h
 * Author: Ireoluwa Dairo
 *
 * Created on December 8, 2024, 11:14 PM
 */

#ifndef SAVACCCLS_H
#define SAVACCCLS_H

class SavingsAccount {
public:
    SavingsAccount(float);          //Constructor
    void Transaction(float);        //Procedure
    float Total(float=0,int=0);     //Savings Procedure
    float TotalRecursive(float=0,int=0);//Savings Procedure
    void toString();                //Output Properties
private:
    float Withdraw(float);          //Utility Procedure
    float Deposit(float);           //Utility Procedure
    float Balance;                  //Property
    int FreqWithDraw;              //Property
    int FreqDeposit;               //Property
};

#endif