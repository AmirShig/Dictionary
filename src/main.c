#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Dictionary {
    char words[20];
    char translate[20];
    int status;
};

int main() {
    struct Dictionary a = {'hello', 'привет', 1};
    printf("%s - %s; Слово изучено на %d%%", a.words, a.translate, a.status);


    // printf("Hello world!");
    return 0;
}