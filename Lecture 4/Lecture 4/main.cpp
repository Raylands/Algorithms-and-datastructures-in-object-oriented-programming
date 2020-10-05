#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;

void fillMatrix(int* matrix, const int& rows, const int& collums, const int& space);
void printMatrix(int* matrix, const int& rows, const int& collums, const int& space);
int* AddMatrix(int* matrix, int* matrix2, const int& rows, const int& collums, const int& space);

int main()
{
    int rows = 0, collums = 0, space = 0;
    cout << " Input collums: ";
    cin >> collums;
    cout << " Input rows: ";
    cin >> rows;
    cout << " Input space: ";
    cin >> space;
    int* matrix = new int [rows, collums, space];
    int* matrix2 = new int [rows, collums, space];

    fillMatrix(matrix, rows, collums, space);
    fillMatrix(matrix2, rows, collums, space);
    printMatrix(matrix, rows, collums, space);
    printMatrix(matrix2, rows, collums, space);
    int* matrix3 = AddMatrix(matrix, matrix2, rows, collums, space);
    printMatrix(matrix3, rows, collums, space);

    delete[] matrix;
    delete[] matrix2;
    delete[] matrix3;
    return EXIT_SUCCESS;
}

void fillMatrix(int* matrix, const int& rows, const int& collums, const int& space) {
    srand(time(0));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < collums; j++) {
            for (int k = 0; k < space; k++)
            {
                matrix[i, j, k] = (rand() % 1001);
            }
            
        }
    }
}

void printMatrix(int* matrix, const int& rows, const int& collums, const int& space) {
    cout << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < collums; j++) {
            for (int k = 0; k < space; k++)
            {
                cout << " | " << "Row: " << i+1 << " Collum: " << j+1 << " Space: " << k+1 << " : "<< setw(2) << (int)matrix[i, j, k];
            }
        }
        cout << " | " << endl;
    }
    cout << endl;
}

int* AddMatrix(int* matrix, int* matrix2, const int& rows, const int& collums, const int& space) {
    int* newMatrix = new int[rows, collums, space];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < collums; j++) {
            for (int k = 0; k < space; k++)
            {
                newMatrix[i, j, k] = matrix[i, j, k] + matrix2[i, j, k];
            }
        }
    }
    return newMatrix;
}