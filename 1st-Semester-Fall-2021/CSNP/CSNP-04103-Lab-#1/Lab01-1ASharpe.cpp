/***************************************************************
* Name: Aidan Sharpe
* Course: Computer Science & Programming
* Class: CS04103 Section: 2
* Assignment Date: 9/15/2021
* File Name: Lab01-1ASharpe.cpp
*****************************************************************
* ID: Lab 1 Problem 1
* Purpose: Print the value of paychecks with given pay periods and salary
*****************************************************************/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    const int ANNUAL_PAY = 39000, TWICE_MONTHLY = 24, BI_WEEKLY = 26;

    //Print paycheck value with both twice monthly payment and bi-weekly payment
    cout << endl << "Paycheck value at $" << ANNUAL_PAY << " per year with " << TWICE_MONTHLY << " paychecks per year: $" << ( ANNUAL_PAY / TWICE_MONTHLY ) << endl
         << "Paycheck value at $" << ANNUAL_PAY << " per year with " << BI_WEEKLY << " paychecks per year: $" << ( ANNUAL_PAY / BI_WEEKLY ) << endl;
    
    return 0;
}