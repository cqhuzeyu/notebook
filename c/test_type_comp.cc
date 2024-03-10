#include <stdio.h>

void f(const char** p) {
    printf("ddd\n");
}

int main(int argc, char** argv) {
    char c = 'a';
    const char d = 'b';
    //char *pd = &d;
    //*pd = 'f';
    *(&d) = 'c';
    printf("%c\n", pd);
    char *p = &c;
    const char * q = &d;
    //p = q;
    q = p;
    //f(argv);
    return 0;
}
