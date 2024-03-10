#include <stdio.h>
#include <stdlib.h>
int x = 0;
int y;

void f() {
    printf("calling f\n");
    int a = 2;
    int b = 3;
    printf("stack during calling f %p %p\n", &a, &b);
}

int main(int argc, char **argv)
{
    int a[3] = {0, 0, 0};
    int i;
    int j;
    int d[2] = {1, 1};
    int *h = malloc(sizeof(int) * 2);
    printf("sizeof pointer %ld\n", sizeof(h));
    printf("sizeof int %ld\n", sizeof(int));
    printf("array a %p %p %p %p\n", &a, &a[0], &a[1], &a[2]);
    printf("array d %p %p %p\n", &d, &d[0], &d[1]);
    printf("stack %p %p %p %p %p %p\n", &a, a, d, &i, &j, &h);
    printf("heap %p\n", &h[0]);
    printf("bss %p\n", &y);
    printf("data %p\n", &x);
    f();
    long daddr = &x;
    daddr -= sizeof(x);
    printf("text %s\n", (const char *)daddr);
    return 0;
}
