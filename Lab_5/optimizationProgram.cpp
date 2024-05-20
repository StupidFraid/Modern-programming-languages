#include <stdio.h>
int main(void){
    char ch, name[50];
    
    printf("Введите имя файла для просмотра: ");
    scanf("%s", name);

    FILE *in = fopen(name, "r");
    if (in == NULL){
        printf("Файл %s не открыт. Т.к. вероятно не существует. \n", name);
        return 1;
    }
   while ((ch = fgetc(in)) != EOF) {
    putchar(ch);
    }
}