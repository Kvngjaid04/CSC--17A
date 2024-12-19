/* 
 * File:   SavAccCls.cpp
 * Author: Ireoluwa Dairo
 * 
 * Created on December 8, 2024, 11:14 PM
 */

#include "SavAccCls.h"
#include <iostream>
using namespace std;

SavingsAccount::SavingsAccount(float initial) {
    Balance = (initial > 0) ? initial : 0;
    FreqWithDraw = 0;
    FreqDeposit = 0;
}

float SavingsAccount::Withdraw(float amount) {
    if (amount > Balance) {
        cout << "WithDraw not Allowed" << endl;
        return Balance;
    }
    FreqWithDraw++;
    return Balance - amount;
}

float SavingsAccount::Deposit(float amount) {
    FreqDeposit++;
    return Balance + amount;
}

void SavingsAccount::Transaction(float amount) {
    if (amount > 0) {
        Balance = Deposit(amount);
    } else {
        Balance = Withdraw(-amount);
    }
}

float SavingsAccount::Total(float savint, int time) {
    float futureValue = Balance;
    for(int i = 0; i < time; i++) {
        futureValue *= (1 + savint);
    }
    return futureValue;
}

float SavingsAccount::TotalRecursive(float savint, int time) {
    if (time == 0) {
        return Balance;
    }
    return TotalRecursive(savint, time - 1) * (1 + savint);
}

void SavingsAccount::toString() {
    cout << "Balance=" << Balance << endl;
    cout << "WithDraws=" << FreqWithDraw << endl;
    cout << "Deposit=" << FreqDeposit << endl;
}