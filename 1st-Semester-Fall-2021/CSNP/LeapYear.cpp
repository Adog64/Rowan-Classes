#include <iostream>

using namespace std;

int main()
{
    int year;

    cout << "Enter a year: ";
    cin >> year;

    cout << " is" << (( year >= 1582 && (year % 100 != 0 || year % 400 == 0) && year % 4 == 0) ? " " : " not ") << "a leap year.";

    return 0;
}