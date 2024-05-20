#include <iostream>
#include <cstring>
#include <cstdlib>

int lenghtStr1(const char*);
int lenghtStr2(const char*);
int lenghtStr3(const char*);
void copyStr(char*, const char*);
int comparyStr(const char*, const char*);
void concatStr(char*, const char*);



int main() {
    char *str1, *str2, *str3;
    str1 = (char*)calloc(100, sizeof(char));
    str2 = (char*)calloc(100, sizeof(char));
    str3 = (char*)calloc(100,  sizeof(char));

    strcpy(str1, "qwerty");
    strcpy(str2, "1234567890");

    std::cout << "Значение str1: " << str1 << std::endl;
    std::cout << "Значение str2: " << str2 << std::endl;
    std::cout << "Значение str3: " << str3 << std::endl;

    std::cout << "____________________________ " << std::endl;
    std::cout <<  std::endl;
 
    std::cout << "Функция lenghtStr1(). Длина str1=" << lenghtStr1(str1) << ", str2=" << lenghtStr1(str2) << std::endl;
    std::cout << "Функция lenghtStr2(). Длина str1=" << lenghtStr2(str1) << ", str2=" << lenghtStr2(str2) << std::endl;
    std::cout << "Функция lenghtStr3(). Длина str1=" << lenghtStr3(str1) << ", str2=" << lenghtStr3(str2) << std::endl;

    std::cout <<  std::endl;

    copyStr(str3, str1);
    std::cout << "Копирование str1 в str3. str3 = " << str3 << std::endl;

    std::cout <<  std::endl;

    int result = comparyStr(str1, str2);
    std::cout << "Если строки равны выводит 0, иначе отрицательое или положительное число" << std::endl;
    std::cout << "Результат сравнения str1 и str2: " << result << std::endl;
    result = comparyStr(str1, str3);
    std::cout << "Результат сравнения str1 и str3: " << result << std::endl;

    std::cout <<  std::endl;

    concatStr(str1, str2);
    std::cout << "Результат конкатенации строк str1 и str2: " << str1 << std::endl;

    return 0;
}

// Реализация функций
int lenghtStr1(const char* str) {
    int length = 0;
    while (*str++) length++;
    return length;
}

int lenghtStr2(const char* str) {
    int length = 0;
    for (; str[length] != '\0'; length++);
    return length;
}

int lenghtStr3(const char* str) {
    const char* s = str;
    while (*s) ++s;
    return s - str;
}

void copyStr(char* dest, const char* src) {
    while ((*dest++ = *src++));
}

int comparyStr(const char* str1, const char* str2) {
    while (*str1 && (*str1 == *str2)) {
        str1++;
        str2++;
    }
    return *(unsigned char*)str1 - *(unsigned char*)str2;
}

void concatStr(char* dest, const char* src) {
    while (*dest) dest++;
    while ((*dest++ = *src++));
}
