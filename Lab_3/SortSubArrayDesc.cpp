#include <iostream>
#include <algorithm>

void sortSubarrayDesc(int arr[], int n, int N1, int N2) {
    std::sort(arr + N1, arr + N2 + 1, std::greater<int>());
}

int main() {
    int arr[] = {2, 5, -8, 1, 4, -6, 3, -5, -9, 13, 0, 4, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    int N1 = 3, N2 = 8; // примерные значения N1 и N2

    std::cout << "Входной массив, не отсортированный: ";
    
    for (int i =0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    sortSubarrayDesc(arr, n, N1, N2);

    std::cout << "Массив после сортировки подмассива по индексу от " << N1 << " до " << N2 << " в порядке убывания: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
