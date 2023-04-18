/***************************************************************
* Name: Aidan Sharpe
* Course: Computer Science & Programming
* Class: CS04103 Section: 6
* Assignment Date: 11.08.2021
* File Name: Homework6-1ASharpe.cpp
*****************************************************************
* ID: Homework 6 Problem 1
* Purpose: Calculate the total cost of a hospital visit
*****************************************************************/
#include <iostream>

using namespace std;

bool isInvalidInput(int);
int totalCharge(int, int, int, int);
int totalCharge(int, int);

int main()
{
    char inpatient;
    bool isInpatient;
    int days, dailyRate, serviceFees, medFees;

    // check if patient stayed multiple days
    cout << "Inpatient? (y/n): ";
    cin >> inpatient;
    isInpatient = inpatient == 'y';

    // get and validate cost data
    if (isInpatient)
    {
        do
        {
            cout << "Days spent: ";
            cin >> days;
        } while (isInvalidInput(days));
        do
        {
            cout << "Daily rate: ";
            cin >> dailyRate;
        } while (isInvalidInput(dailyRate));     
    }
    do
    {
        cout << "Total Service Fees: ";
        cin >> serviceFees;
    } while (isInvalidInput(serviceFees));  
    do
    {
        cout << "Total Medication Fees: ";
        cin >> medFees;
    } while(isInvalidInput(medFees));

    // output total cost
    cout << "\nYour total cost is $";
    if (isInpatient)
        cout << totalCharge(days, dailyRate, serviceFees, medFees);
    else
        cout << totalCharge(serviceFees, medFees);       

    return 0;
}

int totalCharge(int days, int dailyRate, int serviceFees, int medFees)
{
    return days*dailyRate + serviceFees + medFees;
}

int totalCharge(int serviceFees, int medFees)
{
    return serviceFees + medFees;
}

// valid inputs are >= 0
bool isInvalidInput(int in)
{
    return in < 0;
}