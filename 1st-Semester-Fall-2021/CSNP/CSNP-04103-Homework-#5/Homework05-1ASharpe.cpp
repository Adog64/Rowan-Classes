/***************************************************************
* Name: Aidan Sharpe
* Course: Computer Science & Programming
* Class: CS04103 Section: 6
* Assignment Date: 10.18.2021
* File Name: Homework05-1ASharpe.cpp
*****************************************************************
* ID: Homework 5 Problem 1
* Purpose: Simulate a population for N years
*****************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

int getPopAfterNYears(int, float, float, int);

int main()
{
    int pop, time;
    float birthRate, deathRate;

    // get population data
    do
    {
    cout << "Original population size: ";
    cin >> pop;
    } while ( pop < 2 );                            // ensure that population is at least 2
    do
    {
    cout << "Birth rate: ";
    cin >> birthRate;
    } while ( static_cast<int>(birthRate) != 0 );   // make sure birthRate is between 0 and 1
    do
    {
        cout << "Death rate: ";
        cin >> deathRate;
    } while ( static_cast<int>(deathRate) != 0 );   // make sure deathRate is between 0 and 1
    
    do
    {    
        cout << "Time: ";
        cin >> time;
    } while ( time < 1 );                           // ensure that time is at least 1 year
    
    // calculate & print the new population size after "time" years
    // note that pop is an int, so it will only increase 
    cout << "Population after " << time << " years: " << getPopAfterNYears(pop, birthRate, deathRate, time);
    return 0;
}

int getPopAfterNYears(int pop, float birthRate, float deathRate, int time)
{
    // find new population size for each year in the time range    
    for (; time > 0; time--)
        pop = pop * (1 + birthRate) * (1 - deathRate);
    return pop;
}
