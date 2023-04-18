#include <iostream>
#include "Counter.h"

using namespace std;

int main()
{
    Counter c = Counter();
    int num;

    cout << "The current count is " << c.getCount() << endl;    // show that we can get the count

    cout << "Enter a new number for the count: ";               // show that we can change the count
    cin >> num;
    c.setCount(num);
    cout << "The new count is " << c.getCount() << endl;

    cout << "Incramenting the count..." << endl;                // show that we can increment the count
    c.increment();
    cout << "The new count is " << c.getCount() << endl;

    cout << "Decrementing the count..." << endl;                // show that we can decrement the count
    c.decrement();
    cout << "The new count is " << c.getCount() << endl;

    return 0;
}
