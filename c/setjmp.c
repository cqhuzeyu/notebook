typedef void(*ptr_to_func)(int);
ptr_to_func signal(int, ptr_to_func);

#include <signal.h>
#include <setjmp.h>
#include <stdio.h>

jmp_buf jbuf;

void
termination_handler (int signum)
{
    printf("we are going to longjmp back to switch\n");
    longjmp(jbuf, 1);
}

int
main (int argc, char** argv)
{
    if (signal (SIGSEGV, termination_handler) == SIG_IGN)
        signal (SIGSEGV, SIG_IGN);
    char *p;
    //*p = 'b'; // pointers to literals are forbidden
    char* ss = "hello world"; // pointers to string literals are ok
    // char* suspicious = &a;
    char *suspicious = 0;
    char d = 'e';
    volatile char f = 'g';
    printf("before d = %c f = %c\n", d, f);
    char c;
    switch(setjmp(jbuf)) {
    case 0:
        d = 'f';
        f = 'h';
        printf("suspicious: %c\n", *suspicious);
        break;
    case 1:
        printf("after d = %c f = %c\n", d, f);
        printf("suspicious is indeed a bad pointer\n");
        break;
    default:
        printf("unexpected value returned by setjmp\n");
    }
    return 0;
}
