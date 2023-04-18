/***************************************************************
* Name: Aidan Sharpe
* Course: Computer Science & Programming
* Class: CS04103 Section: 6
* Assignment Date: 12.08.2021
* File Name: Lab11-1ASharpe.cpp
*****************************************************************
* ID: Lab 11 Problem 1
* Purpose: Output the last 10 entries of a file
*****************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<string> lines;
	string line;
	ifstream infile("test.txt");

	// store lines in a vector
	while (getline(infile, line))
		lines.push_back(line);

	// vector size is the number of lines
	cout << "Number of lines: " << lines.size() << endl
		 << "Last 10 entries:" << endl << endl;

	// output last 10 indicies of the vector
	for (int i = 10; i > 0; i--)
		cout << lines.at(lines.size() - i) << endl;

	return 0;
}