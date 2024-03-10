#include <stdio.h>

void f(char ca[]) {
    printf("%p, %p, %p %p\n", ca, &ca, &(ca[0]), &(ca[1]));
}

void g(char *pa) {
    printf("%p, %p %p %p\n", &pa, &(pa[0]), &(pa[1]), ++pa);
}

char ga[] = "abc";

int main() {
    f(ga);
    g(ga);
}