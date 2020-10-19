#include <iostream>
#include <chrono>
#include <iomanip>

using namespace std;

int*** createMatrix(const int& rows, const int& collums, const int& space);
void printMatrix(int*** matrix, const int& rows, const int& collums, const int& space);
int*** AddMatrix(int*** matrix, int*** matrix2, const int& rows, const int& collums, const int& space);

int main()
{
    int rows = 0, collums = 0, space = 0;
    cout << " Input collums: ";
    cin >> collums;
    cout << " Input rows: ";
    cin >> rows;
    cout << " Input space: ";
    cin >> space;

    int*** matrix = createMatrix(rows, collums, space);
    int*** matrix2 = createMatrix(rows, collums, space);

    printMatrix(matrix, rows, collums, space);
    printMatrix(matrix2, rows, collums, space);
    int*** matrix3 = AddMatrix(matrix, matrix2, rows, collums, space);
    printMatrix(matrix3, rows, collums, space);

    delete[] matrix;
    delete[] matrix2;
    delete[] matrix3;

    return EXIT_SUCCESS;
}

int*** createMatrix(const int& rows, const int& collums, const int& space) {
    srand(time(0));
    int*** matrix_new = new int** [rows];
    for (int i = 0; i < rows; i++)
    {
        matrix_new[i] = new int* [collums];
        for (int j = 0; j < collums; j++)
        {
            matrix_new[i][j] = new int[space];
            for (int k = 0; k < space; k++)
            {
                matrix_new[i][j][k] = rand() % 1001;
            }
        }
    }
    return matrix_new;
}

void printMatrix(int*** matrix, const int& rows, const int& collums, const int& space) {
    cout << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < collums; j++) {
            for (int k = 0; k < space; k++)
            {
                cout << " | " << "Row: " << i+1 << " Collum: " << j+1 << " Space: " << k+1 << " : " << setw(4) << matrix[i][j][k];
            }
        }
        cout << " | " << endl;
    }
    cout << endl;
}

int*** AddMatrix(int*** matrix, int*** matrix2, const int& rows, const int& collums, const int& space) {
    int*** newMatrix = createMatrix(rows, collums, space);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < collums; j++) {
            for (int k = 0; k < space; k++)
            {
                newMatrix[i][j][k] = matrix[i][j][k] + matrix2[i][j][k];
            }
        }
    }
    return newMatrix;
}