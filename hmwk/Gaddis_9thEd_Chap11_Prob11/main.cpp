/*
 * File:   BudgetReport
 * Author: Ireoluwa
 * Created on October 7, 2024
 * Purpose: Track a student's monthly budget and report over/under expenses.
 */

//System Libraries
#include <iostream>
#include <iomanip>  // For setprecision
using namespace std;

// Structure to hold monthly budget categories
struct MnthBgt {
    float house;  // Housing
    float util;   // Utilities
    float hhold;  // Household Expenses
    float trans;  // Transportation
    float food;   // Food
    float medic;  // Medical
    float insur;  // Insurance
    float enter;  // Entertainment
    float cloth;  // Clothing
    float misc;   // Miscellaneous
};

// Function Prototypes
void getSpent(MnthBgt &); // Function to get user input for spent amounts
void report(MnthBgt, MnthBgt); // Function to display budget report

// Execution Begins Here
int main() {
    // Declare variables
    MnthBgt budget = {500, 150, 65, 50, 250, 30, 100, 150, 75, 50}; // Initial budget
    MnthBgt spent; // User input for actual spending
    
    // Get the amounts spent by the user
    getSpent(spent);
    
    // Display report
    report(budget, spent);
    
    // Exit stage right!
    return 0;
}

// Function to get the amount spent in each category
void getSpent(MnthBgt &spent) {
    cout << "Enter housing cost for the month:$" << endl;
    cin >> spent.house;
    
    cout << "Enter utilities cost for the month:$" << endl;
    cin >> spent.util;
    
    cout << "Enter household expenses cost for the month:$" << endl;
    cin >> spent.hhold;
    
    cout << "Enter transportation cost for the month:$" << endl;
    cin >> spent.trans;
    
    cout << "Enter food cost for the month:$" << endl;
    cin >> spent.food;
    
    cout << "Enter medical cost for the month:$" << endl;
    cin >> spent.medic;
    
    cout << "Enter insurance cost for the month:$" << endl;
    cin >> spent.insur;
    
    cout << "Enter entertainment cost for the month:$" << endl;
    cin >> spent.enter;
    
    cout << "Enter clothing cost for the month:$" << endl;
    cin >> spent.cloth;
    
    cout << "Enter miscellaneous cost for the month:$" << endl;
    cin >> spent.misc;
}

// Function to display the report
void report(MnthBgt budget, MnthBgt spent) {
    float totalBgt = budget.house + budget.util + budget.hhold + budget.trans + budget.food + 
                     budget.medic + budget.insur + budget.enter + budget.cloth + budget.misc;
    float totalSpnt = spent.house + spent.util + spent.hhold + spent.trans + spent.food + 
                      spent.medic + spent.insur + spent.enter + spent.cloth + spent.misc;
    
    // Display individual category differences with Over/Under/Even
    cout << fixed << setprecision(2); // Display two decimal places
    
    auto reportCategory = [](float spent, float budget, const string& name) {
        if (spent == budget) {
            cout << name << "Even" << endl;
        } else if (spent > budget) {
            cout << name << "Over" << endl;
        } else {
            cout << name << "Under" << endl;
        }
    };
    
    reportCategory(spent.house, budget.house, "Housing ");
    reportCategory(spent.util, budget.util, "Utilities ");
    reportCategory(spent.hhold, budget.hhold, "Household Expenses ");
    reportCategory(spent.trans, budget.trans, "Transportation ");
    reportCategory(spent.food, budget.food, "Food ");
    reportCategory(spent.medic, budget.medic, "Medical ");
    reportCategory(spent.insur, budget.insur, "Insurance ");
    reportCategory(spent.enter, budget.enter, "Entertainment ");
    reportCategory(spent.cloth, budget.cloth, "Clothing ");
    reportCategory(spent.misc, budget.misc, "Miscellaneous ");
    
  
    float difference = totalSpnt - totalBgt;
    if (difference == 0) {
        cout << "You were exactly on budget." << endl;
    } else if (difference > 0) {
        cout << "You were $" << difference << " over budget";
    } else {
        cout << "You were $" << -difference << " under budget";
    }
}
