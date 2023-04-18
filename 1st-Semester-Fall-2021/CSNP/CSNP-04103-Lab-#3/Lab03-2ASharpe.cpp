/***************************************************************
* Name: Aidan Sharpe
* Course: Computer Science & Programming
* Class: CS04103 Section: 6
* Assignment Date: 09.29.2021
* File Name: Lab03-2ASharpe.cpp
*****************************************************************
* ID: Lab 3 Problem 2
* Purpose: Computes and prints the price of a speeding ticket given a car speed in a 55 Mph zone
*****************************************************************/

#include <iostream>

using namespace std;

int main()
{
    const int SPEED_LIMIT = 55;
    int speed;

    // ask the cop for the speed of the vehicle
    cout << "Enter the speed between 0 and 150 Mph: ";
    cin >> speed;
    cout << "\n\n";

    // determine the cost of the ticket if the driver was speeding
    if ( speed > SPEED_LIMIT && speed < 150 )

        // determine which ticket cost range applies
        if ( speed - (SPEED_LIMIT + 20) >= 0)
            cout << "The price of the ticket is $" << 50 + 5 * (speed - SPEED_LIMIT);
        else
            cout << "The price of the ticket is $" << 50 + 2 * (speed - SPEED_LIMIT);

    // determine if the vehicle was actually speeding
    else if ( speed <= SPEED_LIMIT )
        cout << "The driver was not speeding.";

    // if the driver is reckless
    else
        cout << "The driver should be arrested.";
    return 0;
}
