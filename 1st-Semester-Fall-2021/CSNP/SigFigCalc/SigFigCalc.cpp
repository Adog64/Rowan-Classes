#include <iostream>
#include <string>

using namespace std;

int main()
{
    string num;
    cin >> num;

    
    int decimal = num.find( '.' );

    //remove decimal point
    if (  decimal >= 0)
        num.erase( '.' );
    else
        //remove trailing zeroes
        while (num.back() == '0')
            num = num.substr( num.length() - 1 );

    //remove leading zeros
    while (num.front() == '0')
        num = num.substr(1);

    cout << num.length();

    return 0;
}