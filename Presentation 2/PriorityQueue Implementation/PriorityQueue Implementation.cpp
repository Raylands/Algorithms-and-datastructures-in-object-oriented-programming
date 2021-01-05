#include <iostream>
#include "PriorityQueue.hpp"

int main()
{
    ListPriorityQueue<int> LPQ;

    std::function<bool(int,int)> isLess = [](int a, int b) -> bool {
        return a < b;
    };

    LPQ.insert(1, [](int a, int b) -> bool {
        return a < b;
               });
    LPQ.insert(8, isLess);
    LPQ.insert(5, isLess);

    std::cout << "Max: " << LPQ.max() << std::endl;
    std::cout << "Min: " << LPQ.min() << std::endl;
    std::cout << "Removing min..." << std::endl;
    LPQ.removeMin();
    std::cout << "Min: " << LPQ.min() << std::endl;
}
