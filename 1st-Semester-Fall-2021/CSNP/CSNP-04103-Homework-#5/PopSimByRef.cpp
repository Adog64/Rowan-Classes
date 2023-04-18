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

void simulateForNYears(int&, float, float, int);

int main()
{
    int pop, time;
    float birthRate, deathRate;

    // get population data
    do
    {
    cout << "Original population size: ";
    cin >> pop;
    } while ( pop < 2 );
    cout << "Birth rate: ";
    cin >> birthRate;
    cout << "Death rate: ";
    cin >> deathRate;
    do
    {    
        cout << "Time: ";
        cin >> time;
    } while ( time < 1 );

    // run simulation
    // note that pop is passed by reference
    simulateForNYears(pop, birthRate, deathRate, time);

    // print the new population size after "time" years
    // note that pop is an int, so it will only increase 
    cout << "Population after " << time << " years: " << pop;
    return 0;
}

void simulateForNYears(int& pop, float birthRate, float deathRate, int time)
{
    // find new population size for each year in the time range    
    for (; time > 0; time--)
        pop = pop * (1 + birthRate) * (1 - deathRate);
}
