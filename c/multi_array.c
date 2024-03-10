#include <stdio.h>

int apricot[2][3][5];

int main() {
    printf("%u, %u, %u\n", sizeof(apricot), sizeof(apricot[0]), sizeof(apricot[0][0]));
    int (*r)[5] = apricot[0];
    int *t = apricot[0][0];
    printf("%x %x\n", r, t);
    ++r;
    ++t;
    printf("%x %x\n", r, t);

}