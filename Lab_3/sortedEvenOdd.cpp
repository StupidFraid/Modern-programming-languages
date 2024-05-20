#include <iostream>
#include <vector>
#include <algorithm>

void sortEvenOdd(int arr[], int n) {
    std::vector<int> evens, odds;

    for (int i = 0; i < n; i++) {
        if (arr[i] % 2 == 0) {
            evens.push_back(arr[i]);
        } else {
            odds.push_back(arr[i]);
        }
    }

    std::sort(evens.begin(), evens.end());
    std::sort(odds.begin(), odds.end(), std::greater<int>());

    int index = 0;
    for (int i = 0; i < evens.size(); i++) {
        arr[index++] = evens[i];
    }
    for (int i = 0; i < odds.size(); i++) {
        arr[index++] = odds[i];
    }
}

int main() {
    int arr[] = {2, 5, -8, 1, 4, -6, 3, -5, -9, 13, 0, 4, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    std::cout << "Входной массив, не отсортированный: ";
    
    for (int i =0; i < n; i++)
        std::cout << arr[i] << " ";
    std::cout << "\n";

    sortEvenOdd(arr, n);

    std::cout << "Сортировка массива (Четный/Нечетный): ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
