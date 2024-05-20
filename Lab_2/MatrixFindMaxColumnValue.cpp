#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#define N 5

using namespace std;

// Функция для нахождения максимального значения в каждом столбце матрицы
void findColumnMax(float matrix[N][N], float columnMax[N]) {
    for (int j = 0; j < N; j++) {
        columnMax[j] = matrix[0][j];
        for (int i = 1; i < N; i++) {
            if (matrix[i][j] > columnMax[j]) {
                columnMax[j] = matrix[i][j];
            }
        }
    }
}

int main() {
    float m[N][N];
    float columnMax[N];
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

    // Нахождение максимальных значений в каждом столбце матрицы
    findColumnMax(m, columnMax);

    // Вывод максимальных значений столбцов матрицы
    for (j = 0; j < N; j++) {
        cout << "Максимальное значение в столбце " << j + 1 << ": " << columnMax[j] << endl;
    }

    return 0;
}
