#define COUNTER_H

class Counter
{
    private:
        int value, maxValue;
    public:
        void setCount(int);
        void increment();
        void decrement();
        int getCount();
        int getMaxValue();
};