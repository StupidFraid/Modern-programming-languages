#include <iostream>
#include <cstdlib>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int arr[] = {2, 5, -8, 1, 4, -6, 3, -5, -9, 13, 0, 4, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Входной массив, не отсортированный: ";
    
    for (int i =0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    bubbleSort(arr, n);

    std::cout << "Сортировка массива (использование метода пузырька): ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
