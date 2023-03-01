#include <stdio.h>
#include <string.h>

#define SIZE 100

void eng();
void rus();


int main() {
    char search[SIZE];
    // Считываем искомое слово или строку
    printf("Введите слово для перевода:\n");
    char symb;
    symb = getc(stdin);
    for (int i = 0; symb != '\n'; i++) {
        search[i] = symb;
        symb = getc(stdin);
    }
    // char *buffer = strtok(search, "\0");
    if ((*search > 64 && *search < 91) || (*search > 96 && *search < 123)) {
        eng(search);
    } else {
        printf("fail");
    }
    return 0;
}

void eng(char *search) {
    // printf("Here");
    // printf("%s", search);
    FILE *words=fopen("eng_rus/ENRUS.txt", "r");
    char row[SIZE]/*, s2[SIZE]*/, translate[SIZE];
    int err = 0, status = 0, flag = 0;
    while(fgets(row, SIZE, words)) {
        // for(int i = 0; search[i] != '\n'; s2[i] = search[i], i++);
        // printf("%s запрошенное слово ", search);
        // поиск совпадений (необязательно 1к1)
        if (strstr(row, search)) {
            // printf("strcmp = %d\n", strcmp(row, search));
            if (strcmp(row, search) == 13 && !status) {
                flag = 1;
                fgets(translate, SIZE, words);
                for(int i = 0; row[i] != '\n'; printf("%c", row[i]), i++);
                // printf("%s запрошенное слово ", row2);
                printf("\t--->  %s\n",  translate);
            } 
            // else if (!flag) {
            //     if (!status) printf("Пожалуйста, введите запрос более конкретно.\nВозможно, вы имели ввиду:\n");
            //     // fgets(translate, SIZE, words);
            //     printf("%s", row);
            //     status = 1;
            // }
            err = 1;
        }
    }
    if (!flag && err) {
        if(fseek(words, SEEK_CUR, SEEK_SET)) perror("Ошибка переноса курсора: ");
        while(fgets(row, SIZE, words)){
            if (strstr(row, search)) {
                if (!status) printf("Пожалуйста, введите запрос более конкретно.\nВозможно, вы имели ввиду:\n");
                // fgets(translate, SIZE, words);
                printf("%s", row);
                status = 1;
            }
        }
    }
    if (!err) printf("Введенное слово отсутствует в базе.\n");
    fclose(words);
}