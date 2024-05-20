#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#define N 5

using namespace std;

// Функция для нахождения сумм элементов каждого столбца матрицы
void findColumnSums(float matrix[N][N], float columnSums[N]) {
    for (int j = 0; j < N; j++) {
        columnSums[j] = 0;
        for (int i = 0; i < N; i++) {
            columnSums[j] += matrix[i][j];
        }
    }
}

int main() {
    float m[N][N];
    float columnSums[N];
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

    // Нахождение сумм элементов каждого столбца матрицы
    findColumnSums(m, columnSums);

    // Вывод сумм столбцов матрицы
    for (j = 0; j < N; j++) {
        cout << "Сумма элементов столбца " << j + 1 << ": " << columnSums[j] << endl;
    }

    return 0;
}
