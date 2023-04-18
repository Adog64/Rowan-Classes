/***************************************************************
* Name: Aidan Sharpe
* Course: Computer Science & Programming
* Class: CS04103 Section: 6
* Assignment Date: 10.13.2021
* File Name: Lab05-1ASharpe.cpp
*****************************************************************
* ID: Lab 5 Problem 1
* Purpose: Calculate the average miles per gallon of 3 planes over a 1000 mile flight
*****************************************************************/

#include <iostream>
#include <string>
using namespace std;

float calcMPG(float miles, float gallons);

int main()
{
    string make, model, mostEfficientPlane;
    float gallonsUsed, milesPerGallon, mostEfficientMPG = -1;
    const float FLIGHT_DISTANCE = 1000;
    const int PLANES = 3;

    for(int i = 0; i < PLANES; i++)
    {
        cout << endl << "Enter the make and model of plane #" << i+1 << ": ";
        cin >> make;
        cin >> model;
        do
        {
            cout << "Enter the number of gallons used during the 1000mi flight: ";
            cin >> gallonsUsed;
        } while (gallonsUsed <= 0);     // make sure that the user enters a valid number of gallons consumed
    
        // calculate the miles per gallon
        milesPerGallon = calcMPG(FLIGHT_DISTANCE, gallonsUsed);

        // determine if the current plane is the most efficient one so far
        if (mostEfficientMPG == -1 || milesPerGallon > mostEfficientMPG)
        {
            mostEfficientMPG = milesPerGallon;
            mostEfficientPlane = make + ' ' + model;
        }

        // display the MPG for the current plane
        cout << "The average MPG of the " << make << ' ' << model << " is " << milesPerGallon << '.' << endl;
    }

    // display the most fuel efficient plane
    cout << endl << "The most efficient plane was the " << mostEfficientPlane << " with an MPG of " << mostEfficientMPG << '.'; 

    return 0;
}

// function to calculate miles per gallon
float calcMPG(float miles, float gallons)
{
    return miles/gallons;
}