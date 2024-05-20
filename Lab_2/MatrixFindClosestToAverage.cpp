#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

#define N 5

using namespace std;

// Функция для нахождения среднеарифметического значения элементов матрицы
float findAverage(float matrix[N][N]) {
    float sum = 0.0;
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum += matrix[i][j];
            count++;
        }
    }
    return sum / count;
}

// Функция для нахождения элементов, наиболее близких по значению к среднеарифметическому
void findClosestToAverage(float matrix[N][N], float average) {
    float minDiff = fabs(matrix[0][0] - average);
    float closestElement = matrix[0][0];

    // Найти минимальную разницу и ближайший элемент
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            float diff = fabs(matrix[i][j] - average);
            if (diff < minDiff) {
                minDiff = diff;
                closestElement = matrix[i][j];
            }
        }
    }

    // Найти все элементы с минимальной разницей
    cout << "Элементы, наиболее близкие к среднеарифметическому значению: ";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (fabs(matrix[i][j] - average) == minDiff) {
                cout << matrix[i][j] << " ";
            }
        }
    }
    cout << endl;
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

    // Нахождение среднеарифметического значения элементов матрицы
    float average = findAverage(m);
    cout << "Среднеарифметическое значение элементов матрицы: " << average << endl;

    // Нахождение и вывод элементов, наиболее близких к среднеарифметическому значению
    findClosestToAverage(m, average);

    return 0;
}
