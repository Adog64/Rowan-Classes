/***************************************************************
* Name: Aidan Sharpe
* Course: Computer Science & Programming
* Class: CS04103 Section: 6
* Assignment Date: 10.27.2021
* File Name: main.cpp
*****************************************************************
* ID: Lab 6 Problem 1
* Purpose: Manage the grades of 3 students
*****************************************************************/

#include <iostream>
#include <string>
#include "GradeMenu.h"

using namespace std;

void enterGrades(struct Student[]);
void adjustGrades(struct Student[]);
void displayGrades(struct Student[]);

struct Student
{
    string name;
    int classId;
    float grade;
};

int main()
{
    int selection = 1;
    char tryAgain;
    Student students[3];
    GradeMenu gm = GradeMenu();
    
    do
    {   
        // display the selection menu
        gm.displayMenu();
        cin >> selection;
        
        // clear the screen and continue
        system("clear");
        switch (selection)
        {
            case 1:
                enterGrades(students);
                break;
            case 2:
                adjustGrades(students);
                break;
            case 3:
                displayGrades(students);
                break;
            case 4:
                return 0;
                
            // if the entry is invalid, the default case will execute
            default:
                cout << "INVALID INPUT: please enter a value between 1 and 4. Input c to try again." << endl;
                cin >> tryAgain;
                if (tryAgain != 'c')
                    return 0;
        }
    } while (true); // run until the user exits the program or does not try again after invalid input
    
}

// edit all properties of each student
void enterGrades(Student students[])
{
    for(int i = 0; i < 3; i++)
    {
        cout << endl << "Full Name: ";
        cin.ignore();
        getline(cin, students[i].name);
        cout << "Class ID: ";
        cin >> students[i].classId;
        cout << "Grade: ";
        cin >> students[i].grade;
    }
}

// loop through each student in the list and update his grade
void adjustGrades(Student students[])
{
    for(int i = 0; i < 3; i++)
    {
        cout << "New Grade for " << students[i].name << ": ";
        cin >> students[i].grade;
        cout << endl;
    }
}

// display the grade of each student
void displayGrades(Student students[])
{
    for(int i = 0; i < 3; i++)
    {
        cout << "Student ID: " << i + 1 << endl
             << "Full Name:  " << students[i].name << endl
             << "Grade:      " << students[i].grade << endl
             << "Class ID:   " << students[i].classId << endl << endl;
    }
}