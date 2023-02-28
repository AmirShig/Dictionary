#include <stdio.h>
#include <locale.h>
#include <wchar.h>

int main() {
    if (!setlocale (LC_ALL,".utf-8")) {
        perror("setlocale fail");
    }
    wchar_t c;
    for (c = 192; c <= 254; c++) {
        wprintf(L"%lc\n",c);
    }
    return 0;
} 



    // int c = 0, ch2 = 0;
    // c = getc(stdin);
    // ch2 = getchar();
    // printf("%d\n", c);
    // putchar(c);
    // if (ch2) putchar(ch2);