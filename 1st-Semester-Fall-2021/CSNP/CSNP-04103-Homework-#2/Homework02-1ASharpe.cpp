/***************************************************************
* Name: Aidan Sharpe
* Course: Computer Science & Programming
* Class: CS04103 Section: 6
* Assignment Date: 09.30.2021
* File Name: Homework02-1ASharpe.cpp
*****************************************************************
* ID: Homework 2 Problem 1
* Purpose: Calculate total monthly and yearly costs of several expenses
*****************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int monthlyCost = 0, cost;   // initialize montlyCost to 0 to prevent propagation of arbitrary values

    cout << "Enter the following costs:" << endl << "Rent/Mortgage: ";
    cin >> cost;                 // set cost to cost of Rent/Mortgage payment
    monthlyCost += cost;         // add Rent/Mortgage payment to monthly cost

    cout << "Phones: ";
    cin >> cost;                 // set cost to cost of Phone payment
    monthlyCost += cost;         // add Phone payment to monthly cost

    cout << "Internet: ";
    cin >> cost;                 // set cost to cost of Internet payment
    monthlyCost += cost;         // add Internet payment to monthly cost

    cout << "Cable: ";
    cin >> cost;                // set cost to cost of Cable payment
    monthlyCost += cost;        // add Cable payment to monthly cost

    cout << "\nTotal Monthly cost: " << monthlyCost << endl
         << "Total Yearly cost: " << 12 * monthlyCost;

    return 0;
}
