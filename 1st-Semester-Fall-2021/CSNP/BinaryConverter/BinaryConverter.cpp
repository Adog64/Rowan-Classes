/***************************************************************
* Name: Aidan Sharpe
* Course: Computer Science & Programming
* Class: CS04103 Section: 2
* Assignment Date: 9/8/2021
* File Name: BinaryConverter.cpp
*****************************************************************
* ID: Lab 0 Problem 1
* Purpose: Convert an user-entered integer to a binary string
*****************************************************************/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int x, n, k, a, c;


    // Data collection
    cout << "Enter an integer in the decimal number system: ";
    cin >> x;
    cout << "Binary value of the number is: ";

    //calculate the number of bits being used
    for ( a = 1; n != 0; a++ )
    {
        n = n / 2;
    }
    a = a - 2;

    // get each bit in the integer by bitshifting it one place to the left and reading the ones place for each bit in the number
    for ( c = a; c >= 0; c-- )
    {
        k = x >> c;
        if ( k & 1 )
            cout << "1";
        else
            cout << "0";
    }

    return 0;
}