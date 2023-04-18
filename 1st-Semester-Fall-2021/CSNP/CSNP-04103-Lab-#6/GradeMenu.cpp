#include <iostream>
#include "GradeMenu.h"

using namespace std;

// display the selection menu and prompt the user
void GradeMenu::displayMenu()
{
    cout << "1. Enter student and grade information" << endl
         << "2. Adjust student grade information" << endl
         << "3. Display sudent grades" << endl
         << "4. Exit" << endl << endl
         << ">>> ";
}