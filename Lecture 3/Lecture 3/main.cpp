/*
    Write a C++ class that is derived from the Progression class to produce a
    progression where each value is the absolute value of the difference between
    the previous two values. You should include a default constructor that starts
    with 2 and 200 as the first two values and a parametric constructor that
    starts with a specified pair of numbers as the first two values.
*/

#include <iostream>
#include "Progession.h"

using namespace std;

int main()
{
    Absolute a(74,2000);
    
    for (size_t i = 0; i < 10; i++)
    {
        a.nextValue();

        a.printProgression();
    }
    

    cin.get();
}

