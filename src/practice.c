#include <stdio.h>

struct Point {
    int x;
    int y;
};

struct Rect1 {
    struct Point lt;
    struct Point rb;
};
int main() {
    struct Rect1 a = {{7, 5}, {5, 3}};
    // a.lt.x = -7;
    // a.lt.y = 5;
    // a.rb.x = 5;
    // a.rb.y = -3;
    printf("%d %d %d %d\n", a.lt.x, a.lt.y, a.rb.x, a.rb.y);

    return 0;
}