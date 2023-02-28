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
    char row[SIZE], translate[SIZE];
    int err = 0, status = 0, flag = 0;
    while(fgets(row, SIZE, words)) {
        // поиск совпадений (необязательно 1к1)
        if (strstr(row, search)) {
            // printf("search: %s\nres: %sСравнение строк: %d\n", search, row, strcmp(row, search));
            if (strcmp(row, search) == 13 && !status) {
                flag = 1;
                fgets(translate, SIZE, words);
                printf("\t%sПеревод: %s\n", row, translate);
            } else if (!flag) {
                if (!status) printf("Пожалуйста, введите запрос более конкретно.\nВозможно, вы имели ввиду:\n");
                // fgets(translate, SIZE, words);
                printf("%s", row);
                status = 1;
            }
            err = 1;
        }
    }
    if (!err) printf("Введенное слово отсутствует в базе.\n");
    fclose(words);
}