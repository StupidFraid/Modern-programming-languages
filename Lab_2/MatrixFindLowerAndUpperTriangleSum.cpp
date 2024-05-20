#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#define N 5

using namespace std;

// Функция для нахождения суммы элементов нижнетреугольной части матрицы
float findLowerTriangleSum(float matrix[N][N]) {
    float sum = 0.0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) { // Условие j <= i
            sum += matrix[i][j];
        }
    }
    return sum;
}

// Функция для нахождения суммы элементов верхнетреугольной части матрицы
float findUpperTriangleSum(float matrix[N][N]) {
    float sum = 0.0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) { // Условие j >= i
            sum += matrix[i][j];
        }
    }
    return sum;
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

    // Нахождение суммы элементов нижнетреугольной части матрицы
    float lowerSum = findLowerTriangleSum(m);
    cout << "Сумма элементов нижнетреугольной части матрицы: " << lowerSum << endl;

    // Нахождение суммы элементов верхнетреугольной части матрицы
    float upperSum = findUpperTriangleSum(m);
    cout << "Сумма элементов верхнетреугольной части матрицы: " << upperSum << endl;

    return 0;
}
