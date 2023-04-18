/***************************************************************
* Name: Aidan Sharpe
* Course: Computer Science & Programming
* Class: CS04103 Section: 6
* Assignment Date: 2021.12.01
* File Name: Lab10-1ASharpe.cpp
*****************************************************************
* ID: Lab 0 Problem 1
* Purpose: Playing with cstrings
*****************************************************************/
#include <iostream>

using namespace std;

int main()
{
	char fName[10], mName[10], mlName[10], lName[10], fullName[80];

	cout << "Enter your first name: ";
	cin >> fName;
	cout << "Enter your middle name: ";
	cin >> mName;
	cout << "Enter your maiden name: ";
	cin >> mlName;
	cout << "Enter your husbands last name: ";
	cin >> lName;

	strcpy(fullName, lName);
	strcat(fullName, ", ");
	strcat(fullName, fName);
	strcat(fullName, " ");
	strcat(fullName, mName);

	cout << "\nYour married name is: " << fullName;
}