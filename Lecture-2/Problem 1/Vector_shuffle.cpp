#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

#define GENERIC true

#if GENERIC
    template <typename T>
    void shuffleVector(vector<T>& Vector, const int rotations);
    template <typename T>
    void printVector(vector<T>& Vector);
#else
    void shuffleVector(vector<int>& Vector, const int rotations);
    void printVector(vector<int>& Vector);
#endif // GENERIC



#if GENERIC
    template <typename T>
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

    template <typename T>
    void printVector(vector<T>& Vector) {
        for (int i = 0; i < Vector.size(); i++)
        {
            cout << Vector[i] << ' ';
        }
        cout << endl << endl;
    }
#else
    void shuffleVector(vector<int>& Vector, const int rotations = 1) {
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

    void printVector(vector<int>& Vector) {
        for (int i = 0; i < Vector.size(); i++)
        {
            cout << Vector[i] << ' ';
        }
        cout << endl << endl;
    }
#endif // GENERIC

int main()
{
    //vector<int> testVector{ 1, 2, 3, 4, 5, 6};
    vector<long> testVector{ 1, 2, 3, 4, 5, 6};

    shuffleVector(testVector,5);
}