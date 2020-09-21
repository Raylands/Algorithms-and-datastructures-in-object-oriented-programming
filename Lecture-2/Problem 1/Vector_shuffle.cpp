#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

template <class T>
void shuffleVector(vector<T>& Vector, const int rotations);
template <class T>
void printVector(vector<T>& Vector);

template <class T>
void shuffleVector(vector<T>& Vector, const int rotations = 1) {
    srand(time(0));
    for (size_t i = 0; i < rotations; i++)
    {
        for (int j = 0; j < Vector.size(); j++)
        {
            int random = rand() % Vector.size();

            swap(Vector[j], Vector[random]);
        }
        printVector(Vector);
    }
}

template <class T>
void printVector(vector<T>& Vector) {
    for (int i = 0; i < Vector.size(); i++)
    {
        cout << Vector[i] << ' ';
    }
    cout << endl << endl;
}

int main()
{
    vector<int> testVector{ 1, 2, 3, 4, 5, 6};

    shuffleVector(testVector,5);
}