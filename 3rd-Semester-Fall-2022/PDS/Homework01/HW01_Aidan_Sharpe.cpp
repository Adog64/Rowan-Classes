/****************************************************************
* Name: Aidan Sharpe
* Course: Principles of Data Structures
* Class: CS04225
* Assignment Date: September 19, 2022
* File Name: HW01_Aidan_Sharpe.cpp
*****************************************************************
* ID: Homework 1 Problem 1
* Purpose: Recieve and perform an operation on 5 numbers
*****************************************************************/

#include <iostream>
#include <string>

#define ENTRIES 5

int main()
{
    std::string entry;
    int nums[ENTRIES];
    int sum = 0, max, min;

    // get entries
    for(int i = 0; i < ENTRIES; i++)
    {
        std::cout << "Enter int (" << i+1 << "):\n";
        std::cin >> entry;
        nums[i] = std::stoi(entry);
    }  
    min = nums[0];
    max = nums[0];

    std::cout << "Values Entered:";
    for(int i = 0; i < ENTRIES; i++)
    {
        std::cout << " " << nums[i];            // repeat entries
        min = (nums[i] < min) ? nums[i] : min;  // update min to current min
        max = (nums[i] > max) ? nums[i] : max;  // update max to current max
        sum += nums[i];
    }
    std::cout << "\nSUM:\t" << sum << std::endl;
    std::cout << "MAX:\t" << max << std::endl;
    std::cout << "MIN:\t" <<  min << std::endl;
    std::cout << "AVG:\t" << (float)sum / ENTRIES << std::endl;

    return 0;
}