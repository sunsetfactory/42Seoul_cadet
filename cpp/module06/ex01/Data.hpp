#ifndef DATA_HPP
#define DATA_HPP

struct Data
{
    // You must create a non-empty (it means it has data members) Data structure.
    long sirialNumber;
    int value;

    // constructor, initializer list
    Data(long sirialNumber, int value) : sirialNumber(sirialNumber), value(value)
    {
    }
};

#endif