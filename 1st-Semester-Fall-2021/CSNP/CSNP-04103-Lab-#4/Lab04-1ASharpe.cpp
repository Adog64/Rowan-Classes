/***************************************************************
* Name: Aidan Sharpe
* Course: Computer Science & Programming
* Class: CS04103 Section: 6
* Assignment Date: 10.06.2021
* File Name: Lab04-1ASharpe.cpp
*****************************************************************
* ID: Lab 4 Problem 1
* Purpose: Run an election machine simulation
*****************************************************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    bool voting = true, firstAttempt = true;
    const string candidate1 = "Donald Trump", candidate2 = "Joe Biden";     // names of the candidates
    int vote = 0;
    int votes[2] = {0, 0};                                                  // votes for each of the two candidates
    ofstream outFile;
    outFile.open("results.txt");

    while ( voting )
    {
        firstAttempt = true;
        vote = -1;
        do
        {
            // voter intro screen
            if ( firstAttempt )
                cout << "\n\n\n"
                     << "***********************************************************************\n"
                     << "*                     WELCOME TO THE 2020 ELECTION                    *\n"
                     << "***********************************************************************\n";

            // invalid input instructions
            else
                cout << "\nWARNING: you have entered an invalid selection. Valid selections include (1), (2)\n";

            // voter instructions
            cout << "Please select (1) to vote for " << candidate1 << " (2) to vote for " << candidate2 << " :";
            cin >> vote;

            // break condition
            if (vote == 999)
            {
                voting = false;

                // put the results in a file
                outFile << candidate1 + ": " + to_string(votes[0]) + "\n" + candidate2 + ": " + to_string(votes[1]);
                outFile.close();
                break;
            }

            firstAttempt = false;
        } while (vote != 1 && vote != 2);

        votes[0] += (vote == 1) ? 1 : 0;    // conditionally incrament candidate 1
        votes[1] += (vote == 2) ? 1 : 0;    // conditionally incrament candidate 2
    }

    // voting results screen
    cout << "\n\n\n"
         << "***********************************************************************\n"
         << "*                        2020 ELECTION RESULTS                        *\n"
         << "***********************************************************************\n";

    cout << endl << candidate1 << ": " << votes[0] << "\t\t\t" << candidate2 << ": " << votes[1] << endl;

    return 0;
}
