/****************************************************************
* Name: Aidan Sharpe
* Course: Principles of Data Structures
* Class: CS04225
* Assignment Date: September 23, 2022
* File Name: HW02_Aidan_Sharpe.cpp
*****************************************************************
* ID: Homework 2 Problem 1
* Purpose: Sort and search through a vector of ints
*****************************************************************/

#include <iostream>
#include <vector>

/// @brief Sort an incoming vector via selection sort
/// @param vals Vector of random integers
/// @return Original values sorted in ascending order
std::vector<int> vectorSelectionSort(std::vector<int> vals);

/// @brief Find val in vals with linear search
/// @param val number to find
/// @param vals ints to look through
/// @return {index, # of comparisons}
std::vector<int> vecIntLinearSearch(int val, std::vector<int> vals);

/// @brief Find val in vals with binary search
/// @param val number to find
/// @param vals ints to look through
/// @return {index, # of comparisons}
std::vector<int> vecIntBinarySearch(int val, std::vector<int> vals);

/// @brief print a vector of ints
/// @param vals vector to print
/// @param isSorted whether or not the vector is known to be sorted
void printVecInt(std::vector<int> vals, bool isSorted);

int main()
{
    std::vector<int> vals{
        8284, 4663, 5670, 2284, 1197, 
        9109, 6547, 7652, 7925, 2421, 
        8717, 6976, 1671, 5533, 1170, 
        1112, 4921, 9702, 4177, 9821, 
        2454, 3211, 5594, 2417, 7294
    };

    printVecInt(vals, false);
    vals = vectorSelectionSort(vals);
    printVecInt(vals, true);

    int sel;
    std::cout << "Query a number:\n";
    std::cin >> sel;

    std::vector<int> linearS = vecIntLinearSearch(sel, vals);
    if (linearS[0] >= 0)
        std::cout << "Value " << sel << " was found with linear search at index " << linearS[0] << " with " << linearS[1]<< " comparisons.\n";
    else
        std::cout << "Linear search could not find " << sel << " after " << linearS[1] << " comparisons\n";

    std::vector<int> binaryS = vecIntBinarySearch(sel, vals);
    if (binaryS[0] >= 0)
        std::cout << "Value " << sel << " was found with binary search at index " << binaryS[0] << " with " << binaryS[1]<< " comparisons.\n";
    else
        std::cout << "Binary search could not find " << sel << " after " << binaryS[1] << " comparisons\n";
    return 0;
}

std::vector<int> vectorSelectionSort(std::vector<int> vals)
{
    int temp;           // throw-away variable for swapping
    int mindex = 0;     // index of the smallest number
    for (int i = 0; i < vals.size() - 1; i++)
    {
        mindex = i;
        // find index of smallest element
        for (int j = i; j < vals.size(); j++)
            if (vals[j] < vals[mindex])
                mindex = j;

        // swap element at i with smallest element
        if (mindex > i)
        {
            temp = vals[mindex];
            vals[mindex] = vals[i];
            vals[i] = temp;
        }
    }
    return vals;
}

void printVecInt(std::vector<int> vals, bool isSorted)
{
    const int COLS = 5;     
    std::cout << "Values (" << ((isSorted) ? "" : "un") << "sorted):\n";
    for (int i = 0; i < vals.size() / COLS + 1; i++)
    {
        for (int j = 0; j < COLS && i*COLS + j < vals.size(); j++)
            std::cout << vals[i*COLS + j] << ", ";
        std::cout << std::endl;     
    }
}

std::vector<int> vecIntLinearSearch(int val, std::vector<int> vals)
{
    for (int i = 0; i < vals.size(); i++)
    {
        if (val == vals[i])
            return std::vector<int>{i, i};
    }
    return std::vector<int>{-1, (int)vals.size()};
}

std::vector<int> vecIntBinarySearch(int val, std::vector<int> vals)
{
    int min = 0, mid = (int)vals.size()/2, max = (int)vals.size() - 1;
    bool found = false;
    int comps = 0;
    while (min != max)
    {
        comps++;
        // short circuit find
        if (vals[mid] == val)
            return std::vector<int>{mid, comps};
        // shrink search space to top half of remaining set
        else if (vals[mid] < val)
        {
            min = mid + 1;
            mid = (max + min)/2;
        }
        // shrink search space to bottom half of remaining set
        else
        {
            max = mid - 1;
            mid = (max + min)/2;
        }
    }
    // if val is at the last remaining position, it has been found; else it has been proven to not be in the list
    return (vals[mid] == val) ? std::vector<int>{mid, comps} : std::vector<int>{-1, comps};
}