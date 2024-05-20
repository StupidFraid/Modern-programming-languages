#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#define N 5

using namespace std;

// Функция для нахождения максимума в верхнетреугольной части матрицы
float findMaxUpperTriangle(float matrix[N][N]) {
    float maxVal = matrix[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) { // Обратите внимание на условие j >= i
            if (matrix[i][j] > maxVal) {
                maxVal = matrix[i][j];
            }
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

    // Нахождение и вывод максимума в верхнетреугольной части матрицы
    float maxVal = findMaxUpperTriangle(m);
    cout << "Максимум в верхнетреугольной части матрицы: " << maxVal << endl;

    return 0;
}
