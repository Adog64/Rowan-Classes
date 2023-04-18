/****************************************************************
* Name: Aidan Sharpe
* Course: Principles of Data Structures
* Class: CS04225
* Assignment Date: November 07, 2022
* File Name: HW06_Aidan_Sharpe.cpp
*****************************************************************
* ID: Homework 6 Problem 1
* Purpose: Read state info data into and out of maps
*****************************************************************/

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <algorithm>

struct state{
	std::string name, abrreviation, capitol;
	int population, area;
};

int main()
{
	std::ifstream infile;
	std::map<std::string, state> stateInfo;
	infile.open("StatesInfo.txt");

	// parse state info into a map
	for (int i=0; i<50; i++)
	{
		state s;
		std::getline(infile, s.name);
		std::getline(infile, s.abrreviation);
		std::getline(infile, s.capitol);
		std::string temp;
		std::getline(infile, temp);
		temp.erase(std::remove(temp.begin(), temp.end(), ','), temp.end()); // remove commas
		s.population = std::stoi(temp);
		std::getline(infile, temp);
		temp.erase(std::remove(temp.begin(), temp.end(), ','), temp.end()); // remove commas
		s.area = std::stoi(temp);

		stateInfo.emplace(s.abrreviation, s); // add state to state info; state referenced by abbreviation
	}

	bool quit = false;
	std::string abbr;

	// query state info from shell
	while (true)
	{
		std::cout << "Enter a U.S. State Abbreviation or 'Q' to quit.\n";
		std::cin >> abbr;
		if (abbr == "Q" || abbr == "q")
			break;
		if (stateInfo.count(abbr))
		{
			std::cout << "Name: " << stateInfo[abbr].name << '\n';
			std::cout << "Abbreviation: " << stateInfo[abbr].abrreviation << '\n';
			std::cout << "Capitol: " << stateInfo[abbr].capitol << '\n';
			std::cout << "Population: " << stateInfo[abbr].population << '\n';
			std::cout << "Area: " << stateInfo[abbr].area << " square miles\n";
		}
		else
			std::cout << "Not a valid U.S. State Abbreviation.\n";
	}
	return 0;
}
