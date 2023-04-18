/****************************************************************
* Name: Aidan Sharpe
* Course: Principles of Data Structures
* Class: CS04225
* Assignment Date: October 17, 2022
* File Name: HW04_Aidan_Sharpe.cpp
*****************************************************************
* ID: Homework 4 Problem 1
* Purpose: Read values to a linked list and rewrite them in reversed order
*****************************************************************/

#include <iostream>
#include <string>
#include <fstream>

struct LL_Node
{
    int val;
    LL_Node *next;

    LL_Node(int d, LL_Node *p=nullptr)
    {
        val = d;
        next = p;
    }
};

/// @brief Adds a new node to the end of a linked list starting at memory address head
/// @param head address of first node
/// @param val value to add
void AddNodeEnd(LL_Node *&head, int val);

/// @brief Adds a new node to the begining of a linked list starting at memory address head
/// @param head address of first node
/// @param val value to add
void AddNodeBegin(LL_Node *&head, int val);

/// @brief prints a linked list in format [m0, m1, ... , mn]
/// @param head address of first node
void PrintLL(LL_Node *head);

/// @brief write a linked list to a space-separated text file
/// @param head address of first list node
/// @param fname file path relative to source directory
void WriteLLToFile(LL_Node *head, std::string fname);

/// @brief read LL from space/newline separated file
/// @param head address of first list node
/// @param fname file path relative to source directory
/// @param reversed whether or not to reverse the order of numbers
void ReadLLFromFile(LL_Node *&head, std::string fname, bool reversed=false);

int main()
{
    LL_Node *head = nullptr;
    std::string in, out;
    std::cout << "Input data file name (path relative to makefile directory):\n";
    std::cin >> in;
    ReadLLFromFile(head, in, true);
    std::cout << "Output data file name (path relative to makefile directory):\n";
    std::cin >> out;
    WriteLLToFile(head, out);
    return 0;
}

void AddNodeEnd(LL_Node *&head, int val)
{
    if (head == nullptr)
        head = new LL_Node(val);
    else
    {
        LL_Node* p = head;
        while (p->next != nullptr)
            p = p->next;
        p->next = new LL_Node(val);
    }
}

void AddNodeBegin(LL_Node *&head, int val)
{
    LL_Node *p = new LL_Node(val);
    p->next = head;
    head = p;
}

void PrintLL(LL_Node *head)
{
    LL_Node *p = head;
    std::cout << "[";
    while (p != nullptr)
    {
        std::cout << p->val;
        p = p->next;
        std::cout << ((p != nullptr) ? ", " : "]\n"); // separate elements by ',' and add close bracket if it's the last node
    }
}

void WriteLLToFile(LL_Node *head, std::string fname)
{
    std::ofstream outfile;
    outfile.open(fname);
    LL_Node* p = head;
    while(p != nullptr)
    {
        outfile << p->val << ' ';
        p = p->next;
    }
    outfile.close();
}

void ReadLLFromFile(LL_Node *&head, std::string fname, bool reversed)
{
    std::ifstream infile;
    std::string line;
    infile.open(fname);
    while (std::getline(infile, line))
    {
        std::string snum;
        for (char c : line)
        {
            if (isdigit(c))
                snum.push_back(c);
            else if (c == ' ' || c == '\n')
            {
                if (reversed)
                    AddNodeBegin(head, std::stoi(snum));
                else
                    AddNodeEnd(head, std::stoi(snum));
                snum = "";
            } 
        }
    }
    infile.close();
}