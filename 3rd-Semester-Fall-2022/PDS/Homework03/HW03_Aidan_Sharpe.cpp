/****************************************************************
* Name: Aidan Sharpe
* Course: Principles of Data Structures
* Class: CS04225
* Assignment Date: October 10, 2022
* File Name: HW03_Aidan_Sharpe.cpp
*****************************************************************
* ID: Homework 3 Problem 1
* Purpose: Read, sort and write, ints from text files
*****************************************************************/

#include <iostream>
#include <fstream>
#include <string>

/// @brief sort a dynamically allocated array in-place
/// @param arrptr pointer to first element in dynamically allocated array
/// @param len length of dynamically allocated array
/// @return true if the array was sorted successfully
bool dynamicArraySelectionSort(int *arrptr, int len);

int main()
{
    std::string fname;
    std::string line;
    std::ifstream readfile;
    std::ofstream writefile;
    std::cout << "Input file name:\n";
    std::cin >> fname;
    readfile.open(fname);
    std::getline(readfile, line);

    int num_count = std::stoi(line);
    std::cout << "Reading " << num_count << " numbers...\n";

    int *nums_ptr;
    nums_ptr = new int[num_count];


    // read numbers from file
    // numbers are multi-digit and separated by either a space or newline char
    int idx = 0;
    while (std::getline(readfile, line))
    {
        std::string snum;
        for (char c : line)
        {
            if (isdigit(c))
                snum.push_back(c);
            else if (c == ' ' || c == '\n')
            {
                *(nums_ptr + idx) = std::stoi(snum);
                snum = "";
                idx++;  
            } 
        }
    }
    readfile.close();
    std::cout << "Done reading values.\n";

    // sort numbers
    std::cout << "Sorting values...\n";
    dynamicArraySelectionSort(nums_ptr, num_count);
    
    std::cout << "Enter filename for sorted values:\n";
    std::cin >> fname;
    writefile.open(fname);

    // write sorted nums to file with 8 columns
    std::cout << "Writing values to " << fname << "...\n";
    for (int i = 0; i < num_count/8 + 1; i++)
    {
        for (int j = 0; j < 8 && i*8 + j < num_count; j++)
            writefile << *(nums_ptr + i*8 + j) << " ";
        writefile << "\n";
    }
    writefile.close();
    std::cout << "Done writing values.\n";
    
    // clear dynamically allocated pointers
    delete [] nums_ptr;
    nums_ptr = nullptr;

    return 0;
}


bool dynamicArraySelectionSort(int *arrptr, int len)
{
    int temp;           // throw-away variable for swapping
    int mindex = 0;     // index of the smallest number
    for (int i = 0; i < len - 1; i++)
    {
        mindex = i;
        // find index of smallest element
        for (int j = i; j < len; j++)
            if (*(arrptr + j) < *(arrptr + mindex))
                mindex = j;

        // swap element at i with smallest element
        if (mindex > i)
        {
            temp = *(arrptr + mindex);
            *(arrptr + mindex) = *(arrptr + i);
            *(arrptr + i) = temp;
        }
    }
    return true;
}

