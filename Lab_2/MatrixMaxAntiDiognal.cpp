#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#define N 5

using namespace std;

// Функция для нахождения максимум на второстепенной диагонали матрицы
float findMinAntiDiagonal(float matrix[N][N]) {
    float maxVal = matrix[0][N-1];
    for (int i = 1; i < N; i++) {
        if (matrix[i][N-1-i] > maxVal) {
            maxVal = matrix[i][N-1-i];
        }
    }
    return maxVal;
}

int main() {
    float m[N][N];
    int i, j;

    // Инициализация генератора случайных чисел
    srand(static_cast<unsigned int>(time(0)));

    // Заполнение матрицы случайными числами
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            m[i][j] = static_cast<float>(rand()) / RAND_MAX * 100; // Случайное число от 0 до 100
        }
    }

    // Вывод матрицы
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cout << setw(8) << setprecision(5) << m[i][j];
        }
        cout << endl;
    }

    // Нахождение и вывод максимум на второстепенной диагонали матрицы
    float maxVal = findMinAntiDiagonal(m);
    cout << "Максимум на второстепенной диагонали матрицы: " << maxVal << endl;

    return 0;
}
