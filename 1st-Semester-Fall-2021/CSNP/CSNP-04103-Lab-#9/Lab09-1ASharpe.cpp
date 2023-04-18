/***************************************************************
* Name: Aidan Sharpe
* Course: Computer Science & Programming
* Class: CS04103 Section: 6
* Assignment Date: 11.17.2021
* File Name: Lab09-1ASharpe.cpp
*****************************************************************
* ID: Lab 9 Problem 1
* Purpose: Collect scores in a dynamically allocated array
*****************************************************************/

#include <iostream>

using namespace std;

void sort(int*, int);

int main()
{
    int length, total = 0;

    cout << "Please enter the number of test scores: ";
    cin >> length;

    int *scores = new int[length];

    for(int i = 0; i < length; i++)
    {
        cout << "Please enter the score No. " << i << ": ";
        cin >> *(scores + i);
    }

    sort(scores, length);
    cout << "The scores in ascending order are:";
    for(int i = 0; i < length; i++)
    {
        cout << ' ' << *(scores + i);
        total += *(scores + i);
    }

    cout << "\nAverage score: " << total / length;
    
    delete scores;
    return 0;
}


void sort(int* ptr, int size)
{
    int minIndex, minValue;

    for(int start = 0; start < (size - 1); start++)
    {
        minIndex = start;
        minValue = *(ptr + start);
        for(int index = start + 1; index < size; index++)
        {
            if(*(ptr + index) < minValue)
            {
                minValue = *(ptr + index);
                minIndex = index;
            }
        }

        // swap
        int temp = *(ptr + minIndex);
        *(ptr + minIndex) = *(ptr + start);
        *(ptr + start) = temp;
    }
}