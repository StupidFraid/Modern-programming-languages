#include <iostream>

int main(void)
{
    int mas[] = {2, 5, -8, 1, 4, -6, 3, -5, -9, 13, 0, 4, 9};
    // текущие индексы мин и макс элементов
    int imin, imax;
    // вычисление n - количества элементов
    int n = sizeof(mas) / sizeof(int);
    int i = 0, t;
    // установление начальных индексов для мин и макс
    imin = i;
    imax = i;
    for(i = 0; i < n; i++)
        std::cout << mas[i] << ' ';
    std::cout << std::endl;

    for(i = 0; i < n - 1; i++) // нахождение мин и макс
    {
        imin = i;
        for(int j = i + 1; j < n; j++)
            if(mas[j] < mas[imin]) imin = j;
        t = mas[i];
        mas[i] = mas[imin];
        mas[imin] = t;
    }
    for(i = 0; i < n; i++) // вывод на экран
        std::cout << mas[i] << ' ';
    std::cout << std::endl;
    return 0;
}
