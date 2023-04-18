/***************************************************************
* Name: Aidan Sharpe
* Course: Computer Science & Programming
* Class: CS04103 Section: 6
* Assignment Date: 10.11.2021
* File Name: Homework3-1ASharpe.cpp
*****************************************************************
* ID: Homework 3 Problem 1
* Purpose: Compare the sizes of two rectangles
*****************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int areas[2];

    for ( int i = 0; i < 2; i++ )
    {
        int width, height;
        cout << "Enter width: ";
        cin >> width;
        cout << "Enter height: ";
        cin >> height;

        areas[i] = width * height;  // set area of rectangle
    }

    // figure out which rectangle has the larger area (if any) and print the result
    cout << ((areas[0] > areas[1]) ? "Rect 1 is bigger." : (areas[1] > areas[0]) ? "Rect 2 is bigger." : "They are the same size.");

    return 0;
} 