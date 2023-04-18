/****************************************************************
* Name: Aidan Sharpe
* Course: Principles of Data Structures
* Class: CS04225
* Assignment Date: November 07, 2022
* File Name: ECHW_Aidan_Sharpe.cpp
*****************************************************************
* ID: Homework 7 Problem 1
* Purpose: Read values into a binary tree and show the data in several ways
*****************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "PDS_BinaryTree.h"


void ReadBTIntFromFile(BinaryTree<int> *tree, std::vector<int> *removals, std::vector<int> *searchTerms, bool hasMetadata, std::string fname);
void ReadBTCharFromFile(BinaryTree<char> *tree, std::vector<char> *removals, std::vector<char> *searchTerms, bool hasMetadata, std::string fname);
void ReadBTDoubleFromFile(BinaryTree<double> *tree, std::vector<double> *removals, std::vector<double> *searchTerms, bool hasMetadata, std::string fname);

int main()
{
	char type;
	std::string fname;
    char hasMetadataAnswer;
    bool hasMetadata;
	std::cout << "Path of data file relative to Makefile.\n";
    std::cin >> fname;
	std::cout << "Enter type of data. I for ints, C for chars, D for doubles.\n";
	std::cin >> type;
    std::cout << "Does data set contain metadata? [y/N]\n";
	std::cin >> hasMetadataAnswer; 
    hasMetadata = tolower(hasMetadataAnswer) == 'y';

    if (type == 'C')
    {
        BinaryTree<char> binTree = BinaryTree<char>(); 
        std::vector<char> removals;
        std::vector<char> searchTerms;
        ReadBTCharFromFile(&binTree, &removals, &searchTerms, hasMetadata, fname);
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
        for (char removal : removals)
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
        for(char term : searchTerms)
            std::cout << term << ((binTree.search(term)) ? " found" : " not found") << std::endl;
    }
    else if(type == 'I')
    {
        BinaryTree<int> binTree = BinaryTree<int>(); 
        std::vector<int> removals;
        std::vector<int> searchTerms;
        ReadBTIntFromFile(&binTree, &removals, &searchTerms, hasMetadata, fname);std::cout << "In Order: ";
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
    }
    else if(type == 'D')
    {
        BinaryTree<double> binTree = BinaryTree<double>(); 
        std::vector<double> removals;
        std::vector<double> searchTerms;
        ReadBTDoubleFromFile(&binTree, &removals, &searchTerms, hasMetadata, fname);
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
        for (double removal : removals)
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
        for(double term : searchTerms)
            std::cout << term << ((binTree.search(term)) ? " found" : " not found") << std::endl;
    }
    else
        std::cout << "Selection " << type << " does not signify any valid type.\n";
	return 0;
}


void ReadBTIntFromFile(BinaryTree<int> *tree, std::vector<int> *removals, std::vector<int> *searchTerms, bool hasMetadata, std::string fname)
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

void ReadBTCharFromFile(BinaryTree<char> *tree, std::vector<char> *removals, std::vector<char> *searchTerms, bool hasMetadata, std::string fname)
{
    std::ifstream infile;
    std::string line;
    infile.open(fname);
	int lineNum = 0;
    bool isFirstEntry;
    char c;
    while (std::getline(infile, line))
    {	
        isFirstEntry = true;
        for (int i = 0; i < line.length(); i++)
        {   
            if (line.at(i) != ' ')
                c = line.at(i);     
            if (line.at(i) == ' ' || i == line.length() - 1)
			{
            	if (!(hasMetadata && isFirstEntry))
				{
					switch (lineNum)
					{
					case 0:
            			tree->insert(c);
						break;
					case 1:
						removals->push_back(c);
						break;
					case 2:
						searchTerms->push_back(c);
						break;
					}
				}
				isFirstEntry = false;
            }         
		}
		lineNum++;
    }
    infile.close();
}

void ReadBTDoubleFromFile(BinaryTree<double> *tree, std::vector<double> *removals, std::vector<double> *searchTerms, bool hasMetadata, std::string fname)
{
    std::ifstream infile;
    std::string line;
    infile.open(fname);
	int lineNum = 0;
    bool isFirstEntry;
    while (std::getline(infile, line))
    {
        isFirstEntry = true;
        std::string snum;
        for (int i = 0; i < line.length(); i++)
        {
			if (isdigit(line.at(i)) || line.at(i) == '.')
				snum.push_back(line.at(i));
            if (line.at(i) == ' ' || i == line.length() - 1)
			{
            	if (!(hasMetadata && isFirstEntry))
				{
					switch (lineNum)
					{
					case 0:
            			tree->insert(std::stod(snum));
						break;
					case 1:
						removals->push_back(std::stod(snum));
						break;
					case 2:
						searchTerms->push_back(std::stod(snum));
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