#include <iostream>
using namespace std;

const int SIZE = 100;

bool isOrthonormal(float matrix[SIZE][SIZE], int n) {
    for (int i = 0; i < n; ++i) {
        float selfDot = 0;
        for (int j = 0; j < n; ++j)
            selfDot += matrix[i][j] * matrix[i][j];

        if (selfDot != 1.0f)
            return false;

        for (int k = i + 1; k < n; ++k) {
            float dot = 0;
            for (int j = 0; j < n; ++j)
                dot += matrix[i][j] * matrix[k][j];

            if (dot != 0.0f)
                return false;
        }
    }
    return true;
}

int main() {
    int n;
    float matrix[SIZE][SIZE];

    cout << "Введите размер квадратной матрицы: ";
    cin >> n;

    cout << "Введите элементы матрицы:\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> matrix[i][j];

    cout << "\nВведённая матрица:\n";
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }

    if (isOrthonormal(matrix, n))
        cout << "\nМатрица является ортонормированной.\n";
    else
        cout << "\nМатрица НЕ является ортонормированной.\n";

    return 0;
}
