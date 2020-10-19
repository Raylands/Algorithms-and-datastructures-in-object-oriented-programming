#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

void printMatrix(int**, const int&, const int&);
void fillMatrix(int**, const int&, const int&);

int main()
{
    int rows = 0, collums = 0;
    cout << " Input collums: ";
    cin >> collums;
    cout << " Input rows: ";
    cin >> rows;
    int** matrix = new int*[rows,collums];

    fillMatrix(matrix, rows, collums);
    printMatrix(matrix, rows, collums);

    delete[] matrix;
    return EXIT_SUCCESS;
}

void fillMatrix(int** matrix, const int& rows, const int& collums) {
    srand(time(0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < collums; j++)
        {
            matrix[i, j] = (int*)(rand() % 1001);
        }
    }
}

void printMatrix(int** matrix, const int& rows, const int& collums) {
    cout << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < collums; j++)
        {
            cout << " | " << setw(2) << (int)matrix[i, j];
        }
        cout << " | " << endl;
    }
    cout << endl;
}