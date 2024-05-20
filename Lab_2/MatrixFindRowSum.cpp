#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#define N 5

using namespace std;

// Функция для нахождения сумм элементов каждой строки матрицы
void findRowSums(float matrix[N][N], float rowSums[N]) {
    for (int i = 0; i < N; i++) {
        rowSums[i] = 0;
        for (int j = 0; j < N; j++) {
            rowSums[i] += matrix[i][j];
        }
    }
}

int main() {
    float m[N][N];
    float rowSums[N];
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

    // Нахождение сумм элементов каждой строки матрицы
    findRowSums(m, rowSums);

    // Вывод сумм строк матрицы
    for (i = 0; i < N; i++) {
        cout << "Сумма элементов строки " << i + 1 << ": " << rowSums[i] << endl;
    }

    return 0;
}
