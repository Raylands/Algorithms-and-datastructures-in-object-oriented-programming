#include <iostream>
#include "VectorStack.hpp"
#include "VectorStack.cpp"

int main()
{
    VectorStack<int> VS;
    VS.push(5);
    VS.push(10);
    VS.push(15);
    VS.push(20);

    printf("VectorStack size: %d \n", VS.size());
    printf("VectorStack top: %d \n", VS.top());

    VS.pop();
    printf("VectorStack top: %d \n", VS.top());
}