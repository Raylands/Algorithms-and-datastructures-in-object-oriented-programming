#include <iostream>
#include <list>
#include <functional>

using namespace std;

template <typename T>
void mergeSort(list<T>& S, const function<bool(int, int)> f);
template <typename T>
void merge(list<T>& S1, list<T>& S2, list<T>& S, const function<bool(T, T)> f);



int main()
{
    list<int> S{ 5, 3, 2, 1, 4, 6, 9, 8, 7};

    for (int number : S)
        printf("%d ", number);

    printf("\n");

    mergeSort(S, [](int a, int b) -> bool {
        return a < b;
              });

    for (int number : S)
        printf("%d ", number);
}



template <typename T>
void mergeSort(list<T>& S, const function<bool(int, int)> f) {
    int listSize = S.size();
    if (listSize <= 1) return;

    list<T> S1, S2;

    typename list<T>::iterator p = S.begin();

    for (int i = 0; i < listSize / 2; i++) S1.push_back(*p++);
    for (int i = listSize / 2; i < listSize; i++) S2.push_back(*p++);
    S.clear();
    mergeSort(S1, f);
    mergeSort(S2, f);
    merge(S1, S2, S, f);
}

template <typename T>
void merge(list<T>& S1, list<T>& S2, list<T>& S, const function<bool(T,T)> f) {
    typename list<T>::iterator p1 = S1.begin();
    typename list<T>::iterator p2 = S2.begin();

    while (p1 != S1.end() && p2 != S2.end())
    {
        if (f(*p1, *p2))
            S.push_back(*p1++);
        else
            S.push_back(*p2++);
    }

    while (p1 != S1.end())
        S.push_back(*p1++);

    while (p2 != S2.end())
        S.push_back(*p2++);
}