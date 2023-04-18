#include "Counter.h"
#include <climits>

// Counter::Counter()
// {
//     maxValue = INT_MAX;
// }

void Counter::setCount(int num)
{
    value = num;
}

void Counter::increment()
{
    ++value;
}

void Counter::decrement()
{
    --value;
}

int Counter::getCount()
{
    return value;
}

int Counter::getMaxValue()
{
    return maxValue;
}