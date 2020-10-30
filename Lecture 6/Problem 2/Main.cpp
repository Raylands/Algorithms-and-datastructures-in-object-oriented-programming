#include <iostream>

using namespace std;

int log2(int number);

int main()
{
    int number;
    cout << "Input number for log2 calculation: ";
    cin >> number;
    cout << log2(number);
}

int log2(int number)
{
    if (number <= 1) return 0;
    return 1 + log2(number / 2);
}