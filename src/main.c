#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NMAX 100

typedef struct Dictionary {
    char word[256];
    char translate[256];
    int status;
} Dictionary;

Dictionary Base[NMAX];

int main() {
    Dictionary a;
    char buffer_word[256] = "hello";
    // scanf("%s", &buffer_word[256]);
    // fflush(stdin);
    // fgets(buffer_word, 256, stdin);
    strcpy(a.word, buffer_word);
    char buffer_translate[256] = "привет";
    // scanf("%s", &buffer_translate[256]);
    // fgets(buffer_translate, 256, stdin);
    strcpy(a.translate, buffer_translate);
    a.status = 0;
    printf("%s - %s;\nСлово изучено на %d%% из 100%%", a.word, a.translate, a.status);
    // printf("%s - %s; Слово изучено на %d%%", a.words, a.translate, a.status);

    return 0;
}