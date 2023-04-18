/***************************************************************
* Name: Aidan Sharpe
* Course: Computer Science & Programming
* Class: CS04103 Section: 6
* Assignment Date: 09.29.2021
* File Name: Lab03-1ASharpe.cpp
*****************************************************************
* ID: Lab 3 Problem 1
* Purpose: Determine and print whether or not a given year is a leap year
*****************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int year;

    // ask the user for a year
    cout << "Enter a year: ";
    cin >> year;
    // cout << "\n\n";

    // determine if the year is a leap year
    // if 
    //     cout << year << " is a leap year.";
    // else
    //     cout << year << " is not a leap year.";

    cout << " is" << (( year >= 1582 && (year % 100 != 0 || year % 400 == 0) && year % 4 == 0) ? " " : " not ") << "a leap year.";

    return 0;
}

