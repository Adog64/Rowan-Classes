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
#include <vector>
#include <string>
#include "PDS_IntBinaryTree.h"

/// @brief Read data from a file into a binary tree
/// @param tree binary tree to read into
/// @param removals list of items to remove from binary tree
/// @param searchTerms list of items to search tree for
/// @param hasMetadata whether or not each line's first entry is the entry count
/// @param fname file to read from
void ReadBTFromFile(IntBinaryTree *tree, std::vector<int> *removals, std::vector<int> *searchTerms, bool hasMetadata, std::string fname);

int main()
{
	IntBinaryTree binTree = IntBinaryTree();
	std::vector<int> removals;
	std::vector<int> searchTerms;
	char hasMetadataAnswer;
	bool hasMetadata;
	std::string fname;
	std::cout << "Data file name and path relative to Makefile:\n";
	std::cin >> fname;
	std::cout << "Does data set contain metadata? [y/N]\n";
	std::cin >> hasMetadataAnswer; 
	hasMetadata = tolower(hasMetadataAnswer) == 'y';

	ReadBTFromFile(&binTree, &removals, &searchTerms, hasMetadata, fname);
	std::cout << "In Order: ";
	binTree.showInOrder();
	std::cout << "\nPre-Order: ";
	binTree.showPreOrder();
	std::cout << "\nPost-Order: ";
	binTree.showPostOrder();
	std::cout << "\nLeaf Nodes: ";
	binTree.showLeafNodes();
	std::cout << "\nMax: " << binTree.getMax();
	std::cout << "\nMin: " << binTree.getMin();
	std::cout << "\nNode Count: " << binTree.getNodeCount();
	std::cout << "\nSum: " << binTree.getSum();
	std::cout << "\nMean: " << binTree.getMean();

	std::cout << "\nRemoving values";
	for (int removal : removals)
	{
		std::cout << ' ' << removal;
		binTree.remove(removal);
	}

	std::cout << "\nIn Order: ";
	binTree.showInOrder();
	std::cout << "\nPre-Order: ";
	binTree.showPreOrder();
	std::cout << "\nPost-Order: ";
	binTree.showPostOrder();
	std::cout << "\nLeaf Nodes: ";
	binTree.showLeafNodes();
	std::cout << "\nMax: " << binTree.getMax();
	std::cout << "\nMin: " << binTree.getMin();
	std::cout << "\nNode Count: " << binTree.getNodeCount();
	std::cout << "\nSum: " << binTree.getSum();
	std::cout << "\nMean: " << binTree.getMean();
	
	std::cout << "\nSearching for values:\n";
	for(int term : searchTerms)
		std::cout << term << ((binTree.search(term)) ? " found" : " not found") << std::endl;

	
	return 0;
}

void ReadBTFromFile(IntBinaryTree *tree, std::vector<int> *removals, std::vector<int> *searchTerms, bool hasMetadata, std::string fname)
{
    std::ifstream infile;
    std::string line;
    infile.open(fname);
	bool isFirstEntry;
	int lineNum = 0;
    while (std::getline(infile, line))
    {	
		isFirstEntry = true;
        std::string snum;
        for (int i = 0; i < line.length(); i++)
        {
			if (isdigit(line.at(i)))
				snum.push_back(line.at(i));
            if (line.at(i) == ' ' || i == line.length() - 1)
			{
				if (!(hasMetadata && isFirstEntry))
				{
					switch (lineNum)
					{
					case 0:
            			tree->insert(std::stoi(snum));
						break;
					case 1:
						removals->push_back(std::stoi(snum));
						break;
					case 2:
						searchTerms->push_back(std::stoi(snum));
						break;
					}
				}
                snum = "";
				isFirstEntry = false;
            }
			
		}
		lineNum++;
    }
    infile.close();
}