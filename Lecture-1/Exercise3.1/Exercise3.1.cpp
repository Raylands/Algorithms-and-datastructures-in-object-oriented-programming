#include "Flower.h"

/*
Write a C++ class, Flower, that has three member variables of type string, int, and float,
which respectively represent the name of the flower, its number of pedals, and price. Your
class must include a constructor method that initializes each variable to an appropriate
value, and your class should include functions for setting the value of each type, and getting
the value of each type.
*/

int main()
{
    Flower a("a", 1, 1);

    cout << a.GetName() << endl;
}
