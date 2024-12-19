/* 
 * File:   empclass.cpp
 * Author: Ireoluwa Dairo
 * 
 * Created on December 7, 2024, 11:33 PM
 */

#include "empclass.h"
#include <iostream>
#include <cstring>
using namespace std;

Employee::Employee(char name[], char title[], float rate) {
    // Copy name and title
    strncpy(MyName, name, 19);
    MyName[19] = '\0';
    strncpy(JobTitle, title, 19);
    JobTitle[19] = '\0';
    
    // Initialize hourly rate if valid, otherwise 0
    if(rate > 0 && rate < 200) {
        HourlyRate = rate;
    } else {
        HourlyRate = 0;
        cout << "Unacceptable Hourly Rate" << endl;
    }
    
    // Initialize other properties to 0
    HoursWorked = 0;
    GrossPay = 0;
    NetPay = 0;
}

double Employee::Tax(float grossPay) {
    double tax = 0;
    
    if(grossPay > 1000) {
        tax += (grossPay - 1000) * 0.3;
        tax += 500 * 0.2;
        tax += 500 * 0.1;
    } else if(grossPay > 500) {
        tax += (grossPay - 500) * 0.2;
        tax += 500 * 0.1;
    } else {
        tax += grossPay * 0.1;
    }
    
    return tax;
}

float Employee::getGrossPay(float rate, int hours) {
    float gross = 0;
    
    if(hours <= 40) {
        gross = hours * rate;
    } else if(hours <= 50) {
        gross = 40 * rate + (hours - 40) * rate * 1.5;
    } else {
        gross = 40 * rate + 10 * rate * 1.5 + (hours - 50) * rate * 2;
    }
    
    GrossPay = gross;
    return gross;
}

float Employee::getNetPay(float grossPay) {
    NetPay = grossPay - Tax(grossPay);
    return NetPay;
}

void Employee::toString() {
    cout << "Name = " << MyName << " ";
    cout << "Job Title = " << JobTitle << endl;
    cout << "Hourly Rate = " << HourlyRate << " ";
    cout << "Hours Worked = " << HoursWorked << " ";
    cout << "Gross Pay = " << GrossPay << " ";
    cout << "Net Pay = " << NetPay <<endl;
}

int Employee::setHoursWorked(int hours) {
    if(hours > 0 && hours < 84) {
        HoursWorked = hours;
    } else {
        cout << "Unacceptable Hours Worked" << endl;
        HoursWorked = 0;
    }
    return HoursWorked;
}

float Employee::setHourlyRate(float rate) {
    if(rate > 0 && rate < 200) {
        HourlyRate = rate;
    } else {
        cout << "Unacceptable Hourly Rate" << endl;
        HourlyRate = 0;
    }
    return HourlyRate;
}

float Employee::CalculatePay(float x, int y) {
    return getNetPay(getGrossPay(setHourlyRate(x), setHoursWorked(y)));
}