/***************************************************************
* Name: Aidan Sharpe
* Course: Computer Science & Programming
* Class: CS04103 Section: 6
* Assignment Date: 11.10.2021
* File Name: Lab8-1ASharpe.cpp
*****************************************************************
* ID: Lab 8 Problem 1
* Purpose: Get and sort a list of speeds from the user
*****************************************************************/

#include <iostream>
#include <string>

using namespace std;

void sort(float[], int);
float mean(float[], int);

int main()
{
    int numSpeeds;

    cout << string(37, '*') << endl
         << "*  WELCOME TO THE DMV SPEED CENTER  *" << endl
         << string(37,'*') << endl;

    // get number of speed values
    do
    {
        cout << "Number of speeds to store: ";
        cin >> numSpeeds;
    } while (numSpeeds <= 0);
    float speeds[numSpeeds];


    // get all speed values
    for(int i=0; i < numSpeeds; i++)
    {
        do
        {
            cout << "Speed " << i + 1 << ": ";
            cin >> speeds[i];
        } while (speeds[i] < 0);
    }

    // sort the speeds and display the sorted array
    sort(speeds, numSpeeds);
    cout << "\nSorted speeds are:" << endl;
    for(int i=0; i<numSpeeds; i++)
        cout << speeds[i] << ' ';

    cout << "\n\nAverage of " << numSpeeds << " speeds is: " << mean(speeds, numSpeeds);
    return 0;
}

// use selection sort to sort an array of floats of length <size> from least to greatest
void sort(float array[], int size)
{
    int minIndex;
    float minValue;

    for(int start = 0; start < (size - 1); start++)
    {
        minIndex = start;
        minValue = array[start];
        for(int index = start + 1; index < size; index++)
        {
            if(array[index] < minValue)
            {
                minValue = array[index];
                minIndex = index;
            }
        }

        // swap
        float temp = array[minIndex];
        array[minIndex] = array[start];
        array[start] = temp;
    }
}

// find and return the mean of an array of floats of length size
float mean(float array[], int length)
{
    float sum = 0;
    for(int i=0; i<length; i++)
        sum += array[i];

    return sum / length;
}