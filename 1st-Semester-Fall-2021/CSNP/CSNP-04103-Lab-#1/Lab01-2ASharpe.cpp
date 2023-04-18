/***************************************************************
* Name: Aidan Sharpe
* Course: Computer Science & Programming
* Class: CS04103 Section: 2
* Assignment Date: 9/15/2021
* File Name: Lab01-2ASharpe.cpp
*****************************************************************
* ID: Lab 1 Problem 2
* Purpose: Calculate how many energy drinks and citrus drinks are being consumed out of a set of customers
*****************************************************************/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    const int CUSTOMERS = 16500;
    const float ENERGY_PERCENT = 0.15, CITRUS_PERCENT = 0.52;

    //Calculate the number of customers that got energy drinks and the number that got citrus drinks
    cout << endl << "Out of " << CUSTOMERS << " customers: about " << int( ENERGY_PERCENT * CUSTOMERS ) << " had an energy drink, "
         << "and about " << int( CITRUS_PERCENT * CUSTOMERS ) << " had a citrus drink." << endl;

    return 0;
}