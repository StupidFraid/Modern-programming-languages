#include <stdio.h>
#include <string.h>

void findString(FILE *in, const char *substring, FILE *out){
    char line[1000];
    int lineNumber, found = 0;

    // Найдем подстроку в каждой строке файла
    while (fgets(line, sizeof(line), in) != NULL)
    {
        lineNumber++;
        if (strstr(line, substring) != NULL){
            found = 1;
            fprintf(out, "Строка %d: %s", lineNumber, line);
        }
    }

    if (!found) {
        fprintf(out, "Строка \"%s\" не найдена в файле.\n", substring );
    }
    
}


int main(void){
    char ch, name[50], substring[100], outputFile[50];
    
    
    printf("Введите имя файла для просмотра: ");
    scanf("%s", name);

    FILE *in = fopen(name, "r");
    if (in == NULL){
        printf("Файл %s не открыт. Т.к. вероятно не существует. \n", name);
        return 1;
    }

    printf("Введите строку для поиска в файле: ");
    scanf("%s", substring);

    printf("Введите имя файла для записи результатов: ");
    scanf("%s", outputFile);

    FILE *out = fopen(outputFile, "w");
    if (out == NULL) {
        printf("Файл %s не может быть открыт для записи. \n", outputFile);
        fclose(in); //закрываем исходный файл
        return 1;
    }


    while ((ch = fgetc(in)) != EOF )
    {
        putchar(ch);
    }

    
    //Возвращаемся к началу входного файла
    rewind(in);

    //Найдем введеную строку и записываем результаты в входной файл
    findString(in, substring, out);

    printf("\nРезульат поиска записаны в файл %s\n", outputFile);

    //Возвращаемся к началу выходного файла
    rewind(out);
    //Закрываем исходный файл и выходной
    fclose(in);
    fclose(out);

    // Снова открываем файл для чтения
    out = fopen(outputFile, "r");
    if (out == NULL) {
        printf("Файл %s не может быть открыт для чтения.\n", outputFile);
        return 1;
    }

    printf("\n================================================= \n");
    printf("Содержимое файла с результатами: \n\n\n");
    while ((ch = fgetc(out)) != EOF){
        putchar(ch);
    }
    printf("\n");
    fclose(out);

    return 0;
}