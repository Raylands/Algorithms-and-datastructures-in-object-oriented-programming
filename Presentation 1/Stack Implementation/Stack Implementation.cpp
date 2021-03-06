#include <iostream>
#include "VectorStack.hpp"

int main()
{
    VectorStack<int> VS;
    VS.push(5);
    VS.push(10);
    VS.push(15);
    VS.push(20);

    printf("VectorStack size: %d \n", VS.size());
    printf("VectorStack top: %d \n", VS.top());
    printf("Removing top...\n");
    VS.pop();
    printf("VectorStack new size: %d \n", VS.size());
    printf("VectorStack new top: %d \n", VS.top());
}