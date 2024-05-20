#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#define N 5

using namespace std;

// Функция для нахождения максимального значения в каждой строке матрицы
void findrowsMax(float matrix[N][N], float rowsMax[N]) {
    for (int i = 0; i < N; i++) {
        rowsMax[i] = matrix[i][0];
        for (int j = 1; j < N; j++) {
            if (matrix[i][j] > rowsMax[i]) {
                rowsMax[i] = matrix[i][j];
            }
        }
    }
}

int main() {
    float m[N][N];
    float rowsMax[N];
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

    // Нахождение максимального значений в каждой строке матрицы
    findrowsMax(m, rowsMax);

    // Вывод максимального значений строк матрицы
    for (i = 0; i < N; i++) {
        cout << "Максимального значение в строке " << i + 1 << ": " << rowsMax[i] << endl;
    }

    return 0;
}
