#include <stdio.h>
#include <ctype.h>

void countCharacters(FILE *file, int *emptyCount, int *nonEmptyCount) {
    char ch;
    *emptyCount = *nonEmptyCount = 0;
    while ((ch = fgetc(file)) != EOF) {
        if (isspace(ch) || iscntrl(ch)) {
            (*emptyCount)++;
        } else {
            (*nonEmptyCount)++;
        }
    }
}

int main(void) {
    char name[50];
    int emptyCount, nonEmptyCount;

    printf("Введите имя файла для просмотра: ");
    scanf("%s", name);

    FILE *in = fopen(name, "r");
    if (in == NULL) {
        printf("Файл %s не открыт. Т.к. вероятно не существует.\n", name);
        return 1;
    }

    char ch;
    while ((ch = fgetc(in)) != EOF) {
        putchar(ch);
    }
    // Перемотка файла в начало для подсчета символов
    rewind(in);

    // Подсчет пустых и непустых символов
    countCharacters(in, &emptyCount, &nonEmptyCount);
    printf("Пустые символы: %d\n", emptyCount);
    printf("Непустые символы: %d\n", nonEmptyCount);

    fclose(in);
    return 0;
}
