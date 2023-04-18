/***************************************************************
* Name: Aidan Sharpe
* Course: Computer Science & Programming
* Class: CS04103 Section: 6
* Assignment Date: <date>
* File Name: <filename>.cpp
*****************************************************************
* ID: Homework 1 Problem 2
* Purpose: Calculate the tax and total cost of a purchase given sales tax and the subtotal
*****************************************************************/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    const float STATE_SALES_TAX = .065, COUNTY_SALES_TAX = 0.02;
    
    float subtotal, tax, total;

    // get price of purchase
    cout << "Price of purchase: ";
    cin >> subtotal;

    tax = subtotal * (STATE_SALES_TAX + COUNTY_SALES_TAX);  // calculate tax
    total = subtotal + tax;                                 // calculate total price

    cout << fixed << setprecision(3) << endl;               // format the costs to 3 decimal places to account for sales tax precision errors

    // print data
    cout << "Subtotal: $" << subtotal << endl;
    cout << "Tax:      $" << tax << endl;
    cout << "Total:    $" << total;

    return 0;
}
