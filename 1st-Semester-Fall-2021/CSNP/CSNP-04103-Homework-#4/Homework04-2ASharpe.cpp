/***************************************************************
* Name: Aidan Sharpe
* Course: Computer Science & Programming
* Class: CS04103 Section: 6
* Assignment Date: 10.11.2021
* File Name: Homework04-2ASharpe.cpp
*****************************************************************
* ID: Homework 4 Problem 2
* Purpose: Display distance covered at different time periods
*****************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int mph, time;

    // get user inputs
    cout << "Enter speed in MPH: ";
    cin >> mph;
    cout << "Enter time of trip in hours: ";
    cin >> time;

    // formatting things
    cout << "*********************************" << endl;
    cout << "* Hour\t* Miles Traveled\t*" << endl;
    cout << "*********************************" << endl;

    // distance traveled after each hour
    for (int i = 0; i < time; i++)
    {
        cout << "* " << i << "\t* " << i * mph << "\t\t\t*" << endl;
    }

    // more formatty things
    cout << "*********************************" << endl;

    return 0;
}
