/***************************************************************
* Name: Aidan Sharpe
* Course: Computer Science & Programming
* Class: CS04103 Section: 6
* Assignment Date: 10.11.2021
* File Name: Homework04-1ASharpe.cpp
*****************************************************************
* ID: Homework 4 Problem 1
* Purpose: Display ASCII characters 32-127
*****************************************************************/

#include <iostream>

using namespace std;

int main()
{
    for ( int i = 32; i < 128; i++) // for characters 32-127
    {
        if (!(i % 16))              // newline after every 16 ASCII chars
            cout << endl;
        cout << char(i) << ' ';     // print the ASCII char followed by a space
    }
    return 0;
}