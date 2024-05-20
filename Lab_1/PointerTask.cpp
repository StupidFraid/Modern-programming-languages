#include <iostream>
#include <cstdint>

#define PR(x) std::cout << "x=" << (uintptr_t)x << ", *x=" << *x << ", &x=" << (uintptr_t)&x << std::endl;

int main() {
    // Целочисленные значения
    int mas_int[] = {100, 200, 300};
    int *ptr1_int, *ptr2_int;
    
    ptr1_int = mas_int;
    ptr2_int = &mas_int[2];
    
    PR(ptr1_int);
    ptr1_int++;
    PR(ptr1_int);
    PR(ptr2_int);
    ++ptr2_int;
    
    std::cout << "ptr2_int - ptr1_int = " << ptr2_int - ptr1_int << std::endl;

    // Значения с плавающей точкой
    float mas_float[] = {1.1, 2.2, 3.3};
    float *ptr1_float, *ptr2_float;
    
    ptr1_float = mas_float;
    ptr2_float = &mas_float[2];
    
    PR(ptr1_float);
    ptr1_float++;
    PR(ptr1_float);
    PR(ptr2_float);
    ++ptr2_float;
    
    std::cout << "ptr2_float - ptr1_float = " << ptr2_float - ptr1_float << std::endl;

    // Символьные значения
    char mas_char[] = {'a', 'b', 'c'};
    char *ptr1_char, *ptr2_char;
    
    ptr1_char = mas_char;
    ptr2_char = &mas_char[2];
    
    PR(ptr1_char);
    ptr1_char++;
    PR(ptr1_char);
    PR(ptr2_char);
    ++ptr2_char;
    
    std::cout << "ptr2_char - ptr1_char = " << ptr2_char - ptr1_char << std::endl;

    return 0;
}
