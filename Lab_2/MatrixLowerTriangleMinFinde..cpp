#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#define N 5

using namespace std;

// Функция для нахождения минимума в нижнетреугольной части матрицы
float findMimLowerTriangle(float matrix[N][N]) {
    float minValue = matrix[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) { // Обратите внимание на условие j <= i
            if (matrix[i][j] < minValue) {
                minValue = matrix[i][j];
            }
        }
    }
    return minValue;
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

    // Нахождение и вывод минимума в нижнетреугольной части матрицы
    float minValue = findMimLowerTriangle(m);
    cout << "Минимум в нижнетреугольной части матрицы: " << minValue << endl;

    return 0;
}
