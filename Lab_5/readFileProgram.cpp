#include <stdio.h>

int main(void) {
    char name[50];
    FILE *in;

    printf("Введите имя файла для просмотра: ");
    scanf("%s", name);

    if ((in = fopen(name, "r")) == NULL) {
        printf("Файл %s не открыт\n", name);
    } else {
        char ch;
        while ((ch = fgetc(in)) != EOF) {
            putchar(ch);
        }
        fclose(in);
    }

    return 0;
}
