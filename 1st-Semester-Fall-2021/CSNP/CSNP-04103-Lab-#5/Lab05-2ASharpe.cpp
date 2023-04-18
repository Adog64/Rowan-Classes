/***************************************************************
* Name: Aidan Sharpe
* Course: Computer Science & Programming
* Class: CS04103 Section: 6
* Assignment Date: 10.13.2021
* File Name: Lab05-2ASharpe.cpp
*****************************************************************
* ID: Lab 5 Problem 2
* Purpose: Calculate the profit made from stocks
*****************************************************************/

#include <iostream>

using namespace std;

float profit(float NS, float SP, float SC, float PP, float PC);

int main(int argc, char const *argv[])
{
    float NS, SP, SC, PP, PC;

    // get investment information
    cout << "Number of shares: ";
    cin >> NS;
    cout << "Sale price per share: ";
    cin >> SP;
    cout << "Sale commission paid: ";
    cin >> SC;
    cout << "Purchase price per share: ";
    cin >> PP;
    cout << "Purchase commission paid: ";
    cin >> PC;

    // display profit or loss
    cout << endl << "The profit on the investment was $" << profit(NS, SP, SC, PP, PC);
    return 0;
}


// calculate the profit of an investment
float profit(float NS, float SP, float SC, float PP, float PC)
{
    return ((NS * SP) - SC) - ((NS * PP) + PC);
}