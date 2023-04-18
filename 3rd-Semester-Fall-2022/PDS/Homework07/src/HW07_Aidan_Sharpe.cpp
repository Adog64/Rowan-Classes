/****************************************************************
* Name: Aidan Sharpe
* Course: Principles of Data Structures
* Class: CS04225
* Assignment Date: November 07, 2022
* File Name: HW07_Aidan_Sharpe.cpp
*****************************************************************
* ID: Homework 7 Problem 1
* Purpose: Read values into a binary tree and show the data in several ways
*****************************************************************/

#include <iostream>
#include <fstream>
#include "PDS_IntBinaryTree.h"

/// @brief Read data from a file into a binary tree
/// @param tree binary tree to read into
/// @param fname file to read from
void ReadBTFromFile(IntBinaryTree *tree, std::string fname);

int main()
{
	IntBinaryTree binTree = IntBinaryTree();
	std::string fname;
	std::cout << "Data file name and path relative to Makefile:\n";
	std::cin >> fname;
	ReadBTFromFile(&binTree, fname);
	std::cout << "In Order: ";
	binTree.showInOrder();
	std::cout << "\nPre-Order: ";
	binTree.showPreOrder();
	std::cout << "\nPost-Order: ";
	binTree.showPostOrder();
	std::cout << "\nLeaf Nodes: ";
	binTree.showLeafNodes();		// custom function to show leafnodes (located in PDS_IntBinaryTree.h)
	std::cout << std::endl;
	return 0;
}

void ReadBTFromFile(IntBinaryTree *tree, std::string fname)
{
    std::ifstream infile;
    std::string line;
    infile.open(fname);
    while (std::getline(infile, line))
    {
        std::string snum;
        for (int i = 0; i < line.length(); i++)
        {
			if (isdigit(line.at(i)))
				snum.push_back(line.at(i));
            if (line.at(i) == ' ' || i == line.length() - 1)
			{
            	tree->insert(std::stoi(snum));
                snum = "";
            }
			
		}
    }
    infile.close();
}